// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

// Функция для тестирования faStr1
void test_faStr1() {
    std::cout << "Testing faStr1..." << std::endl;
    struct TestCase {
        const char* input;
        unsigned int expected;
    } testCases[] = {
        {"Hello world 123 abc", 2},  // "Hello", "world"
        {"123 456 789", 0},         // Нет слов без цифр
        {"one two three", 3},       // Все слова без цифр
        {"", 0},                    // Пустая строка
        {"   ", 0},                  // Только пробелы
        {"text1 text2 text", 1}     // Только одно слово без цифр
    };

    for (const auto& test : testCases) {
        unsigned int result = faStr1(test.input);
        std::cout << "Input: \"" << test.input << "\" | Expected: " 
                  << test.expected << " | Got: " << result 
                  << (result == test.expected ? " ✅" : " ❌") << std::endl;
    }
}

// Функция для тестирования faStr2
void test_faStr2() {
    std::cout << "\nTesting faStr2..." << std::endl;
    struct TestCase {
        const char* input;
        unsigned int expected;
    } testCases[] = {
        {"Hello world Apple banana", 2}, // "Hello", "Apple"
        {"Zebra Cat Dog", 3},            // Все слова подходят
        {"HELLO world aPPle", 0},        // Нет подходящих слов
        {"Aaa Bbb Ccc Ddd", 4},          // Все слова подходят
        {"apple Banana cherry", 1}       // Только "Banana"
    };

    for (const auto& test : testCases) {
        unsigned int result = faStr2(test.input);
        std::cout << "Input: \"" << test.input << "\" | Expected: " 
                  << test.expected << " | Got: " << result 
                  << (result == test.expected ? " ✅" : " ❌") << std::endl;
    }
}

// Функция для тестирования faStr3
void test_faStr3() {
    std::cout << "\nTesting faStr3..." << std::endl;
    struct TestCase {
        const char* input;
        unsigned int expected;
    } testCases[] = {
        {"Hello world this is test", 4},  // (5+5+4+2+4) / 5 = 4
        {"One two three four", 4},       // (3+3+5+4) / 4 = 4
        {"   ", 0},                      // Нет слов
        {"longest shortest tiny", 7},    // (7+8+4) / 3 = 7
        {"A bb ccc dddd eeeee", 3}       // (1+2+3+4+5) / 5 = 3
    };

    for (const auto& test : testCases) {
        unsigned int result = faStr3(test.input);
        std::cout << "Input: \"" << test.input << "\" | Expected: " 
                  << test.expected << " | Got: " << result 
                  << (result == test.expected ? " ✅" : " ❌") << std::endl;
    }
}

int main() {
    test_faStr1();
    test_faStr2();
    test_faStr3();
    return 0;
}
