// lambdas capturing local variables:
//   this includes local parameter packs as well
//
// storing parameter packs: an elegant storage container;
// get_first, get_size, get_tail impl.

// standard library of c++ (v2) is named as std::ranges


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// struct Blabla {
//     int i;
//     char c;
//     double d;
//     string s;
//     auto operator() ( ... ) {

//     }
// };

// Ts = compile-time parameter pack
template<typename ... Ts> // Ts=int|char|double|string
auto mylist(const Ts& ... ts) { // ts=1|'c'|3.4|"hello"s
    return [ts...](auto accessor) {
        return accessor(ts...);
    };
}

auto get_first() {
    return [](const auto& first, const auto& ...) {
        return first;
    };
}

auto get_tail() {
    return [](const auto&, const auto& ... rest) {
        return mylist(rest...);
    };
}


int main() {

    auto l = mylist(10, 'c', 3.4, string("hello"));

    auto first_item = l(get_first());
    cout << first_item << endl;

    auto l2 = l(get_tail());
    auto another_item = l2(get_first());
    cout << another_item << endl;

    // cout << 10 << endl;
    // cout << 'c' << endl;


    return 0;
}
