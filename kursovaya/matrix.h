#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <windows.h>
#include <ctime>
#include <iomanip>

class Matrix {
private:
    std::vector<std::vector<int>> array;
    int size;
public:
    Matrix(int, int);
    void Random();
    void Manually();
    void Replace();
    void DeleteZero();
    void Display(int);
};
