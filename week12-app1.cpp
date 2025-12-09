// pair, tuple, std::map
// variadic templates, sizeof... operator, structured binding
// decltype

// we learned 3 main functional algorithms:
// - transform (called "map" in some languages)
// - filter
// - accumulate (called "reduce" in some languages)
// above algorithms are sufficient for representation of all problems
// BUT we need a few other algorithms to facilitate our coding in a packed manner
// we don't want to create a "just enough" set of functional algorithms
// we also want to create a beautiful high-level coding environment as well

// nested for-loops in functional programming paradigm: cartesian_product
// zip/attach algorithm: attaching two or more objects together for making them act as a single sequence

#include <iostream>
#include <string>
#include <unordered_map>
#include <variant>

using namespace std;

template<typename Key, typename Value>
struct Pair {
    Key first;
    Value second;
    // MyPair(int key, const char* value) : key(key), value(value) { }
};

// struct Foo {
//     int v1;
//     float v2;
//     double v3;
//     string v4;
// };


using Foo = std::tuple<int, float, double, string>;

using EitherIntOrDouble = std::variant<int, double>;
// using ANY = std::any;

// template<typename Key, typename Value>
// void print(const std::unordered_map<Key, Value>& m) {
//     cout << "print function for std::map got called" << endl;
//     for (const auto& [key, value] : m) {
//         cout << key << " --> " << value << endl;
//     }
// }

// void print(const auto& m) {
//     cout << "Most generic print got called" << endl;
// }


// template<typename T1, typename T2, typename T3, typename T4>
// void print(T1 v1, T2 v2, T3 v3, T4 v4) {
//     cout << v1 << endl;
//     cout << v2 << endl;
//     cout << v3 << endl;
//     cout << v4 << endl;
// }


// void print() { }

// Ts is called a compile-time parameter pack
// ts is called a run-time parameter pack
template<typename First, typename ... Rest> // First=int Rest=const char*|double|char
inline void print(const First& first, Rest ... rest) { // first=1 rest="hi"|3.14|'c'
    if constexpr(std::is_same<First, int>::value) {
        cout << "Hey this parameter is an integer: ";
    }
    cout << first << endl;

    if constexpr(sizeof...(Rest) > 0)
        print(rest...); // print("hi", 3.14, 'c')

    // ts...; // 1, "hi", 3.14, 'c'

    // cout << v1 << endl;
    // cout << v2 << endl;
    // cout << v3 << endl;
    // cout << v4 << endl;
}


// void print(int i, const char* text, double d, char c) {
//     cout << i << endl;
//     cout << text << endl;
//     cout << d << endl;
//     cout << c << endl;
// }


int main(int, char* [])
{
    int i = 10;
    decltype(i) j = 100;

    // print<int, const char*, double, char>(1, "hi", 3.14, 'c');
    print(1, "hi", 3.14, 'c');

    // const char s[] = "Hi there";
    // auto p = Pair{5, "Hi there"s};

    // auto m = unordered_map<int, string>{
    //     { 5, "five" },
    //     { 10, "ten" },
    //     { 3, "three" },
    //     { -100, "minus hundred" }
    // };

    // m[200] = "two hundred";

    // // cout << m[10] << endl;
    // print(m);

    return 0;
}
