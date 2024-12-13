#ifndef DATA_VALIDATOR_H
#define DATA_VALIDATOR_H

template <typename T>
class DataValidator {
public:
    bool isValid(T value, T min, T max) {
        return value >= min && value <= max;
    }
};

#endif // DATA_VALIDATOR_H
