#pragma once
#include <vector>
#include <stdexcept>

extern double summa = 0;
template<typename T>
void add(std::vector <T>& base, int i) {
    std::cout << "На складе доступно " << base[i].get_quant() << " единиц товара" << std::endl;
    base[i].set_num();
    if (base[i].get_num() > base[i].get_quant()) {
        std::cout << "На складе недостаточно товара" << std::endl;
    }
    else {
        base[i].set_quant(-base[i].get_num());
        std::cout << "В вашу корзину добавлено товара на сумму - " << base[i].cost() << " рублей" << std::endl;
    }
    summa += base[i].cost();
}

template<typename T>
void display(std::vector <T> base) {
    for (int i = 0; i < base.size(); i++) {
        std::cout << i + 1 << ".";
        base[i].print();
    }
    std::cout << std::endl;
}

void print_menu() {
    system("cls");
    std::cout << "Чтобы вы хотели сделать?" << std::endl;
    std::cout << "1. Вывести список препаратов аптеки" << std::endl;
    std::cout << "2. Перейти к покупке" << std::endl;
    std::cout << "3. Вывести конечную цену корзины" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << ">";
}

int str_to_int(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            throw std::invalid_argument("Строка не является числом.");
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
        std::cout << "Неккоректный ввод. Попробуйте еще раз." << std::endl;
        break;
    }
    return num;
}