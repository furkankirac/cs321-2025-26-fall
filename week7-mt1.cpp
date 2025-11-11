#include <iostream>

enum TempUnit { Celsius = 1, Fahrenheit = 2 };

struct Temperature {
    float value;
    TempUnit unit;
    Temperature(float v, TempUnit u) : value(v), unit(u) { }
};

Temperature* toFahrenheit(Temperature& temp) {
    if (temp.unit == Celsius) {
        auto f = (temp.value / 5) * 9 + 32;
        auto* p = new Temperature(f, Fahrenheit);
        // draw memory layout here, just before return
        return p;
    }
    return &temp;
}

void Q1_main() {
    Temperature t1 = Temperature(25, Celsius);
    Temperature* t2 = toFahrenheit(t1);
    // draw memory layout when code arrives here, just before executing cout
    std::cout << t2->value << " Fahrenheit" << std::endl;
    delete t2;
}

// Write a function object that stores how many times it will call a function
// from a family of functions that gets a single argument as int,
// does something with that int and then returns a float.

// Q2a
using INT_TO_FLOAT_FUNCS = float (*)(int);
struct FunctionObject {
    int times;
    INT_TO_FLOAT_FUNCS func;
    FunctionObject(int times, INT_TO_FLOAT_FUNCS func) : times(times), func(func) {}
    void operator() () const {
        for(int i=0; i<times; i++)
            func(i);
    }
};

// Q2b
float func(int a) {
    return (float)a * 3.14f;
}

void Q2c_d() {
    auto fo = FunctionObject(3, &func);
    fo();
}


// Q3abc
template<typename T>
struct Temp {
    T value;
    TempUnit unit;
    Temp(T v, TempUnit u) : value(v), unit(u) { }

    Temp toFahrenheit() {
        if (this->unit == Celsius) {
            auto f = (this->value / 5) * 9 + 32;
            return Temp(f, Fahrenheit);
        }
        return *this;
    }
};

// Q3d
int main(int argc, char* argv[])
{
    auto t1 = Temp<float>(25, Celsius);
    auto t2 = t1.toFahrenheit();
    std::cout << t2.value << " Fahrenheit" << std::endl;
}
