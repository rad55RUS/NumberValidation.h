// ����������
#include <iostream>     // ����-�����
#include <iomanip>      // ����-����� ���
#include <stdio.h>      // ����-����� ���
#include <cstring>      // ������
#include <sstream>      // ������ ���
#include <cctype>       // �������
#include <ostream>      // ����� ���
#include <cmath>        // ����������
#include <Windows.h>    // Windows API
#include <vector>       // �������
#include <ctime>        // �����
#include <chrono>       // �������� �������
#include <list>         // ������
#include <algorithm>    // ��� �������
#include <intrin.h>
//
#pragma once

using namespace std;

// �������� �� ����� �����
bool isInteger(string number)
{
    return all_of(number.begin(), number.end(), ::isdigit);
}
//

// �������� �� ������� �����
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

// ���� ������ �����
int enterInteger()
{
    string number;
    getline(cin, number);
    while (isInteger(number) == false) // �������� �����
    {
        cout << "\n����������, ������� ����� �����: ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// ���� ����� �� min �� inf
int enterInteger(int min)
{
    string number;
    getline(cin, number);
    while (isInteger(number) == false && stoi(number) > min) // �������� �����
    {
        cout << "\n����������, ������� ����� ����� ����� �� ����� " << min << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// ���� ����� �� min �� max
int enterInteger(int min, int max)
{
    string number;
    getline(cin, number);
    while (isInteger(number) && stoi(number) > min && stoi(number) < max) // �������� �����
    {
        cout << "\n����������, ������� ����� ����� ����� �� �����" << min << ", � �� ����� " << max << ": ";
        cin >> number;
    }
    int num = stoi(number);
    return num;
}
//

// ���� �������� �����
double enterDouble()
{
    string number;
    getline(cin, number);
    while (isDouble(number)) // �������� �����
    {
        cout << "\n����������, ������� ������� �����: ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// ���� �������� ����� �� min �� inf
double enterDouble(double min)
{
    string number;
    getline(cin, number);
    while (isDouble(number) && stod(number) > min) // �������� �����
    {
        cout << "\n����������, ������� ������� ����� ����� �� ����� " << min << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// ���� �������� ����� �� min �� max
double enterDouble(double min, double max)
{
    string number;
    getline(cin, number);
    while (isDouble(number) && stod(number) > min && stod(number) < max) // �������� �����
    {
        cout << "\n����������, ������� ������� ����� ����� �� �����" << min << ", � �� ����� " << max << ": ";
        cin >> number;
    }
    double num = stod(number);
    return num;
}
//

// ���� ������������������ ����� �����
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

// ���� ������������������ ����� ����� �� min �� max
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
                    cout << "������� ������������������ ��� ���: ";
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
                    cout << "������� ������������������ ��� ���: ";
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