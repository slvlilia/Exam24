// Task1FibonacciSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int enterFibonacciStartValueLimit();
bool isEvenNumber(int number);
string toString(bool isEvenNumber);
int getSumForStartValueLimitNumbers(int startValueLimitNumbers);

int main()
{
    int fibonacciStartValueLimit = enterFibonacciStartValueLimit();
    int sum = getSumForStartValueLimitNumbers(fibonacciStartValueLimit);
    if (sum == -1) {
        cout << "Bad data! Number must be positive!!!";
        return 1;
    }
    bool isEven = isEvenNumber(sum);
    cout << "For fibonacci start value limit: " << fibonacciStartValueLimit << "\n" << "Sum " << sum << ": for this numbers is - " << toString(isEven) << "\n";
}


int enterFibonacciStartValueLimit() {
    int valueLimit;
    cout << "Please enter a positive number for fibonacci start value limit...\n";
    cin >> valueLimit;
    if (valueLimit < 0) {
        return -1;
    }
    return valueLimit;
}

bool isEvenNumber(int number) {
    if (number % 2 == 0) {
        return true;
    }
    else
    {
        return false;
    }
}

string toString(bool isEvenNumber) {
    if (isEvenNumber) {
        return "even";
    }
    else {
        return "odd.";
    }
}

int getSumForStartValueLimitNumbers(int startValueLimitNumbers) {
    if (startValueLimitNumbers == -1) {
        return startValueLimitNumbers;
    }

    int number = 1;
    int firstFibonacciValue = 1;
    int secondFibonacciValue = 1;
    int nextFibonacciValue = 0;
    int sum = 0;

    number = startValueLimitNumbers;

    for (int i = 1; i <= number; ++i) {
        if (i == 1) {
            sum += firstFibonacciValue;
            continue;
        }
        if (i == 2) {
            sum += secondFibonacciValue;
            continue;
        }
        nextFibonacciValue = firstFibonacciValue + secondFibonacciValue;
        firstFibonacciValue = secondFibonacciValue;
        secondFibonacciValue = nextFibonacciValue;
        sum += nextFibonacciValue;
    }
    return sum;
}
