// Higher Order Functions: reverse, filter, take<x>, transform, accumulate algorithms
// "and(...)" predicate

// C++ concepts, requires expression
// IsContainer<T>, IsPushable<T>

#include <iostream>
#include <vector>
#include <list>

using namespace std;

auto print_(int value) {
    cout << value << endl;
    return value;
}

auto print_(const auto& container) {
    for(const auto& item : container) {
        cout << item << ", ";
    }
    cout << endl;
    return container;
}

auto print() {
    return [](const auto& whatever) {
        return print_(whatever);
    };
}


// HW: make this algo use iterators
auto reverse_(auto new_cont) {
    auto sz = new_cont.size();
    for(int i=0; i<sz/2; i++) {
        std::swap(new_cont[i], new_cont[sz-i-1]); // HW: write your own swap function
        // auto t = new_cont[i];
        // new_cont[i] = new_cont[sz-i-1];
        // new_cont[sz-i-1] = t;
    }
    return new_cont;
}

auto reverse() {
    return [](const auto& container) {
        return reverse_(container);
    };
}

inline bool higher_than_(auto a, auto b) { return a > b; }
auto higher_than(auto b) {
    return [b](auto a) {
        return higher_than_(a, b);
    };
}

inline bool less_than_(auto a, auto b) { return a < b; }
auto less_than(auto b) {
    return [b](auto a) {
        return less_than_(a, b);
    };
}


auto AND_(auto value, auto func1, auto func2) {
    return func1(value) && func2(value);
}

auto AND(auto func1, auto func2) {
    return [func1, func2](auto value) {
        return AND_(value, func1, func2);
    };
}

template<typename Container>
auto filter_(const Container& container, auto func) {
    auto new_cont = Container();
    for(const auto& item : container) {
        if (func(item)) {
            new_cont.push_back(item);
        }
    }
    return new_cont;
}

auto filter(auto func) {
    return [func](const auto& container) {
        return filter_(container, func);
    };
}


template<int sz, typename Container>
auto take_(const Container& container) {
    auto new_cont = Container();
    auto SZ = container.size();
    if (sz < SZ)
        SZ = sz;
    for(int i=0; i<SZ; i++) {
        new_cont.push_back(container[i]); // HW: convert to iterators
    }
    return new_cont;
}

template<int sz>
auto take() {
    return [](const auto& container) {
        return take_<sz>(container);
    };
}


auto transform_(auto new_cont, auto func) {
    for(auto& item : new_cont) {
        item = func(item);
    }
    return new_cont;
}

auto transform(auto func) {
    return [func](const auto& container) {
        return transform_(container, func);
    };
}

inline auto add_(auto a, auto b) {
    return a + b;
}

auto add(auto b) {
    return [b](auto a) {
        return add_(a, b);
    };
}



auto operator| (const auto& left, const auto& right) {
    return right(left);
}


int main(int, char* [])
{
    using CONTAINER = std::vector<float>;

    // print()(5);

    // print() (CONTAINER{1.1, 50.3, -3, 5, -10, 100});

    CONTAINER{1.1, 50.3, -3, 5, -10, 100}
        | print()
        | reverse()
        | print()
        | filter(AND(higher_than(-5), less_than(60)))
        | print()
        | take<2>()
        | print()
        | transform(add(2))
        | print()
        // HOMEWORK BELOW:
        // | accumulate(multiplier(), 1.0f)
        // | print()
        ;

    return 0;
}
