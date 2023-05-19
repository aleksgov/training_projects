#include "quantity.h"

QuantityOfInformation::QuantityOfInformation() : bytes(bytes_default) {}

QuantityOfInformation::QuantityOfInformation(double value) {
    if (value < 0) {
        std::cout << "Incorrect byte value. Setting a default value" << std::endl;
        bytes = bytes_default;
    }
    else bytes = value;
}

void QuantityOfInformation::SetBytes(double value) {
    if (value < 0) {
        std::cout << "Incorrect byte value. Setting a default value" << std::endl;
        bytes = bytes_default;
    }
    else bytes = value;
}
double QuantityOfInformation::get_bytes() { return bytes; }

double QuantityOfInformation::convert_to_bit() {
    return (bytes * 8);
}
double QuantityOfInformation::convert_to_kilobytes() {
    return (bytes / 1024);
}
double QuantityOfInformation::convert_to_megabytes() {
    return (bytes / pow(1024, 2));
}
double QuantityOfInformation::convert_to_gigabytes() {
    return (bytes / pow(1024, 3));
}
double QuantityOfInformation::convert_to_terabytes() {
    return (bytes / pow(1024, 4));
}

bool QuantityOfInformation::operator< (QuantityOfInformation val) {
    return bytes < val.bytes;
}

bool QuantityOfInformation::operator<= (QuantityOfInformation val) {
    return bytes <= val.bytes;
}

bool QuantityOfInformation::operator> (QuantityOfInformation val) {
    return bytes > val.bytes;
}

bool QuantityOfInformation::operator>= (QuantityOfInformation arg) {
    return bytes >= arg.bytes;
}

bool QuantityOfInformation::operator== (QuantityOfInformation val) {
    return bytes == val.bytes;
}

bool QuantityOfInformation::operator!= (QuantityOfInformation val) {
    return bytes != val.bytes;
}

QuantityOfInformation QuantityOfInformation::operator+(QuantityOfInformation val) {
    QuantityOfInformation temp;
    temp.bytes = bytes + val.bytes;
    return temp;
}
QuantityOfInformation QuantityOfInformation::operator-(QuantityOfInformation val) {
    QuantityOfInformation temp;
    temp.bytes = bytes - val.bytes;
    return temp;
}

QuantityOfInformation QuantityOfInformation::operator*(QuantityOfInformation val) {
    QuantityOfInformation temp;
    temp.bytes = bytes * val.bytes;
    return temp;
}

QuantityOfInformation QuantityOfInformation::operator/(QuantityOfInformation val) {
    QuantityOfInformation temp;
    temp.bytes = bytes / val.bytes;
    return temp;
}

QuantityOfInformation& QuantityOfInformation::operator+=(QuantityOfInformation val) {
    bytes += val.bytes;
    return *this;
}

QuantityOfInformation& QuantityOfInformation::operator-=(QuantityOfInformation val) {
    bytes -= val.bytes;
    return *this;
}

QuantityOfInformation& QuantityOfInformation::operator*=(QuantityOfInformation val) {
    bytes *= val.bytes;
    return *this;
}

QuantityOfInformation& QuantityOfInformation::operator/=(QuantityOfInformation val) {
    bytes /= val.bytes;
    return *this;
}

QuantityOfInformation& QuantityOfInformation::operator=(QuantityOfInformation val) {
    bytes = val.bytes;
    return *this;
}

void zadanie() {
    std::cout << "Задание лабораторной:\n-------------------------------------------------------------------------------------------------------" << std::endl
        << "Разработать класс Количество информации. Объекты класса должны хранить значение количества информации (в байтах)" << std::endl
        << "Перегрузить операции сравнения, арифметические операции, перегрузка >>, << (для ввода / вывода)." << std::endl
        << "Реализовать метод перевода количества информации из байт в бит, килобайт, мегабайт, гигабайт, терабайт." << std::endl
        << "-------------------------------------------------------------------------------------------------------" << std::endl;
}
