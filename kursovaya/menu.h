#pragma once
#include "matrix.h"

void print_menu() {
    system("cls");
    std::cout << "����� �� ������ �������?" << std::endl;
    std::cout << "1. ������ ������" << std::endl;
    std::cout << "2. �����" << std::endl;
    std::cout << ">> ";
}

int str_to_int(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            throw std::invalid_argument("������ �� �������� ������.");
        }
    }
    return std::stoi(str);
}

int get_variant(int count) {
    std::string variant;
    std::cin >> variant;
    int num;
    try {
        num = str_to_int(variant);

    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    while (num < 1 || num > count) {
        std::cout << "������������ ����. ���������� ��� ���." << std::endl;
        break;
    }
    return num;
}