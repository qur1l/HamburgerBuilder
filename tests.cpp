#include <gtest/gtest.h>
#include "hamburger.h"

class HamburgerBuilderTest : public ::testing::Test {
protected:
    void SetUp() override {
        builder = std::make_unique<HamburgerBuilder>();
    }

    std::unique_ptr<HamburgerBuilder> builder;
};

TEST_F(HamburgerBuilderTest, BuildSimpleHamburger) {
    auto burger = builder->BuildHamburger();
    EXPECT_EQ(burger.GetBuns(), 2);
    EXPECT_EQ(burger.GetPatties(), 1);
    EXPECT_EQ(burger.GetCheese(), 1);
    EXPECT_EQ(burger.GetVegetables(), 2);
    EXPECT_EQ(burger.GetSauces(), 1);
}

TEST_F(HamburgerBuilderTest, BuildDeluxeHamburger) {
    builder->AddExtraBuns()
           ->AddExtraPatties()
           ->AddExtraCheese()
           ->AddExtraVegetables()
           ->AddExtraSauces();
    auto burger = builder->BuildHamburger();
    EXPECT_EQ(burger.GetBuns(), 3);
    EXPECT_EQ(burger.GetPatties(), 2);
    EXPECT_EQ(burger.GetCheese(), 2);
    EXPECT_EQ(burger.GetVegetables(), 3);
    EXPECT_EQ(burger.GetSauces(), 2);
}

TEST_F(HamburgerBuilderTest, BuildCustomHamburger) {
    builder->AddBuns(4)
           ->AddPatties(3)
           ->AddCheese(2)
           ->AddVegetables(4)
           ->AddSauces(3);
    auto burger = builder->BuildHamburger();
    EXPECT_EQ(burger.GetBuns(), 4);
    EXPECT_EQ(burger.GetPatties(), 3);
    EXPECT_EQ(burger.GetCheese(), 2);
    EXPECT_EQ(burger.GetVegetables(), 4);
    EXPECT_EQ(burger.GetSauces(), 3);
}
