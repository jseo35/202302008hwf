#include <iostream>
#include "DataValidator.h"
#include "ExceptionHandler.h"
#include "ClimateModel.h"

using namespace std;

int main() {
    try {
        ClimateModel model;
        double inputTemperature, inputEmission;
        DataValidator<double> validator;

        while (true) {
            cout << "2024년 예상 연평균 기온을 입력하세요 : ";
            cin >> inputTemperature;
            cout << "2024년 예상 온실가스 배출량을 입력하세요 : ";
            cin >> inputEmission;

            if (!validator.isValid(inputTemperature, 10.0, 20.0) ||
                !validator.isValid(inputEmission, 290.0, 900.0)) {
                cout << "입력하신 값이 비정상적으로 크거나 작습니다. 다시 입력하시려면 : 1, 종료하시려면 : 0" << endl;
                int choice;
                cin >> choice;
                if (choice == 0) {
                    cout << "프로그램을 종료하겠습니다." << endl;
                    return 0;
                }
                continue;
            }

            model.addData(2024, inputTemperature, inputEmission);
            double predictedTemperature = model.predict(2025);
            cout << "2025년도의 기온 예측 결과는 " << predictedTemperature << "°C 입니다." << endl;
            break;
        }
    } catch (const runtime_error& e) {
        cerr << "오류 발생: " << e.what() << endl;
    }

    return 0;
}
