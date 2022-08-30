#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cctype>
#include <string>
#include <ostream>
#include <cmath>
#include <math.h>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <time.h>
#include <intrin.h>
#include <ctime>
#include <chrono>
#include <list>
#include <algorithm>
#pragma once

using namespace std;

// Проверка на число (доп функция)
void isdFunc(bool& isd, char number[256], char* p)
{
    while (*p)
        if (!isdigit(unsigned char(*p++)))
        {
            isd = false;
            break;
        }
    if (abs(atof(number)) != (int)atof(number))
        isd = true;
}
//

// Валидация введенного числа
double checkNumber(double num, bool& check, bool& isd, char number[256], char* p)
{
    while (check == false) // Проверка числа N
    {
        isd = true;
        cout << "\nПожалуйста, введите число";
        cin >> number;
        p = number;
        isdFunc(isd, number, p);
        num = atof(number);
        if (isd == true)
            check = true;
    }
    return num;
}
//

// Ввод числа
double enterNumber()
{
    char number[256]{}, * p = number;
    bool isd = true;
    bool check = false;
    cin >> number;
    p = number;
    isdFunc(isd, number, p);
    double num = atof(number);
    if (isd == true)
        check = true;
    checkNumber(num, check, isd, number, p);
    return num;
}
//

// Валидация введенного числа от min до inf
double checkNumber(double num, bool& check, bool& isd, char number[256], char* p, int min)
{
    while (check == false) // Проверка числа N
    {
        isd = true;
        cout << "\nПожалуйста, введите число не менее " << min << ": ";
        cin >> number;
        p = number;
        isdFunc(isd, number, p);
        num = atof(number);
        if (isd == true && num >= min)
            check = true;
    }
    return num;
}
//

// Ввод числа от min до inf
double enterNumber(int min)
{
    char number[256]{}, * p = number;
    bool isd = true;
    bool check = false;
    cin >> number;
    p = number;
    isdFunc(isd, number, p);
    double num = atof(number);
    if (isd == true && num >= min)
        check = true;
    checkNumber(num, check, isd, number, p, min);
    return num;
}
//

// Валидация введенного числа от min до max
double checkNumber(double num, bool& check, bool& isd, char number[256], char* p, int min, int max)
{
    while (check == false) // Проверка числа N
    {
        isd = true;
        cout << "\nПожалуйста, введите число не менее " << min << " и не более " << max << ": ";
        cin >> number;
        p = number;
        isdFunc(isd, number, p);
        num = atof(number);
        if (isd == true && num >= min && num <= max)
            check = true;
    }
    return num;
}
//

// Ввод числа от min до max
double enterNumber(int min, int max)
{
    char number[256]{}, * p = number;
    bool isd = true;
    bool check = false;
    cin >> number;
    p = number;
    isdFunc(isd, number, p);
    double num = atof(number);
    if (isd == true && num >= min && num <= max)
        check = true;
    checkNumber(num, check, isd, number, p, min, max);
    return num;
}
//