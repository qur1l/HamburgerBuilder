#include <gtest/gtest.h>
#include "hamburger.hpp"

// Test case for Hamburger class
TEST(HamburgerTest, HamburgerPrintTest) {
    std::vector<std::unique_ptr<HamburgerIngredient>> ingredients;
    ingredients.push_back(std::make_unique<Bread>());
    ingredients.push_back(std::make_unique<Patty>());
    ingredients.push_back(std::make_unique<Cheese>());
    ingredients.push_back(std::make_unique<Tomato>());
    ingredients.push_back(std::make_unique<Lettuce>());
    ingredients.push_back(std::make_unique<Sauce>());

    Hamburger hamburger(std::move(ingredients));

    testing::internal::CaptureStdout();
    hamburger.Print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "----------\nBread\nPatty\nCheese\nTomato\nLettuce\nSauce\n----------\n");
}

// Test case for Hamburger class with no ingredients
TEST(HamburgerTest, HamburgerNoIngredientsTest) {
    std::vector<std::unique_ptr<HamburgerIngredient>> ingredients;

    Hamburger hamburger(std::move(ingredients));

    testing::internal::CaptureStdout();
    hamburger.Print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "----------\n----------\n");
}

// Test case for HamburgerBuilder class
TEST(HamburgerBuilderTest, HamburgerBuilderTest) {
    BeefHamburgerBuilder builder;
    builder.Initialize();
    builder.BuildBread();
    builder.BuildPatty();
    builder.BuildCheese();
    builder.BuildTomato();
    builder.BuildLettuce();
    builder.BuildSauce();

    Hamburger hamburger = builder.GetHamburger();

    testing::internal::CaptureStdout();
    hamburger.Print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "----------\nLightBread\nBeefPatty\nMozzarellaCheese\nTomato\nLettuce\nGarlicSauce\n----------\n");
}

