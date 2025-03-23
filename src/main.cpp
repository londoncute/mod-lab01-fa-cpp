// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "../include/fun.h"

// Тест для faStr1 (слова без цифр)
TEST(FaStr1Test, BasicCases) {
    EXPECT_EQ(faStr1("Hello world 123 abc"), 2); // "Hello", "world"
    EXPECT_EQ(faStr1("123 456 789"), 0); // Нет слов без цифр
    EXPECT_EQ(faStr1("one two three"), 3); // Все слова без цифр
}

// Тест для faStr2 (слова с заглавной буквы и только строчными буквами)
TEST(FaStr2Test, BasicCases) {
    EXPECT_EQ(faStr2("Hello world Apple banana"), 2); // "Hello", "Apple"
    EXPECT_EQ(faStr2("Zebra Cat Dog"), 3); // Все слова подходят
    EXPECT_EQ(faStr2("HELLO world aPPle"), 0); // Нет подходящих слов
}

// Тест для faStr3 (средняя длина слова)
TEST(FaStr3Test, BasicCases) {
    EXPECT_EQ(faStr3("Hello world this is test"), 4); // (5+5+4+2+4) / 5 = 4
    EXPECT_EQ(faStr3("One two three four"), 4); // (3+3+5+4) / 4 = 4
    EXPECT_EQ(faStr3("   "), 0); // Нет слов
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
