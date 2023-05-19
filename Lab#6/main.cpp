#include "Medication.h"
#include "Pill.h"
#include "Tablet.h"
#include "Vaccine.h"
#include "Extra.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	std::vector<Pills> pills = {
	{"Greenwood", 1250, "Германия", 21},
	{"Taibao", 1100, "Китай", 39},
	{"Evrika", 750, "Россия", 42}
	};
	std::vector<Tablets> tablets{
	{"Kitoshi", 750, "Япония", 18},
	{"Evalar", 250, "Россия", 31},
	{"Danson", 540, "Испания", 23}
	};
	std::vector<Vaccine> vaccine = {
	{"Zoetic", 4750, "Англия", 17},
	{"ACUT", 9750, "Швейцария", 19},
	{"Biocan", 5540, "США", 15}
	};
	int num;
    do {
        print_menu();
        num = get_variant(4);
        switch (num) {
		case 1: {
			std::cout << "Каталог пилюль:\n----------------" << std::endl;
			display(pills);
			std::cout << "Каталог таблеток:\n-----------------" << std::endl;
			display(tablets);
			std::cout << "Каталог вакцины:\n----------------" << std::endl;
			display(vaccine);
			break;
		}
		case 2: {
			int choice, choice2;
			std::cout << "Чтобы вы хотели приобрести (1 - Пилюли, 2 - Таблетки, 3 - Вакцину) >> ";
			std::cin >> choice;
			switch (choice) {
			case 1: {
				display(pills);
				std::cout << "Выберите препарат >> ";
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					add(pills, 0);
					break;
				case 2:
					add(pills, 1);
					break;
				case 3:
					add(pills, 2);
					break;
				default:
					std::cout << "Такого товара нет" << std::endl;
					exit(0);
				}
				break;
			}
			case 2: {
				display(tablets);
				std::cout << "Выберите препарат >> ";
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					add(tablets, 0);
					break;
				case 2:
					add(tablets , 1);
					break;
				case 3:
					add(tablets, 2);
					break;
				default:
					std::cout << "Такого товара нет" << std::endl;
					break;
				}
				break;
			}
			case 3: {
				display(vaccine);
				std::cout << "Выберите препарат >> ";
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					add(vaccine, 0);
					break;
				case 2:
					add(vaccine, 1);
					break;
				case 3:
					add(vaccine, 2);
					break;
				default:
					std::cout << "Такого товара нет" << std::endl;
					break;
				}
				break;
			}
			}
			break;
		}
		case 3: {
			if (summa == 0) {
				std::cout << "Корзина пуста" << std::endl;
			}
			else {
				std::cout << "Сумма вашей корзины составляет - " << summa << " рублей\n" << std::endl;
			}
			break; 
		}
		}
        if (num != 4)
            system("pause");
    } while (num != 4);

    return 0;
}



