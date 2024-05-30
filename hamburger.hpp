#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct HamburgerIngredient { virtual ~HamburgerIngredient() = default; virtual std::string Name() const = 0; };

struct Bread : public HamburgerIngredient { std::string Name() const override { return "Bread"; } };
struct Patty : public HamburgerIngredient { std::string Name() const override { return "Patty"; } };
struct Cheese : public HamburgerIngredient { std::string Name() const override { return "Cheese"; } };
struct Tomato : public HamburgerIngredient { std::string Name() const override { return "Tomato"; } };
struct Lettuce : public HamburgerIngredient { std::string Name() const override { return "Lettuce"; } };
struct Sauce : public HamburgerIngredient { std::string Name() const override { return "Sauce"; } };

struct LightBread : public Bread { std::string Name() const override { return "LightBread"; } };
struct SaltyBread : public Bread { std::string Name() const override { return "SaltyBread"; } };

struct BeefPatty : public Patty { std::string Name() const override { return "BeefPatty"; } };
struct PorkPatty : public Patty { std::string Name() const override { return "PorkPatty"; } };

struct MozzarellaCheese : public Cheese { std::string Name() const override { return "MozzarellaCheese"; } };
struct CheddarCheese : public Cheese { std::string Name() const override { return "CheddarCheese"; } };

struct GarlicSauce : public Sauce { std::string Name() const override { return "GarlicSauce"; } };
struct MustardSauce : public Sauce { std::string Name() const override { return "MustardSauce"; } };

class Hamburger final
{
public:
    explicit Hamburger(std::vector<std::unique_ptr<HamburgerIngredient>>&& ingredientList)
        : ingredientList_(std::move(ingredientList))
    {}

    void Print() const
    {
        std::cout << "----------" << std::endl;
        for (auto const& ingredient : ingredientList_)
            std::cout << ingredient->Name() << std::endl;
        std::cout << "----------" << std::endl;
    }

private:
    std::vector<std::unique_ptr<HamburgerIngredient>> ingredientList_;
};

class HamburgerBuilder
{
public:
    virtual ~HamburgerBuilder() = default;

    virtual void Initialize() = 0;

    virtual void BuildBread() = 0;
    virtual void BuildPatty() = 0;
    virtual void BuildCheese() = 0;
    virtual void BuildTomato() = 0;
    virtual void BuildLettuce() = 0;
    virtual void BuildSauce() = 0;

    virtual Hamburger GetHamburger() = 0;
};

class BeefHamburgerBuilder : public HamburgerBuilder
{
public:
    void Initialize() override { ingredientList_.clear(); }

    void BuildBread() override { ingredientList_.push_back(std::make_unique<LightBread>()); }
    void BuildPatty() override { ingredientList_.push_back(std::make_unique<BeefPatty>()); }
    void BuildCheese() override { ingredientList_.push_back(std::make_unique<MozzarellaCheese>()); }
    void BuildTomato() override { ingredientList_.push_back(std::make_unique<Tomato>()); }
    void BuildLettuce() override { ingredientList_.push_back(std::make_unique<Lettuce>()); }
    void BuildSauce() override { ingredientList_.push_back(std::make_unique<GarlicSauce>()); }

    Hamburger GetHamburger() override 
    { 
        Hamburger hamburger(std::move(ingredientList_));
        return hamburger;
    };

private:
    std::vector<std::unique_ptr<HamburgerIngredient>> ingredientList_;
};

class PorkHamburgerBuilder : public HamburgerBuilder
{
public:
    void Initialize() override { ingredientList_.clear(); }

    void BuildBread() override { ingredientList_.push_back(std::make_unique<SaltyBread>()); }
    void BuildPatty() override { ingredientList_.push_back(std::make_unique<PorkPatty>()); }
    void BuildCheese() override { ingredientList_.push_back(std::make_unique<CheddarCheese>()); }
    void BuildTomato() override { ingredientList_.push_back(std::make_unique<Tomato>()); }
    void BuildLettuce() override { ingredientList_.push_back(std::make_unique<Lettuce>()); }
    void BuildSauce() override { ingredientList_.push_back(std::make_unique<MustardSauce>()); }

    Hamburger GetHamburger() override
    {
        Hamburger hamburger(std::move(ingredientList_));
        return hamburger;
    };

private:
    std::vector<std::unique_ptr<HamburgerIngredient>> ingredientList_;
};

class HamburgerHouse final
{
public:
    explicit HamburgerHouse(std::unique_ptr<HamburgerBuilder>&& builder)
        : builder_(std::move(builder))
    {}

    void ChangeBuilder(std::unique_ptr<HamburgerBuilder>&& builder) { builder_ = std::move(builder); }

    Hamburger MakeCheeseBurger()
    {
        builder_->Initialize();

        builder_->BuildBread();
        builder_->BuildLettuce();
        builder_->BuildSauce();
        builder_->BuildPatty();
        builder_->BuildCheese();
        builder_->BuildBread();

        return builder_->GetHamburger();
    }

    Hamburger MakeJumboBurger()
    {
        builder_->Initialize();

        builder_->BuildBread();
        builder_->BuildLettuce();
        builder_->BuildSauce();
        builder_->BuildPatty();
        builder_->BuildCheese();
        builder_->BuildBread();
        builder_->BuildLettuce();
        builder_->BuildSauce();
        builder_->BuildPatty();
        builder_->BuildCheese();
        builder_->BuildBread();

        return builder_->GetHamburger();
    }

private:
    std::unique_ptr<HamburgerBuilder> builder_;
};
