#pragma once
#include "Medication.h"

class Tablets : public Medication {
public:
    Tablets();
    Tablets(std::string, double, std::string);
    void setter() override;
    double cost() override;
    double get_price() override;
    double get_num() override;
    void print() override;
};
