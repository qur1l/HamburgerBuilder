#include <gtest/gtest.h>
#include "hamburger.cpp"

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

// Add more test cases as needed

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
