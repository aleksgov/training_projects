#include "matrix.h"

Matrix::Matrix(int n, int m) { // ����������� - ��������� ������������� �������� n � ������� ���������� ������� �������� n x m, �������� �� ������.
    size = n;
    for (int i = 0; i < n; i++) {
        std::vector<int> row(m, 0);
        array.push_back(row);
    }
}
void Matrix::Random() { // ����� ��������� ������� ���������� ������� �� 2 �� n^3 (��� 0 � 1), ��������� ��������� ��������� �����.
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < array[i].size(); j++) {
            int num = rand() % (size * array[i].size() * array.size()) + 2;
            array[i][j] = num;
        }
    }
}
void Matrix::Manually() {
    std::cout << "������� " << array.size() * array[0].size() << " ����� ��� ���������� ������� (��� 0 � 1)" << std::endl;
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[0].size(); j++) {
            std::cin >> array[i][j];
            if (array[i][j] == 0 || array[i][j] == 1) {
                std::cout << "������� 1 ��� 0. ����� �� ���������";
                exit(0);
            }
        }
    }
    if (std::cin.fail()) {
        std::cerr << "������: ������� ������������ ��������!" << std::endl;
        return;
    }
//    if (std::cin.peek() != EOF && std::cin.peek() != '\n') {
//        std::cerr << "��������������: ������� ������ " << array.size() * array[0].size() << " �����, ������ �������� ����� ���������������." << std::endl;
//        return;
//    }
}

void Matrix::Replace() { // ����� �������� ��� ������������� �������� ������� �� 1, � ��� ��������������� �������� - �� 0.
    std::vector<int> fmatrix; // ������� ���������� ������, � ������� �������� �������� �������� �������
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[i].size(); j++) {
            fmatrix.push_back(array[i][j]);
        }
    }
    std::unordered_map<int, int> count; // ������� ���-�������, ������� �������� ���������� ��������� ������� �������� � ������. (���� + ��������)
    for (int i = 0; i < fmatrix.size(); i++) {
        count[fmatrix[i]]++;
    }
    for (int i = 0; i < fmatrix.size(); i++) { // �������� �� ���� ��������� ������� � ���������, ������� ��� ��� ����������� � ���-�������.
        if (count[fmatrix[i]] > 1) {
            fmatrix[i] = 1;
            count[fmatrix[i]] = 1;
        }
        else { fmatrix[i] = 0; }
    }
    int k = 0;
    for (int i = 0; i < array.size(); i++) { // �������� �� ���� ��������� ������� � �������� �� ������� � �������.
        for (int j = 0; j < array[i].size(); j++) {
            array[i][j] = fmatrix[k++];
        }
    }
}

void Matrix::DeleteZero() { // ����� ������� �� ������� ��� ������ � �������, ������� ������� ������ �� �����.
    // ���������� ������� �������
    for (int j = 0; j < array[0].size(); j++) {
        bool allZeros = true;
        // ���������, ��� �� �������� � ������� ������� ����� 0
        for (int i = 0; i < array.size(); i++) {
            if (array[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        // ���� ��� �������� ����� 0, ������� ������� �� �������
        if (allZeros) {
            for (int i = 0; i < array.size(); i++) {
                array[i].erase(array[i].begin() + j);
            }
            j--;
        }
    }
    // ���������� ������ �������
    for (auto it = array.begin(); it != array.end(); ) {
        bool allZeros = true;
        // ���������, ��� �� �������� � ������� ������ ����� 0
        for (int x : *it) {
            if (x != 0) {
                allZeros = false;
                break;
            }
        }
        // ���� ��� �������� ����� 0, ������� ������ �� �������
        if (allZeros) {
            it = array.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Matrix::Display(int version) {
    // ������� �������, ����������� ������� ������ � ������� � ������� ����
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
                // ���������� ������� ������ � �������
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
