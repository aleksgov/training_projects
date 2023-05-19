#include "Quantity.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double quantity;
    zadanie();
    std::cout << "Введите количество информации (в байтах) >> ";
    std::cin >> quantity;

    QuantityOfInformation val1(quantity);
    std::cout << "value" << std::endl
        << "bytes: " << std::fixed << std::setprecision(1) << val1.get_bytes() << std::endl
        << "bit: " << std::fixed << std::setprecision(1) << val1.convert_to_bit() << std::endl
        << "kilobytes: " << std::fixed << std::setprecision(3) << val1.convert_to_kilobytes() << std::endl
        << "megabytes: " << std::fixed << std::setprecision(6) << val1.convert_to_megabytes() << std::endl
        << "gigabytes: " << std::fixed << std::setprecision(9) << val1.convert_to_gigabytes() << std::endl
        << "terabytes: " << std::fixed << std::setprecision(12) << val1.convert_to_terabytes() << std::endl
        << std::endl;

    QuantityOfInformation val2;
    std::cout << "defult value" << std::endl
        << "bytes: " << std::fixed << std::setprecision(1) << val2.get_bytes() << std::endl
        << "bit: " << std::fixed << std::setprecision(1) << val2.convert_to_bit() << std::endl
        << "kilobytes: " << std::fixed << std::setprecision(3) << val2.convert_to_kilobytes() << std::endl
        << "megabytes: " << std::fixed << std::setprecision(6) << val2.convert_to_megabytes() << std::endl
        << "gigabytes: " << std::fixed << std::setprecision(9) << val2.convert_to_gigabytes() << std::endl
        << "terabytes: " << std::fixed << std::setprecision(12) << val2.convert_to_terabytes() << std::endl
        << std::endl;

    QuantityOfInformation temp(0);

    std::cout << "(val1 += val1) == ";
    temp += val1;
    temp = temp + val1;
    std::cout << std::fixed << std::setprecision(1) << temp.get_bytes() << std::endl;
    temp.SetBytes(100000);

    std::cout << "(val2 -= val1) == ";
    temp -= val1;
    std::cout << std::fixed << std::setprecision(1) << temp.get_bytes() << std::endl;
    temp.SetBytes(1);

    std::cout << "(val1 *= val1) == ";
    temp *= val1;
    temp = temp * val1;
    std::cout << std::fixed << std::setprecision(1) << temp.get_bytes() << std::endl;
    temp.SetBytes(100000);

    std::cout << "(val2 / val1) == ";
    temp /= val1;
    std::cout << std::fixed << std::setprecision(1) << temp.get_bytes() << std::endl << std::endl;

    std::cout << "val1 < val2 " << (val1 < val2) << std::endl
        << "val1 > val2 " << (val1 > val2) << std::endl
        << "val1 <= val2 " << (val1 <= val2) << std::endl
        << "val1 >= val2 " << (val1 >= val2) << std::endl
        << "val1 != val2 " << (val1 != val2) << std::endl
        << "val1 == val2 " << (val1 == val2) << std::endl;

    return 0;
}
