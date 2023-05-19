#include <fstream>
#include <windows.h>
#include "stack.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string path = "myfile.txt";
	std::string storage;
	char st, var;
	std::ifstream fin;
	fin.open(path);
	zadanie();
	if (!fin.is_open()) {
		std::cout << "�� ������� ������� ����" << std::endl;
	}
	else {
		std::cout << "���� ������� ������" << std::endl;
		std::cout << "\n������� ������ �� �������� ����� ���� ��������� (�� ������� ASCII)\n\n���� -> ";
		std::cin >> var;
		while (fin.get(st)) {
			if (st > int(var)) {
				storage = st;
				DATA d = { storage };
				push(d);
			}
		}
	}
	show();
	fin.close();
	return 0;
}

void zadanie() {
	std::cout << "������� ������������:\n---------------------------------------------------------------------\n�� ����� ��������� � ���� ��� �������, ����������� �������� ��������.\n---------------------------------------------------------------------" << std::endl;
}
void pop() {
	if (top == NULL) return;
	OBJ* ptr = top->next;
	std::cout << "������" << top->d.str << "�����\n";
	delete top;
	top = ptr;
}

void show() {
	OBJ* c = top;
	std::cout << "\n����� �����" << std::endl << "----------------" << std::endl;
	while (c != NULL) {
		std::cout << c->d.str;
		c = c->next;
	}
	std::cout << std::endl;
}

