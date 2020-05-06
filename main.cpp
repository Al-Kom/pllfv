// Laboratory work 1 on the discipline LOIS
// Completed by student of group 721702 BSUIR Komar Alexander Nazarovich
// Console UI for testing propositional logic language formula verifier
// Version 2. Tidy updates
//
// https://www.opennet.ru/base/dev/pcre_cpp.txt.html
// https://eax.me/libpcre/
// https://eax.me/cmake/
//
#include <iostream>
#include "pllfv.h"

const int MAX_LENGTH = 10;
const int VOCABULARY_LENGTH = 35;
const std::string VOCABULARY[] = {"1", "0", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                                                    "L", "M", "N",
                                                    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "!",
                                                    "&", "|", "~",
                                                    "(", ")", "->"};


void check();

void test();

std::string generateTest();

int main() {
    for (;;) {
        std::cout << "Enter 1 to check formula, 2 to test yourself, else to exit\n";
        int choice = 0;
        std::cin >> choice;
        switch (choice) {
            case 1:
                check();
                continue;
            case 2:
                test();
                continue;
            default:
                std::cout << "exit!\n";
        }
        break;
    }
    return 0;
}

void check() {
    std::cout << "Enter a string to check\n";
    std::string str;
    std::cin >> str;
    bool isFormula = matchRegexp(DEFAULT_FORMULA_PATTERN, str.c_str(), str.length());
    if (isFormula)
        std::cout << "String " + str + " is a formula\n";
    else
        std::cout << "String " + str + " is not a formula\n";
}

void test() {
    std::string test = generateTest();
    std::cout << "Is it a formula: " + test + "? (Enter 1 if yes, else if not)\n";
    int answer;
    std::cin >> answer;
    bool isFormula = matchRegexp(DEFAULT_FORMULA_PATTERN, test.c_str(), test.length());
    if ((answer == 1 && isFormula) || (answer != 1 && !isFormula))
        std::cout << "Right!\n";
    else
        std::cout << "Wrong!\n";
}

std::string generateTest() {
    int testLength = (int) rand() % MAX_LENGTH;
    std::string test;
    int randomSignId = 0;
    for (int i = 0; i < testLength; i++) {
        randomSignId = rand() % VOCABULARY_LENGTH;
        test += VOCABULARY[randomSignId];
    }
    return test;
}
