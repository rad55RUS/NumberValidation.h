# NumberValidation.h
My library for entering numbers, their validation and entering sequence (sequences may be separated later). If you want to use english version of code,
you can copy it below
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
`enterSequence(vector<int> seq)`&nbsp;&nbsp;&nbsp;          - enter sequence ***seq*** <br>
## Validation functions (used by number entering functions)
`isInteger(string number)`&emsp;&emsp;&emsp;&nbsp;&nbsp;     - check string ***number*** for integer <br>
`isDouble(string number)`&emsp;&emsp;&emsp;&emsp;            - check string ***number*** for double <br>
<br>


# Code
```cpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <cctype>
#include <ostream>
#include <cmath>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <chrono>
#include <list>
#include <algorithm>
#include <intrin.h>
#pragma once

using namespace std;

// Integer validation
bool isInteger(string number)
{
    return all_of(number.begin(), number.end(), ::isdigit);
}
//

// Double validation
bool isDouble(string number)
{
    int commas = 0;
    bool is_double = (number.find_first_not_of("0123456789,.") == std::string::npos);
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

// Integer entering
int enterInteger()
{
    string number;
    cin >> number;
    while (isInteger(number) == false)
    {
        cout << "\nPlease, enter integer: ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Integer entering from min to inf
int enterInteger(int min)
{
    string number;
    cin >> number;
    while (isInteger(number) == false && stoi(number) > min)
    {
        cout << "\nPlease, enter integer not less than " << min << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Integer entering from min to max
int enterInteger(int min, int max)
{
    string number;
    cin >> number;
    while (isInteger(number) && stoi(number) > min && stoi(number) < max)
    {
        cout << "\nPlease, enter integer not less than " << min << ", and not greater " << max << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// Double entering
double enterDouble()
{
    string number;
    cin >> number;
    while (isDouble(number))
    {
        cout << "\nPlease, enter fractional number: ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Double entering from min to inf
double enterDouble(double min)
{
    string number;
    cin >> number;
    while (isDouble(number) && stod(number) > min)
    {
        cout << "\nPlease, enter fractional number not less than " << min << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Double entering from min to max
double enterDouble(double min, double max)
{
    string number;
    cin >> number;
    while (isDouble(number) && stod(number) > min && stod(number) < max) // Проверка числа
    {
        cout << "\nPlease, enter fractional number not less than " << min << ", and not greater " << max << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// Integer sequence entering
vector<int> enterSequence(vector<int> seq)
{
    string sequence, number;
    bool isd = true;
    bool check = false;
    cin >> sequence;
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
    if (sequence[sequence.size() - 1] != ',' && sequence[sequence.size() - 1] != ' ' && sequence[sequence.size() - 1] != '.') {
        if (number.size() > 0) {
            seq.push_back(stoi(number));
            number.clear();
        }
    }
    return seq;
}
//
```
