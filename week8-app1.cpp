// overview of encapsulating functions (OOP):
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// GENERATORS (Coroutines): appropriate for functional programming
// Fibonacci Generator as a function object
// - with generator logic (coroutines)
// - with functions
// - with (mutable) lambdas

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm

#include <iostream>

using namespace std;

// 0, 1, 1, 2, 3, 5, 8, ...

struct FibonacciGenerator {
    int& a;
    int& b;
    // FibonacciGenerator() : a(0), b(1) { }
    FibonacciGenerator(int& m, int& n) : a(m), b(n) { }

    int operator() (/* FibonacciGenerator* this */) {
        auto c = a + b;
        // yield c;
        this->a = b;
        this->b = c;
        return c;
    }

};

// int get_next_value( FibonacciGenerator* ptr ) {

// }

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 1;

    // auto fg = FibonacciGenerator(m, n);
    // for(int i=0; i<5; i++) {
    //     // auto next_value = fg.get_next_value();
    //     auto next_value = fg();
    //     // auto next_value = fg.operator() ();
    //     cout << next_value << endl;
    // }

    {
        auto fg_lambda = [&a, b]() mutable {
            auto c = a + b;
            a = b;
            b = c;
            return c;
        };
        for(int i=0; i<5; i++) {
            auto next_value = fg_lambda();
            cout << next_value << endl;
        }
    }

    cout << "Values of a and b are " << a << ", " << b << endl;

    return 0;
}
