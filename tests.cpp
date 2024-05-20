#include <gtest/gtest.h>
#include "hamburger.cpp"

TEST(HamburgerBuilderTest, InitialState) {
    HamburgerBuilder vm;
    EXPECT_EQ(vm.GetCpuCount(), 1);
    EXPECT_EQ(vm.GetRamSize(), 500);
}

TEST(HamburgerBuilderTest, ChangeCpuCount) {
    HamburgerBuilder vm;
    vm.ChangeCpuCount(4);
    EXPECT_EQ(vm.GetCpuCount(), 4);
}

TEST(HamburgerBuilderTest, ChangeRamSize) {
    HamburgerBuilder vm;
    vm.ChangeRamSize(2000);
    EXPECT_EQ(vm.GetRamSize(), 2000);
}

TEST(HamburgerBuilderTest, ResetToSnapshot) {
    HamburgerBuilder vm;
    auto snapshot = vm.TakeSnapshot();
    vm.ChangeCpuCount(4);
    vm.ChangeRamSize(2000);
    vm.ResetToSnapshot(snapshot);
    EXPECT_EQ(vm.GetCpuCount(), 1);
    EXPECT_EQ(vm.GetRamSize(), 500);
}
