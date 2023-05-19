#include "matrix.h"

Matrix::Matrix(int n, int m) { // Конструктор - принимает целочисленный параметр n и создает квадратную матрицу размером n x m, заполняя ее нулями.
    size = n;
    for (int i = 0; i < n; i++) {
        std::vector<int> row(m, 0);
        array.push_back(row);
    }
}
void Matrix::Random() { // Метод заполняет матрицу случайными числами от 2 до n^3 (без 0 и 1), используя генератор случайных чисел.
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < array[i].size(); j++) {
            int num = rand() % (size * array[i].size() * array.size()) + 2;
            array[i][j] = num;
        }
    }
}
void Matrix::Manually() {
    std::cout << "Введите " << array.size() * array[0].size() << " чисел для заполнения вектора (без 0 и 1)" << std::endl;
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[0].size(); j++) {
            std::cin >> array[i][j];
            if (array[i][j] == 0 || array[i][j] == 1) {
                std::cout << "Введена 1 или 0. Выход из программы";
                exit(0);
            }
        }
    }
    if (std::cin.fail()) {
        std::cerr << "Ошибка: введено некорректное значение!" << std::endl;
        return;
    }
//    if (std::cin.peek() != EOF && std::cin.peek() != '\n') {
//        std::cerr << "Предупреждение: введено больше " << array.size() * array[0].size() << " чисел, лишние значения будут проигнорированы." << std::endl;
//        return;
//    }
}

void Matrix::Replace() { // Метод заменяет все повторяющиеся элементы матрицы на 1, а все неповторяющиеся значения - на 0.
    std::vector<int> fmatrix; // Создаем одномерный вектор, в который копируем элементы исходной матрицы
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[i].size(); j++) {
            fmatrix.push_back(array[i][j]);
        }
    }
    std::unordered_map<int, int> count; // Создаем хэш-таблицу, которая содержит количество вхождений каждого элемента в вектор. (ключ + значение)
    for (int i = 0; i < fmatrix.size(); i++) {
        count[fmatrix[i]]++;
    }
    for (int i = 0; i < fmatrix.size(); i++) { // Проходим по всем элементам вектора и проверяем, сколько раз они встречаются в хэш-таблице.
        if (count[fmatrix[i]] > 1) {
            fmatrix[i] = 1;
            count[fmatrix[i]] = 1;
        }
        else { fmatrix[i] = 0; }
    }
    int k = 0;
    for (int i = 0; i < array.size(); i++) { // Проходим по всем элементам вектора и копируем их обратно в матрицу.
        for (int j = 0; j < array[i].size(); j++) {
            array[i][j] = fmatrix[k++];
        }
    }
}

void Matrix::DeleteZero() { // Метод удаляет из матрицы все строки и столбцы, которые состоят только из нулей.
    // Перебираем столбцы матрицы
    for (int j = 0; j < array[0].size(); j++) {
        bool allZeros = true;
        // Проверяем, все ли элементы в текущем столбце равны 0
        for (int i = 0; i < array.size(); i++) {
            if (array[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        // Если все элементы равны 0, удаляем столбец из матрицы
        if (allZeros) {
            for (int i = 0; i < array.size(); i++) {
                array[i].erase(array[i].begin() + j);
            }
            j--;
        }
    }
    // Перебираем строки матрицы
    for (auto it = array.begin(); it != array.end(); ) {
        bool allZeros = true;
        // Проверяем, все ли элементы в текущей строке равны 0
        for (int x : *it) {
            if (x != 0) {
                allZeros = false;
                break;
            }
        }
        // Если все элементы равны 0, удаляем строку из матрицы
        if (allZeros) {
            it = array.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Matrix::Display(int version) {
    // Выводим матрицу, раскрашивая нулевые строки и столбцы в красный цвет
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[0].size(); j++) {
            if (version == 1) {
                std::cout << array[i][j] << "\t";
            }
            else if (version == 2) {
                std::cout << array[i][j] << "  ";
            }
            else if (version == 3) {
                std::vector<bool> zeroRows(array.size(), true);
                std::vector<bool> zeroCols(array[0].size(), true);
                // Определяем нулевые строки и столбцы
                for (int i = 0; i < array.size(); i++) {
                    for (int j = 0; j < array[0].size(); j++) {
                        if (array[i][j] != 0) {
                            zeroRows[i] = false;
                            zeroCols[j] = false;
                        }
                    }
                }
                if (zeroRows[i] || zeroCols[j]) {
                    std::cout << "\033[34m" << array[i][j] << "\033[0m  ";
                }
                else {
                    std::cout << array[i][j] << "  ";
                }
            }
        }
        std::cout << "\n";
    }
}
