#ifndef CLIMATE_MODEL_H
#define CLIMATE_MODEL_H

#include <vector>

class ClimateModel {
private:
    std::vector<double> temperatures;
    std::vector<double> emissions;
    int startYear;

public:
    ClimateModel();
    void addData(int year, double temperature, double emission);
    double predict(int year) const;
};

#endif // CLIMATE_MODEL_H
