// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame


#include <iostream>

using namespace std;

template<int i, int j> struct Multiply { static const int value = i * j; };

template<int i, int j> struct Divide        { static const int value = i / j; };
template<int a>        struct Divide<a, 0>  { static const int value = 0; };

// struct Multiply_3_4 {
//     static const int value = 3 * 4;
// };


// struct Divide_10_0 {
//     static const int value = 0;
// };


// auto div_10_0 = Divide<10, 0>::value;


inline int safe_div(int i, int j) {
    int div;
    if (j == 0)
        div = 0;
    else
        div = i / j;
    return div;
}

int main(int argc, char* argv[])
{
    auto mul_3_4 = Multiply<3, 4>::value;

    auto div_10_2 = Divide<10, 0>::value;
    // auto div_10_2 = 10 / 0;
    cout << div_10_2 << endl;

    // int i = 10;
    // int j = 0;
    // int div;
    // if (j == 0)
    //     div = 0;
    // else
    //     div = i / j;

    auto div = safe_div(10, 0);

    // auto div_0_0 = Divide<0, 0>::value;


    return 0;
}
