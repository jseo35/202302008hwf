#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include <exception>
#include <string>

class ExceptionHandler : public std::exception {
private:
    std::string message;

public:
    explicit ExceptionHandler(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // EXCEPTION_HANDLER_H
