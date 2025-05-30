#include "my_string2.h"
#include <sstream>

// Функція рахує кількість слів у рядку (через stringstream)
int count_words(const std::string& s) {
    std::istringstream iss(s);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;
}
