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
            std::cout << "Введите размер двумерного массива (NxM) >> ";
            std::cin >> n >> m;
            if (n < 0 || m < 0) { std::cout << "\nОтрицательное значение длины матрицы.\nПовторите ввод\n\n"; break; }
            if (n == 0 || m == 0) { std::cout << "\nПустая матрица\n\n"; break; }
            if (n > 0 && m > 0) {
                Matrix matrix(n, m);
                int choice;
                std::cout << "Как заполнить матрицу?" << std::endl;
                std::cout << "1. Рандомно" << std::endl;
                std::cout << "2. Вручную (с клавиатуры)" << std::endl;
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
                    std::cout << "Неверный ввод! Матрица заполняется рандомно." << std::endl;
                    matrix.Random();
                    break;
                }
                int pole_m = m * 3 + 5 * (m - 1) + 1;
                int pole = (m - 1) * 2 + m + 1;
                std::cout << "\nМатрица" << std::endl;
                std::cout << std::setfill('-') << std::setw(pole_m) << "\n";
                matrix.Display(1);
                std::cout << "\nМатрица с заменой повторяющихся элементов на 1, неповторяющихся на 0" << std::endl;
                std::cout << std::setfill('-') << std::setw(pole) << "\n";
                matrix.Replace();
                matrix.Display(3);
                std::cout << "\nМатрица с удаленными пустыми строками" << std::endl;
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
