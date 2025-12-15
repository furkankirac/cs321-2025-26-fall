#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using XY = pair<int, int>;

auto cartesian_product(const auto& cont1, const auto& cont2, const auto& func) {
    for(const auto& item1 : cont1)
        for(const auto& item2 : cont2)
            func(item1, item2);
}

template<typename T>
inline void print_impl(const T& item) {
    if constexpr (is_same<T, XY>::value) {
        const auto& [x, y] = item;
        cout << "(" << x << ", " << y << ")";
    } else {
        cout << item;
    }
}

template<typename First, typename ... Rest>
inline void print(const First& first, const Rest& ... rest) {
    print_impl(first);
    if constexpr (sizeof...(rest) > 0)
        print(rest...);
}

template<typename T1, typename T2>
auto zip(const vector<T1>& c1, const vector<T2>& c2) {
    auto cont_new = vector<std::pair<T1, T2>>{};
    auto sz = c1.size(); // assume all have the same size
    for(int i=0; i<sz; i++) {
        cont_new.push_back(std::pair{c1[i], c2[i]});
    }
    return cont_new;
}

// we need First exclusively declared below just for using first.size()
// if we had another way of getting the size from a parameter pack
// we could have written below algorithm in a neater way without any First
// but only with template <typename ... Ts>
// that's for advanced cpp course
template<typename First, typename ... Rest>
auto zip_variadic(const vector<First>& first, const vector<Rest>& ... rest) {
    auto cont_new = vector<std::tuple<First, Rest...>>{};
    auto sz = first.size();
    for(int i=0; i<sz; i++) {
        cont_new.push_back(std::tuple{first[i], rest[i]...});
    }
    return cont_new;
}


int main(int argc, char* argv[])
{
    auto v1 = vector<XY>{{1,0}, {2, 2}, {5, -1}};
    auto v2 = vector<int>{10, 20, 30, 40};
    auto v3 = vector<double>{1.1, 2.2, 3.3, 4.4};
    auto v4 = vector<char>{'A', 'B', 'C', 'D'};

    cartesian_product(v1, v2, [](const auto& i1, const auto& i2) {
        print(i1, ", ", i2);
        cout << endl;
    });
    // outputs
    // (1, 0), 10
    // (1, 0), 20
    // (1, 0), 30
    // (1, 0), 40
    // (2, 2), 10
    // (2, 2), 20
    // (2, 2), 30
    // (2, 2), 40
    // (5, -1), 10
    // (5, -1), 20
    // (5, -1), 30
    // (5, -1), 40

    for (const auto& item : zip(v2, v3)) {
        print(item.first, ", ", item.second, '\n');
    }
    // outputs:
    // 10, 1.1
    // 20, 2.2
    // 30, 3.3
    // 40, 4.4

    for (const auto& [a, b, c] : zip_variadic(v2, v3, v4)) {
        print(a, ", ", b, ", ", c, '\n');
    }
    // outputs:
    // 10, 1.1, A
    // 20, 2.2, B
    // 30, 3.3, C
    // 40, 4.4, D

    // We could have used zip_variadic in place of zip algorithm from now on
    // zip_variadic also handles the 2 container inputs already

    return 0;
}
