#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <utility>
#include <algorithm>
#include <limits>  
#include <sstream>

void print_menu() {
    system("cls");
    std::cout << "��� ������������ �������� �� ��������� LZ77!" << std::endl;
    std::cout << "����� �� ������ �������?" << std::endl;
    std::cout << "1. ����������� ������" << std::endl;
    std::cout << "2. ������������� ������" << std::endl;
    std::cout << "3. �����" << std::endl;
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
        std::cout << "\033[0;31m������������ ����. ���������� ��� ���.\033[0m" << std::endl << std::endl;
        break;
    }
    return num;
}

// ������� ��� ����������� ������
void encode(std::string input, std::vector<std::pair<int, int>>& output) {
    //��������� ������� (��������� ����)
    int WINDOW_SIZE = 1024; // ������������ ������ ����
    int index = 0, match_length = 0, max_match_length = 0, max_match_index = 0;
    for (int i = 0; i < input.size(); i++) {
        match_length = 0;
        // ����� ����� ������� ���������, ����������� � ������� ���������� ������
        for (int j = (std::max)(index, i - WINDOW_SIZE); j < i; j++) { // ������������ ����� ������������ ��������� ������ � �������� ����
            int k = 0;
            while (input[i + k] == input[j + k]) {
                k++;
                if (i + k >= input.size()) {
                    break; // ���� ����� �� ����� ������, �� ���������
                }
            }
            if (k > match_length) { // ���� ������� ����� ������� ��������� - ���������� �� (����. ����� � ����. ������)
                match_length = k;
                max_match_length = k;  
                max_match_index = j; 
            }
        }
        if (match_length == 0) { // ���� �� ������� ����������, �� ��������� ������ � �������� �����
            output.push_back(std::make_pair(0, input[i]));
        }
        else { // ���� ������� ���������, �� ��������� ���������� � ��� � �������� �����
            output.push_back(std::make_pair(i - max_match_index, match_length)); // ���� ���� (��������, �����)
            i += match_length - 1; // ���������� ��������� ���������
            index = max_match_index + match_length; // ���������� ����� ���������� � ��������� ��������� ������
        }
    }
}

//������� ��� ������������� ������
void decode(std::vector<std::pair<int, int>> input, std::string& output) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i].first == 0) { //���� ������ ������ ���� 0, �� ��������� ��� ��� ASCII � ������ � ��������� � ������
            output += char(input[i].second);
        }
        else { // � ��������� ������ ������� ������, � �������� ����� ������ �������������
            int start_index = output.size() - input[i].first;
            for (int j = 0; j < input[i].second; j++) { // � ���������� ������������������ ��������
                output += output[start_index + j];
            }
        }
    }
}

void readPairs(std::vector<std::pair<int, int>>& input) {
    int x, y;
    char comma;
    std::string line;
    std::cout << "������� ���� ���� (int, int)" << std::endl;
    while (std::getline(std::cin, line) && !line.empty()) {
        std::istringstream iss(line);
        if (!(iss >> x >> comma >> y)) {
            std::cout << "\033[0;31m������������ ������ ����. ������� ���� ���� (int, int)\033[0m" << std::endl;
        }
        else {
            input.push_back(std::make_pair(x, y));
        }
    }
}

// ������� ��������� ���� �������� ���
bool comparePairs(const std::vector<std::pair<int, int>>& vector1, const std::vector<std::pair<int, int>>& vector2) { 
    // ���� ������� �������� �� ���������, �� ��� ����� �� �����
    if (vector1.size() != vector2.size()) {
        return false;
    }
    // ���������� ������ ���� ��������
    return std::equal(vector1.begin(), vector1.end(), vector2.begin());
}