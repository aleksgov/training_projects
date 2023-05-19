#include "Vaccine.h"

Vaccine::Vaccine() {
    price = 0;
    brand = "";
    num = 0;
}
Vaccine::Vaccine(std::string b, double p, std::string c) {
    price = p;
    country = c;
    brand = b;
}
void Vaccine::setter() {
    std::cout << "������� ���������� �������� >> ";
    int n;
    std::cin >> n;
    num = n;
}
double Vaccine::get_price() {
    return price;
}
double Vaccine::get_num() {
    return num;
}
double Vaccine::cost() {
    return price * num;
}
void Vaccine::print() {
    std::cout << "����� " << brand << ", ������ ������������� - " << country << ", ���� - " << price << " ������" << std::endl;
}