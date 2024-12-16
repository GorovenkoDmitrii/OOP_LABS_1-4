#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
using namespace std;
class Error {
public:
    virtual string what() const = 0;
    virtual ~Error() {}
};
class MemoryAccessError : public Error {
public:
    string what() const override {
        return "Memory access error";
    }
};
class MathError : public Error {
public:
    string what() const override {
        return "Mathematical error";
    }
};
class DivisionByZeroError : public MathError {
public:
    string what() const override {
        return "Division by zero error";
    }
};
class OverflowError : public MathError {
public:
    string what() const override {
        return "Overflow error";
    }
};
// Функция для сложения с проверкой на переполнение
int safe_add(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        throw overflow_error("Overflow occurred during addition");
    }
    return a + b;
}
template <typename T>
class PointerArray {
private:
    T** array;
    size_t size;
public:
    PointerArray(size_t size) : size(size) {
        array = new T * [size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = nullptr;
        }
    }
    ~PointerArray() {
        for (size_t i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;
    }
    T*& operator[](size_t index) {
        if (index >= size) throw out_of_range("The index is out of range");
        return array[index];
    }
    size_t getSize() const {
        return size;
    }
};
int main() {
    try {
        int result = safe_add(INT_MAX, 1);// Это вызовет исключение overflow_error
        PointerArray<Error> errorArray(3);
        errorArray[0] = new MemoryAccessError();
        errorArray[1] = new DivisionByZeroError();
        errorArray[2] = new OverflowError();
        for (size_t i = 0; i < errorArray.getSize(); ++i) {
            cout << errorArray[i]->what() << endl;
            delete errorArray[i];
            errorArray[i] = nullptr;
        }
    }
    catch (const overflow_error& e) { 
        cerr << "Overflow Exception: " << e.what() << endl; // Обработка вырадженного исключения overflow_error
    }
    catch (const exception& e) { 
        cerr << "Exception: " << e.what() << endl; // Обработка других исключений
    }
}