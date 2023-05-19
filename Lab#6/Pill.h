#pragma once
#include "Medication.h"
#include "Tablet.h"
#include "Vaccine.h"

class Pills : public Medication {
public:
    Pills();
    Pills(std::string, double, std::string);
    void setter() override;
    double get_num() override;
    double get_price() override;
    double cost() override;
    void print() override;
};



