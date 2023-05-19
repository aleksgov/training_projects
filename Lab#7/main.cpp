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
            std::cout << "������� ������ >> ";
            std::getline(std::cin, input);
            std::vector<std::pair<int, int>> encoded; //������ ��� ������������� ��������
            encode(input, encoded);
            std::string decoded;
            decode(encoded, decoded);
            std::cout << "---------------------------------------" << std::endl << "������������� ������: ";
            for (auto p : encoded) { //������� ��� pair, ������� ������������� �������� �� ������� �������������
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cout << std::endl << "---------------------------------------" << std::endl << "�������������� ������: " << decoded << std::endl;
            if (input == decoded) {
                std::cout << "---------------------------------------" << std::endl << "�������� ������ ��������� � ���������������. ���� �������!" << std::endl << std::endl;
            }
            else {
                std::cout << "---------------------------------------" << std::endl << "���� ��������!" << std::endl;
            }
            break;
        }
        case(2): {
            std::vector<std::pair<int, int>> encoded; // ������ ��� ��� ������������ ������
            std::vector<std::pair<int, int>> encoded2; // ������ ��� ��� ������������ ������ ��������� ���� ������������� � �������� ���������
            std::string decoded;
            std::cin.ignore();
            readPairs(encoded); // ������ ������ (���)
            decode(encoded, decoded);
            std::cout << "---------------------------------------" << std::endl << "�������� ������������� ������: ";
            for (auto p : encoded) {
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cout << std::endl << "---------------------------------------" << std::endl << "�������������� ������: ";
            std::cout << decoded << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "������������� ������: ";
            encode(decoded, encoded2);
            for (auto p : encoded2) {
                std::cout << "[" << p.first << "," << p.second << "] ";
            }
            std::cin.clear();
            std::cin.sync();
            std::cout << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            if (comparePairs(encoded, encoded2)) {
                std::cout << "������ ���������. ���� �������!" << std::endl << std::endl;
            }
            else { std::cout << "���� ��������!" << std::endl << std::endl; }
        }
               break;
        } 
        if (choice != 3) { system("pause"); }
    } while (choice != 3);
    return 0;
}



