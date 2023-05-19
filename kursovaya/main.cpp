#include "menu.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, n, m;
    do {
        print_menu();
        choice = get_variant(2);
        switch (choice) {
        case(1): {
            std::cout << "������� ������ ���������� ������� (NxM) >> ";
            std::cin >> n >> m;
            if (n < 0 || m < 0) { std::cout << "\n������������� �������� ����� �������.\n��������� ����\n\n"; break; }
            if (n == 0 || m == 0) { std::cout << "\n������ �������\n\n"; break; }
            if (n > 0 && m > 0) {
                Matrix matrix(n, m);
                int choice;
                std::cout << "��� ��������� �������?" << std::endl;
                std::cout << "1. ��������" << std::endl;
                std::cout << "2. ������� (� ����������)" << std::endl;
                std::cout << ">> ";
                std::cin >> choice;
                switch (choice) {
                case 1:
                    matrix.Random();
                    break;
                case 2:
                    matrix.Manually();

                    break;
                default:
                    std::cout << "�������� ����! ������� ����������� ��������." << std::endl;
                    matrix.Random();
                    break;
                }
                int pole_m = m * 3 + 5 * (m - 1) + 1;
                int pole = (m - 1) * 2 + m + 1;
                std::cout << "\n�������" << std::endl;
                std::cout << std::setfill('-') << std::setw(pole_m) << "\n";
                matrix.Display(1);
                std::cout << "\n������� � ������� ������������� ��������� �� 1, ��������������� �� 0" << std::endl;
                std::cout << std::setfill('-') << std::setw(pole) << "\n";
                matrix.Replace();
                matrix.Display(3);
                std::cout << "\n������� � ���������� ������� ��������" << std::endl;
                std::cout << std::setfill('-') << std::setw(pole) << "\n";
                matrix.DeleteZero();
                matrix.Display(2);
                std::cout << std::endl;
            }
        }
        }
        if (choice != 2) { system("pause"); }
    } while (choice != 2);
    return 0;
}
