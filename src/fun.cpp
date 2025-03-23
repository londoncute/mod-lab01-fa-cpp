// Copyright 2022 UNN-IASR

#include "fun.h"
#include <cctype>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (isdigit(*str)) {
                hasDigit = true;
            }
        } else {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
        }
        str++;
    }

    if (inWord && !hasDigit) {
        count++;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool valid = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!inWord) {
                inWord = true;
                valid = isupper(*str);
            } else {
                if (!islower(*str)) {
                    valid = false;
                }
            }
        } else {
            if (inWord && valid) {
                count++;
            }
            inWord = false;
        }
        str++;
    }

    if (inWord && valid) {
        count++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    unsigned int wordLength = 0;
    bool inWord = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!inWord) {
                inWord = true;
                wordLength = 0;
            }
            wordLength++;
        } else {
            if (inWord) {
                totalLength += wordLength;
                wordCount++;
            }
            inWord = false;
        }
        str++;
    }

    if (inWord) {
        totalLength += wordLength;
        wordCount++;
    }
    double midLength = static_cast<double>((totalLength) / wordCount);
    unsigned int ansver = static_cast<unsigned int>(std::round(midLength));
    return wordCount == 0 ? 0 :ansver;
}
