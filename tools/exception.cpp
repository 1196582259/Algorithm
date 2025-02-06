#include <exception>
#include <string>

class EmptyContainerException : public std::exception {
private:
    std::string message;
public:
    EmptyContainerException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};