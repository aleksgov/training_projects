#include "Tablet.h"

Tablets::Tablets() {
    price = 0;
    brand = "";
    num = 0;
}
Tablets::Tablets(std::string b, double p, std::string c) {
    price = p;
    country = c;
    brand = b;
}
void Tablets::setter() {
    std::cout << "������� ���������� �������� (���� �������� �������� - 10 ��.) >> ";
    int n;
    std::cin >> n;
    num = n;
}
double Tablets::get_price() {
    return price;
}
double Tablets::get_num() {
    return num;
}
double Tablets::cost() {
    return price * num;
}
void Tablets::print() {
    std::cout << "����� " << brand << ", ������ ������������� - " << country << ", ���� - " << price << " ������" << std::endl;
}