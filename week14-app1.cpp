// common pitfalls
// TypeDisplay trick for generic programmer
// lambdas capturing local variables:
//   this includes local parameter packs as well
//
// storing parameter packs: an elegant storage container; get_first, get_size, get_tail impl.

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// struct Blabla {
//     int a;
//     Blabla(const int& a) : a(a) { }
//     auto operator() () const {
//         cout << a << endl;
//     }
// };

auto foo() {
    int a = 10;
    auto lambda = [&a]() {
        cout << a << endl;
    };
    lambda();
    return lambda;
}


// forward declaration
template<typename ...>
struct TypeDisplay;


template<typename T>
void bar() {
    // auto td = TypeDisplay<T, T, T>();

}


void bar_int() {

}

struct mypair {
    int first;
    char second;
};



template<typename T> struct REM_CREF { using type = T; };
template<typename U> struct REM_CREF<const U> { using type = U; };
template<typename U> struct REM_CREF<const U&> { using type = U; };
template<typename U> struct REM_CREF<U&> { using type = U; };

// std::remove_cvref<const int&>::type


template<typename C1, typename C2>
auto zip(const C1& c1, const C2& c2) {
    using ITEM1 = decltype(*c1.begin()); // this is wrong, you need to remove refness at least
    using ITEM2 = decltype(*c2.begin());
    auto sz = c1.size(); // assume bot containers have same length
    using PAIR = std::pair<ITEM1, ITEM2>;

    auto zipped = vector<PAIR>();

    for(auto i=0; i<sz; i++) {
        zipped.push_back(PAIR{c1[i], c2[i]});
    }
    return zipped;
    // auto td = TypeDisplay<ITEM1>();

}


int main() {
    auto v = vector<int> { 1,   2,   3};
    auto k = vector<char>{'a', 'b', 'c'};

    auto vk = zip(v, k);

    for(auto i=0; i<3; i++) {
        cout << v[i] << ", " << k[i] << endl;
    }



    // auto l = foo();
    // l();

    // bar<int>();

    return 0;
}
