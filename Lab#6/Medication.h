#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <cctype>

class Medication {
public:
    virtual double cost() = 0;
    virtual double get_price() = 0;
    virtual double get_num() = 0;
    virtual void print() = 0;
    virtual void set_num() = 0;
    double get_quant() {
        return quantity;
    }
    void set_quant(int n) {
        quantity += n;
    }
protected:
    double price = 0;
    int num = 0;
    std::string brand;
    std::string country;
    int quantity = 0;
};

void print_menu();
int get_variant(int);

