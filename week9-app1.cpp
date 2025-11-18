// in search of a simpler and more understandable generic way of writing code
//  the dance of OOP, FP and GP paradigms

// lifting a function (higher order functions):
//  a function returning a function object: delays function use
// less_than(x), greater_than(x), get_name(), ...

// composing functions

// filter algorithm

// extra generic algorithms on containers

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string name;
    double price;
};


template<typename T>
auto get_price_worker(const T& item) {
    return item.price;
}

auto get_price() {
    return []<typename T>(const T& item) {
        return get_price_worker<T>(item);
        // return item.price;
    };
}


auto less_than_worker(double value, double from_what) {
    return value < from_what;
}

auto less_than(auto from_what) {
    return [from_what](double value) {
        return less_than_worker(value, from_what);
    };
}

auto compose(auto f, auto g) {
    return [f, g](const auto& item) {
        return g(f(item));
    };
}
// auto composed_function = compose(get_price(), less_than(10));

auto operator| (auto f, auto g) {
    return compose(f, g);
}


template<typename Container>
auto filter(const Container& container, auto filtering_func) {
    auto new_cont = Container();
    for(const auto& item : container) {
        if (filtering_func(item)) {
            new_cont.push_back(item);
        }
    }
    return new_cont;
}


auto get_printer() {
    return [](const auto& item) {
        cout << item << endl;
        return item;
    };
}


int main(int argc, char* argv[])
{
    auto v = vector<Book>{
        {"Harry Potter", 9.95},
        {"Lord of the Rings", 19.95},
        {"Robinson Crusoe", 15.0}
    };

    auto& lotr = v[1];

    auto price_getter = get_price();

    // cout << price_getter(lotr) << endl;

    auto less_than_10_middleware = less_than(10);
    // cout << less_than_10_middleware(5) << endl;

    auto new_cont = filter(v,
        get_price() | get_printer() | less_than(10) | get_printer()
    );


    return 0;
}
