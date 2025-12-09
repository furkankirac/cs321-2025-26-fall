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
// zip algorithm: attaching two or more objects together for making them act as a single sequence

#include <iostream>
#include <vector>

using namespace std;

auto cartesian_product(const auto& cont1, const auto& cont2, const auto& func) {
    for(const auto& item1 : cont1)
        for(const auto& item2 : cont2)
            func(item1, item2);
}


int main(int argc, char* argv[])
{
    auto v1 = vector<int>{1, 2, 5};
    auto v2 = vector<int>{10, 20, 30, 40};

    for(const auto& item1 : v1)
        for(const auto& item2 : v2)
            cout << item1 << ", " << item2 << endl;

    return 0;
}
