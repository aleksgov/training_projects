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
    std::cout << "Вас приветствует помощник по алгоритму LZ77!" << std::endl;
    std::cout << "Чтобы вы хотели сделать?" << std::endl;
    std::cout << "1. Кодирование данных" << std::endl;
    std::cout << "2. Декодирование данных" << std::endl;
    std::cout << "3. Выход" << std::endl;
    std::cout << ">> ";
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
        std::cout << "\033[0;31mНеккоректный ввод. Попробуйте еще раз.\033[0m" << std::endl << std::endl;
        break;
    }
    return num;
}

// Функция для кодирования данных
void encode(std::string input, std::vector<std::pair<int, int>>& output) {
    //добавляем словарь (плавающее окно)
    int WINDOW_SIZE = 1024; // максимальный размер окна
    int index = 0, match_length = 0, max_match_length = 0, max_match_index = 0;
    for (int i = 0; i < input.size(); i++) {
        match_length = 0;
        // поиск самой длинной подстроки, совпадающей с текущим фрагментом текста
        for (int j = (std::max)(index, i - WINDOW_SIZE); j < i; j++) { // ограничиваем поиск максимальной подстроки только в пределах окна
            int k = 0;
            while (input[i + k] == input[j + k]) {
                k++;
                if (i + k >= input.size()) {
                    break; // если дошли до конца текста, то прерываем
                }
            }
            if (k > match_length) { // если найдена более длинная подстрока - запоминаем ее (макс. длину и макс. индекс)
                match_length = k;
                max_match_length = k;  
                max_match_index = j; 
            }
        }
        if (match_length == 0) { // если не найдено совпадений, то добавляем символ в выходной поток
            output.push_back(std::make_pair(0, input[i]));
        }
        else { // если найдена подстрока, то добавляем информацию о ней в выходной поток
            output.push_back(std::make_pair(i - max_match_index, match_length)); // пара вида (смещение, длина)
            i += match_length - 1; // пропускаем найденную подстроку
            index = max_match_index + match_length; // продолжаем поиск совпадений в следующем фрагменте текста
        }
    }
}

//функция для декодирования данных
void decode(std::vector<std::pair<int, int>> input, std::string& output) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i].first == 0) { //если первый символ пары 0, то переводим его код ASCII в символ и добавляем в строку
            output += char(input[i].second);
        }
        else { // в противном случае находим индекс, с которого нужно начать декодирование
            int start_index = output.size() - input[i].first;
            for (int j = 0; j < input[i].second; j++) { // и декодируем последовательность символов
                output += output[start_index + j];
            }
        }
    }
}

void readPairs(std::vector<std::pair<int, int>>& input) {
    int x, y;
    char comma;
    std::string line;
    std::cout << "Введите пары вида (int, int)" << std::endl;
    while (std::getline(std::cin, line) && !line.empty()) {
        std::istringstream iss(line);
        if (!(iss >> x >> comma >> y)) {
            std::cout << "\033[0;31mНекорректный формат пары. Введите пару вида (int, int)\033[0m" << std::endl;
        }
        else {
            input.push_back(std::make_pair(x, y));
        }
    }
}

// функция сравнения двух векторов пар
bool comparePairs(const std::vector<std::pair<int, int>>& vector1, const std::vector<std::pair<int, int>>& vector2) { 
    // Если размеры векторов не совпадают, то они точно не равны
    if (vector1.size() != vector2.size()) {
        return false;
    }
    // Сравниваем каждую пару векторов
    return std::equal(vector1.begin(), vector1.end(), vector2.begin());
}