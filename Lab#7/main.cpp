#include "LZ77_function.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        print_menu();
        choice = get_variant(3);
        switch (choice) {
        case(1): {
            std::cin.ignore();
            std::string input;
            std::cout << "Введите данные >> ";
            std::getline(std::cin, input);
            std::vector<std::pair<int, int>> encoded; //вектор пар целочисленных значений
            encode(input, encoded);
            std::string decoded;
            decode(encoded, decoded);
            std::cout << "---------------------------------------" << std::endl << "Коддированные данные: ";
            for (auto p : encoded) { //перебор пар pair, которым присваиваются значения из функции декодирования
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cout << std::endl << "---------------------------------------" << std::endl << "Декодированные данные: " << decoded << std::endl;
            if (input == decoded) {
                std::cout << "---------------------------------------" << std::endl << "Исходные данные совпадают с декодированными. Тест пройден!" << std::endl << std::endl;
            }
            else {
                std::cout << "---------------------------------------" << std::endl << "Тест провален!" << std::endl;
            }
            break;
        }
        case(2): {
            std::vector<std::pair<int, int>> encoded; // вектор пар для кодированных данных
            std::vector<std::pair<int, int>> encoded2; // вектор пар для кодированных данных прошедших цикл декодирования и обратной кодировки
            std::string decoded;
            std::cin.ignore();
            readPairs(encoded); // чтение данных (пар)
            decode(encoded, decoded);
            std::cout << "---------------------------------------" << std::endl << "Исходные коддированные данные: ";
            for (auto p : encoded) {
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cout << std::endl << "---------------------------------------" << std::endl << "Декодированные данные: ";
            std::cout << decoded << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "Коддированные данные: ";
            encode(decoded, encoded2);
            for (auto p : encoded2) {
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cin.clear();
            std::cin.sync();
            std::cout << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            if (comparePairs(encoded, encoded2)) {
                std::cout << "Данные совпадают. Тест пройден!" << std::endl << std::endl;
            }
            else { std::cout << "Тест провален!" << std::endl << std::endl; }
        }
               break;
        } 
        if (choice != 3) { system("pause"); }
    } while (choice != 3);
    return 0;
}



