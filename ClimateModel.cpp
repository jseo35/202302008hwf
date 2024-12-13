#include "ClimateModel.h"
#include <numeric>
#include <stdexcept>

ClimateModel::ClimateModel() : startYear(1990) {
    temperatures = {12.8, 12.0, 12.2, 11.6, 13.0, 11.7, 11.8, 12.4, 13.2, 12.5, 12.2, 12.4, 12.4, 12.2, 12.9, 12.1, 12.6, 13.0, 12.7, 12.7, 12.4, 12.1, 12.1, 12.6, 12.8, 13.1, 13.4, 12.8, 12.8, 13.3, 13.0, 13.3, 12.9, 13.7};
    emissions = {292.1, 315.4, 343.4, 378.5, 403.6, 433.8, 470.3, 501.9, 431.4, 469.4, 502.7, 516.0, 538.5, 548.8, 557.0, 561.5, 566.9, 580.2, 593.5, 597.3, 655.1, 683.8, 687.0, 695.7, 690.8, 691.3, 692.4, 709.4, 725.0, 699.2, 654.4, 676.6, 654.5, 624.2};
}

void ClimateModel::addData(int year, double temperature, double emission) {
    temperatures.push_back(temperature);
    emissions.push_back(emission);
}

double ClimateModel::predict(int year) const {
    if (temperatures.empty() || emissions.empty())
        throw std::runtime_error("데이터가 부족합니다.");

    double xSum = std::accumulate(emissions.begin(), emissions.end(), 0.0);
    double ySum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double xMean = xSum / emissions.size();
    double yMean = ySum / temperatures.size();

    double numerator = 0.0, denominator = 0.0;
    for (size_t i = 0; i < emissions.size(); ++i) {
        numerator += (emissions[i] - xMean) * (temperatures[i] - yMean);
        denominator += (emissions[i] - xMean) * (emissions[i] - xMean);
    }

    double slope = numerator / denominator;
    double intercept = yMean - slope * xMean;
    double futureEmission = emissions.back();
    return slope * futureEmission + intercept;
}
