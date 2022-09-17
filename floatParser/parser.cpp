#include <iostream>
#include "VectorContainer.hpp"
#include <cmath>
#include <cassert>

float ParseFloating(GLVM::Core::TCVectorContainer<char> _word) {
    GLVM::Core::TCVectorContainer<int> baseContainer;

    for (int i = 0; i < _word.GetSize(); ++i)
        baseContainer.Push(_word[i] - 48);
        
    int integerPart = 0;
    float floatingPart = 0;
    GLVM::Core::TCVectorContainer<int> integerPartContainer;
    GLVM::Core::TCVectorContainer<int> floatingPartContainer;
    bool dotFlag = false;
    bool negateFlag = false;
    unsigned int baseContainerSize = baseContainer.GetSize();

    if (baseContainer[0] == -3)
        negateFlag = true;

    for (int i = 0; i < baseContainerSize; ++i) {
        if (negateFlag && i == 0)
            continue;
        else if (baseContainer[i] == -5 && i == 0)
            continue;
        else if (baseContainer[i] == -2) {
            dotFlag = true;
            continue;
        }

        if (baseContainer[i] >= 0 && baseContainer[i] <= 9) {
            if (dotFlag)
                floatingPartContainer.Push(baseContainer[i]);
            else
                integerPartContainer.Push(baseContainer[i]);
        } else {
            std::cout << "Element is not a number" << std::endl;
            return NAN;
        }
    }

    unsigned int integerPartContainerSize = integerPartContainer.GetSize();
    for (int i = 0; i < integerPartContainerSize; ++i)
        integerPart += integerPartContainer[i] * std::pow(10, (integerPartContainerSize - 1) - i);

    unsigned int floatingPartContainerSize = floatingPartContainer.GetSize();
    for (int i = 0; i < floatingPartContainerSize; ++i)
        floatingPart += floatingPartContainer[i] / std::pow(10, i + 1);

    float result = 0;
    result = (float)(integerPart + floatingPart);

    if (negateFlag)
        result *= -1.0f;
        
    return result;
}

int main(int argc, char* argv[])
{
    GLVM::Core::TCVectorContainer<char> word;
    word.Push('-');
    word.Push('2');
    word.Push('3');
    word.Push('3');
    word.Push('.');
    word.Push('1');
    word.Push('1');
    word.Push('1');

    float result = ParseFloating(word);

    std::cout << result << std::endl;
    
    return 0;
}
