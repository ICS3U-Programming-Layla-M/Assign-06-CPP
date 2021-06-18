// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: June 16, 2021
// This program asks the user to create a list, state what math operator to use
// on the list, and displays the new list

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <sstream>

std::list<float> mathList(std::list<float> listResult, std::string operation,
                          float secondNum, int secondNumMod) {
    // performs a math operation on a list and returns an empty list if there
    // is a ZeroDivisionError
    std::list<float> newList;
    for (float number : listResult) {
        if (operation == "+") {
            newList.push_back(number + secondNum);
        } else if (operation == "-") {
            newList.push_back(number - secondNum);
        } else if (operation == "*") {
            newList.push_back(number * secondNum);
        } else if (operation == "/") {
            if (secondNum == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            } else {
                newList.push_back(number / secondNum);
            }
        } else if (operation == "%") {
            if (secondNumMod == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            } else {
                int numberInt = static_cast<int>(number);
                float mod = numberInt % secondNumMod;
                newList.push_back(mod);
            }
        }
    }
    return newList;
}

int main() {
    // declare local variables
    std::string numberElements, userOper, userSecondNum;
    std::list<float> numberList;
    std::list<float> userListResult;
    std::list<int> numberListMod;
    std::vector<std::string> result;
    float elementFloat, userSecondNumFloat;
    int userSecondNumInt, numberIntList;

    // greet user
    std::cout << "This program does a math operation on a list of numbers ";
    std::cout << "to create a new list.\n";

    while (numberList.size() == 0) {
        // ask user to enter each number of the list
        std::cout << "Enter a list of numbers (i.e. 1 2 3 4 5): ";
        getline(std::cin, numberElements);

        // each string separated by a space is added to a list
        // got this from:
// https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++
        std::istringstream iss(numberElements);
        for (std::string numberElements; iss >> numberElements; ) {
            result.push_back(numberElements);
        }

        for (std::string element : result) {
            try {
                // converts each element from string to float and adds it to
                // a new list
                elementFloat = std::stof(element);
                numberList.push_back(elementFloat);
            } catch (std::invalid_argument) {
                // removes elements that aren't numbers
                std::cout << element << " is not a number so it will be ";
                std::cout << "removed.\n";
            }
        }

        if (numberList.size() == 0) {
            // asks the user to reenter numbers in the list if the
            // list is empty
            std::cout << "The list is empty, try again.\n";
        }
    }

    std::cout << "\n";
    while (true) {
        // asks the user what kind of operation they want to perform
        // on the list
        std::cout << "Enter what kind of operation you want to perform on ";
        std::cout << "the list (i.e. +, -, *, /, %): ";
        std::cin >> userOper;

        if (userOper == "+") {
            // check if it's an addition
            std::cout << "\n";
            while (true) {
                // get the second number of the operation
                std::cout << "What number do you want to add to each number? ";
                std::cin >> userSecondNum;

                try {
                    // convert from string to float
                    userSecondNumFloat = stof(userSecondNum);
                    break;
                } catch (std::invalid_argument) {
                    // error message if the input is not a number
                    std::cout << userSecondNum << " is not a valid number, ";
                    std::cout << "try again.\n";
                }
            } break;
        } else if (userOper == "-") {
            // check if it's a subtraction
            std::cout << "\n";
            while (true) {
                // get the second number of the operation
                std::cout << "What number do you want to subtract to each ";
                std::cout << "number? ";
                std::cin >> userSecondNum;

                try {
                    // convert from string to float
                    userSecondNumFloat = stof(userSecondNum);
                    break;
                } catch (std::invalid_argument) {
                    // error message if the input is not a number
                    std::cout << userSecondNum << " is not a valid number, ";
                    std::cout << "try again.\n";
                }
            } break;
        } else if (userOper == "*") {
            // check if it's a subtraction
            std::cout << "\n";
            while (true) {
                // get the second number of the operation
                std::cout << "What number do you want to multiply each ";
                std::cout << "number by? ";
                std::cin >> userSecondNum;

                try {
                    // convert from string to float
                    userSecondNumFloat = stof(userSecondNum);
                    break;
                } catch (std::invalid_argument) {
                    // error message if the input is not a number
                    std::cout << userSecondNum << " is not a valid number, ";
                    std::cout << "try again.\n";
                }
            } break;
        } else if (userOper == "/") {
            // check if it's a division
            std::cout << "\n";
            while (true) {
                // get the second number of the operation
                std::cout << "What number do you want to divide each ";
                std::cout << "number by? ";
                std::cin >> userSecondNum;

                try {
                    // convert from string to float
                    userSecondNumFloat = stof(userSecondNum);
                    break;
                } catch (std::invalid_argument) {
                    // error message if the input is not a number
                    std::cout << userSecondNum << " is not a valid number, ";
                    std::cout << "try again.\n";
                }
            } break;
        } else if (userOper == "%") {
            // check if the user wants the remainder
            std::cout << "\n";
            for (float number : numberList) {
                numberIntList = static_cast<int>(number);
                numberListMod.push_back(numberIntList);
            }

            while (true) {
                std::cout << "Notice: if any number in the list is a decimal";
                std::cout << ", the decimal will be dropped for this ";
                std::cout << "calculation.\n";
                std::cout << "Here is the updated list: ";

                // create and display list of only integers if the user is
                // doing a mod operation
                auto iter5 = numberListMod.begin();
                auto iterEnd5 = (++numberListMod.rbegin()).base();
                std::cout << "[";
                while (iter5 != numberListMod.end()) {
                    if (iter5 == iterEnd5) {
                        int numberInt = *iter5;
                        std::cout << numberInt << "]\n";
                        break;
                    } else {
                        int numberInt = *iter5;
                        std::cout << numberInt << ", ";
                        iter5++;
                    }
                }
                std::cout << "\n";

                while (true) {
                    // get the second number of the operation
                    std::cout << "What number do you want to divide each ";
                    std::cout << "number by? ";
                    std::cin >> userSecondNum;

                    try {
                        // convert from string to float
                        userSecondNumFloat = stof(userSecondNum);
                        // convert from string to int
                        userSecondNumInt = stoi(userSecondNum);

                        if (userSecondNumInt == userSecondNumFloat) {
                            // check if the second number was an integer
                            break;
                        } else {
                            // error message if the second number is a decimal
                            std::cout << userSecondNum << " is not a valid ";
                            std::cout << "number, try again.\n";
                        }
                    } catch (std::invalid_argument) {
                        // error message if the input is not a number
                        std::cout << userSecondNum << " is not a valid ";
                        std::cout << "number, try again.\n";
                    }
                } break;
            } break;
        } else {
            // error message if the operator is not a valid one
            std::cout << userOper << " is not a valid operator, try again.\n";
        }
    }

    try {
        if (userOper == "%") {
            // call mathList function if the user is using %
            std::cout << "\n";
            userListResult = mathList(numberList, userOper,
                                      userSecondNumFloat = 0, userSecondNumInt);

            // create new list of just integers for mod
            std::list<int> userListMod;
            for (float number : userListResult) {
                int numberInt = static_cast<int>(number);
                userListMod.push_back(numberInt);
            }

            // display the first list, operator, second number and the new list
            auto iter = numberListMod.begin();
            auto iterEnd = (++numberListMod.rbegin()).base();
            std::cout << "[";
            while (iter != numberListMod.end()) {
                if (iter == iterEnd) {
                    float number = *iter;
                    std::cout << number << "]";
                    break;
                } else {
                    float number = *iter;
                    std::cout << number << ", ";
                    iter++;
                }
            }
            std::cout << " " << userOper << " " << userSecondNumInt << " = ";

            auto iter2 = userListMod.begin();
            auto iterEnd2 = (++userListMod.rbegin()).base();
            std::cout << "[";
            while (iter2 != userListMod.end()) {
                if (iter2 == iterEnd2) {
                    int number = *iter2;
                    std::cout << number << "]";
                    break;
                } else {
                    int number = *iter2;
                    std::cout << number << ", ";
                    iter2++;
                }
            }
        } else {
            // call math_list function if the user is using a different
            // operator
            std::cout << "\n";
            userListResult = mathList(numberList, userOper, userSecondNumFloat,
                                      userSecondNumInt = 0);
            // display the first list, operator, second number and the new list
            auto iter3 = numberList.begin();
            auto iterEnd3 = (++numberList.rbegin()).base();
            std::cout << "[";
            while (iter3 != numberList.end()) {
                if (iter3 == iterEnd3) {
                    float number = *iter3;
                    std::cout << number << "]";
                    break;
                } else {
                    float number = *iter3;
                    std::cout << number << ", ";
                    iter3++;
                }
            }
            std::cout << " " << userOper << " " << userSecondNumFloat << " = ";

            auto iter4 = userListResult.begin();
            auto iterEnd4 = (++userListResult.rbegin()).base();
            std::cout << "[";
            while (iter4 != userListResult.end()) {
                if (iter4 == iterEnd4) {
                    float number = *iter4;
                    std::cout << number << "]";
                    break;
                } else {
                    float number = *iter4;
                    std::cout << number << ", ";
                    iter4++;
                }
            }
        }
    } catch (std::runtime_error& e) {
        // catches runtime error if the second number for the / or % is zero
        std::cout << ""
                  << e.what();
    }
}
