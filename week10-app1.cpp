// static keyword

// pure functions != free functions --> functions that have no side-effect
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it
// from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame, ConditionalType
// constexpr, if constexpr


#include <iostream>

using namespace std;

// struct Dummy {
//     static int a;
// };


void func() {
    static int a = 0;
    cout << a << endl;
    a++;
}

struct FuncObj {
    int a = 0;

    // ~FuncObj() { }

    auto operator() (/* FuncObj* this */ ) {
        cout << a << endl;
        a++;
    }
};

int mul_10_3 = 30;
int mul_5_2 = 10;

template<int i, int j>
struct Multiply {
    static const int value = i * j;
};


// constexpr int mul(int i, int j) {
//     return i * j;
// }


int main(int argc, char* argv[])
{
    // cout << mul_10_3 << endl;

    // func();
    // func();

    // {
    //     auto funcobj = FuncObj();
    //     // funcobj.operator()();
    //     funcobj();
    //     funcobj();
    // }

    // {
    //     auto funcobj = FuncObj();
    //     // funcobj.operator()();
    //     funcobj();
    //     funcobj();
    // }

    int product = 10 * 3;

    int k = Multiply<10, 3>::value;
    int m = Multiply<5, 2>::value;

    cout << k << endl;
    cout << m << endl;

    return 0;
}
