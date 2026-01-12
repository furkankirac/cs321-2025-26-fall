#include <iostream>

using namespace std;

enum GeoPrimitive { Square, Circle };

// Q4a) (10 pts) implement “areaOf<T>” higher order function
// and necessary “enum”.
template<GeoPrimitive gp>
auto areaOf() {
    if constexpr (gp == Square) {
        return [](const auto side) {
            return side * side;
        };
    } else if constexpr (gp == Circle) {
        return [](const auto radius) {
            return 3.14 * radius * radius;
        };
    }
}

// Q2 (25 pts): Implement “multiply_by” higher order function
// • DON’T use lambda function. Implement the function
//     object manually. If not, you’ll get zero points.
// • (10 pts) multiply_by must allow being constructed with
//   an unknown (auto) value.
// • (5 pts) it must also be compatible with an unknown (auto)
//   input type that will arrive in the future.
// • (10 pts) rest of it.
template<typename T>
struct MultiplyBy {
    T value;
    MultiplyBy(T value) : value(value) { }

    template<typename U>
    auto operator() (U input) const {
        return input * value;
    }
};

auto multiply_by(auto value) {
    return MultiplyBy(value);
}

// Q4b) (10 pts) implement “printer” higher order function
auto printer() {
    return [](const auto& item) {
        cout << item << endl;
        return item;
    };
}

// Q4c) (10 pts) implement overloading of “operator |”
auto operator|(const auto& f, const auto& g) {
    return [f, g](const auto& x) {
        return g(f(x));
    };
}

// Q3 (25 pts): implement “junction” higher order function.
auto junction(auto pipe1, auto pipe2) {
    return [=](const auto& input) {
        pipe1(input);
        pipe2(input);
        return input;
    };
}

auto run(auto input) {
    static bool init = false;
    double value;
    if (!init) {
        init = true;
        auto parallel_pipe = junction(
            areaOf<Circle>() | printer(),
            multiply_by(2) | areaOf<Square>() | printer()
            );

        value = parallel_pipe(input);
    }

    // Q1) draw memory layout for only the alive variables
    // when the program reaches this line for the 2nd time
    // Answer:
    // Static/Global memory at left of logical memory space
    // - boolean init variable that is set to true
    // No Heap allocation
    // Stack Memory
    // - int argc
    // - char* argv[]
    // - double value (of main function)
    // - Stack Pointer (SP) saved
    // - Program Counter (PC) saved
    // - New SP points to stack frame start of run function
    // - "auto input" is deduced as "int input" (called with 3)
    //   hence, we have int input variable set to 3
    // - double value (of run function)
    // parallel_pipe variable is out of scope (no need to indicate)
    return value;
}

int main(int argc, char *argv[])
{
    double value;
    value = run(3);
    value = run(3);

    return 0;
}
