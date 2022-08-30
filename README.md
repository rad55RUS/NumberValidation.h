# NumberValidation.h
My library for entering positive (for now) numbers, their validation and entering sequence (sequences may be separated later)
<br> <br>

## Number entering functions
### Integer entering
`enterInteger()`&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;   - enter integer <br>
`enterInteger(int min)`&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;  - enter integer not less than ***min*** <br>
`enterInteger(int min, int max)`&nbsp;&nbsp;&nbsp;                       - enter integer not less than ***min*** and not greater than ***max*** <br>
### Double entering
`enterDouble()`&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;   - enter double <br>
`enterDouble(int min)`&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  - enter double not less than ***min*** <br>
`enterDouble(int min, int max)`&nbsp;&nbsp;&nbsp;&nbsp;                       - enter double not less than ***min*** and not greater than ***max*** <br>

## Sequnce entering
### Integer sequence entering to vector
`enterSequence()`&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - enter sequence <br>
`enterSequence(int min, int max)`&nbsp;&nbsp;&nbsp;                                       - enter sequence not less than ***min*** and not greater than ***max*** <br>
## Validation functions (used by number entering functions)
`isInteger(string number)`&emsp;&emsp;&emsp;&nbsp;&nbsp;     - check string ***number*** for integer <br>
`isDouble(string number)`&emsp;&emsp;&emsp;&emsp;            - check string ***number*** for double <br>
<br>


# Code
```cpp
// Библиотеки
#include <iostream>     // Ввод-вывод
#include <iomanip>      // Ввод-вывод доп
#include <stdio.h>      // Ввод-вывод доп
#include <cstring>      // Строки
#include <sstream>      // Строки доп
#include <cctype>       // Символы
#include <ostream>      // Вывод доп
#include <cmath>        // Математика
#include <Windows.h>    // Windows API
#include <vector>       // Векторы
#include <ctime>        // Время
#include <chrono>       // Создание таймера
#include <list>         // Списки
#include <algorithm>    // Доп функции
#include <intrin.h>
//
#pragma once

using namespace std;

// Проверка на целое число
bool isInteger(string number)
{
    return all_of(number.begin(), number.end(), ::isdigit);
}
//

// Проверка на дробное число
bool isDouble(string number)
{
    int commas = 0;
    bool is_double = (number.find_first_not_of("0123456789,.") == string::npos);
    if (is_double == true && !isdigit(number[0]) && !isdigit(number[number.size() - 1]))
        is_double = false;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == ',' || number[i] == '.') {
            commas++;
            if (commas > 1) {
                is_double = false;
                break;
            }
        }
    }
    return is_double;
}
//

// Ввод целого числа
int enterInteger()
{
    string number;
    getline(cin, number);
    while (isInteger(number) == false) // Проверка числа
    {
        cout << "\nПожалуйста, введите целое число: ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Ввод числа от min до inf
int enterInteger(int min)
{
    string number;
    getline(cin, number);
    while (isInteger(number) == false && stoi(number) > min) // Проверка числа
    {
        cout << "\nПожалуйста, введите целое число число не менее " << min << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Ввод числа от min до max
int enterInteger(int min, int max)
{
    string number;
    getline(cin, number);
    while (isInteger(number) && stoi(number) > min && stoi(number) < max) // Проверка числа
    {
        cout << "\nПожалуйста, введите целое число число не менее" << min << ", и не более " << max << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Ввод дробного числа
double enterDouble()
{
    string number;
    getline(cin, number);
    while (isDouble(number)) // Проверка числа
    {
        cout << "\nПожалуйста, введите дробное число: ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Ввод дробного числа от min до inf
double enterDouble(double min)
{
    string number;
    getline(cin, number);
    while (isDouble(number) && stod(number) > min) // Проверка числа
    {
        cout << "\nПожалуйста, введите дробное число число не менее " << min << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Ввод дробного числа от min до max
double enterDouble(double min, double max)
{
    string number;
    getline(cin, number);
    while (isDouble(number) && stod(number) > min && stod(number) < max) // Проверка числа
    {
        cout << "\nПожалуйста, введите дробное число число не менее" << min << ", и не более " << max << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Ввод последовательности целых чисел
vector<int> enterSequence()
{
    vector<int> seq;
    string sequence, number;
    bool again = false;
    getline(cin, sequence);
    for (int i = 0; i < sequence.size(); i++) {
        if (isdigit(sequence[i]))
            number.push_back(sequence[i]);
        else {
            if (number.size() > 0) {
                seq.push_back(stoi(number));
                number.clear();
            }
        }
    }
    if (isdigit(sequence[sequence.size() - 1])) {
        if (number.size() > 0) {
            seq.push_back(stoi(number));
            number.clear();
        }
    }
    return seq;
}
//

// Ввод последовательности целых чисел от min до max
vector<int> enterSequence(int min, int max)
{
    vector<int> seq;
    string number;
    string sequence;
    getline(cin, sequence);
    bool again = false;
    for (int i = 0; i < sequence.size(); i++) {
        if (isdigit(sequence[i]))
            number.push_back(sequence[i]);
        else {
            if (number.size() > 0) {
                if (stoi(number) < min || stoi(number) > max) {
                    again = true;
                    cout << "Введите последовательность еще раз: ";
                    break;
                }
                seq.push_back(stoi(number));
                number.clear();
            }
        }
    }
    if (!again)
        if (isdigit(sequence[sequence.size() - 1])) {
            if (number.size() > 0) {
                if (stoi(number) < min || stoi(number) > max) {
                    again = true;
                    cin.clear();
                    cout << "Введите последовательность еще раз: ";
                }
                seq.push_back(stoi(number));
                number.clear();
            }
        }
    if (!again)
        return seq;
    else
        return enterSequence(min, max);
}
//
```
