#include "Pill.h"

Pills::Pills() {
    price = 0;
    brand = "";
    num = 0;
}
Pills::Pills(std::string b, double p, std::string c) {
    price = p;
    country = c;
    brand = b;
}
void Pills::setter() {
    std::cout << "������� ���������� �������� (���� ���� ������ - 50 ��.) >> ";
    int n;
    std::cin >> n;
    num = n;
}
double Pills::get_price() {
    return price;
}
double Pills::get_num() {
    return num;
}
double Pills::cost() {
    return price * num;
}
void Pills::print() {
    std::cout << "����� " << brand << ", ������ ������������� - " << country << ", ���� - " << price << " ������" << std::endl;
}