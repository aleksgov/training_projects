#pragma once
#include "Medication.h"

class Vaccine : public Medication {
public:
    Vaccine();
    Vaccine(std::string, double, std::string);
    void setter() override;
    double cost() override;
    double get_price() override;
    double get_num() override;
    void print() override;
};
