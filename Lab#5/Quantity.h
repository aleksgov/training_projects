#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip>
using namespace std;

class QuantityOfInformation {
private:
    const double bytes_default = 100000.0;
    double bytes;
public:
    QuantityOfInformation();
    QuantityOfInformation(double);
    void SetBytes(double);
    double get_bytes();
    double convert_to_bit();
    double convert_to_kilobytes();
    double convert_to_megabytes();
    double convert_to_gigabytes();
    double convert_to_terabytes();
    bool operator>(QuantityOfInformation);
    bool operator<(QuantityOfInformation);
    bool operator==(QuantityOfInformation);
    bool operator!=(QuantityOfInformation);
    bool operator>=(QuantityOfInformation);
    bool operator<=(QuantityOfInformation);
    QuantityOfInformation operator+(QuantityOfInformation);
    QuantityOfInformation operator-(QuantityOfInformation);
    QuantityOfInformation operator*(QuantityOfInformation);
    QuantityOfInformation operator/(QuantityOfInformation);
    QuantityOfInformation& operator+=(QuantityOfInformation);
    QuantityOfInformation& operator-=(QuantityOfInformation);
    QuantityOfInformation& operator*=(QuantityOfInformation);
    QuantityOfInformation& operator/=(QuantityOfInformation);
    QuantityOfInformation& operator=(QuantityOfInformation);

    friend istream& operator >> (istream& is, QuantityOfInformation& q) {
        cout << "Enter the amount of information in bytes: ";
        is >> q.bytes;
        return is;
    }

    friend ostream& operator << (ostream& os, const QuantityOfInformation& q) {
        os << q.bytes << " bytes";
        return os;
    }
};

void zadanie();