#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum SortOrder { ASC = 0, DESC = 1 };

void sort(auto& c, SortOrder so) {
    auto conditional_negate = [so](bool b) { return so == ASC ? b : !b; };
    auto swapped = true;
    while (swapped) {
        swapped = false;
        for (auto j=c.begin(); j!=c.end()-1; j++) {
            if ( conditional_negate(*(j+1) < *j) ) {
                swapped = true;
                std::swap(*j, *(j+1));
            }
        }
    }
}

auto sorter(SortOrder so) {
    return [so](const auto& c) { auto c2 = c; sort(c2, so); return c2; };
}

template<SortOrder so>
auto sorter() {
    return [](const auto& c) { auto c2 = c; sort(c2, so); return c2; };
}

template<typename First, typename ... Rest>
auto concat_as_vector_impl(auto& c, const First& first, const Rest& ... rest) {
    if constexpr (is_same<First, int>::value) {
        c.push_back(first);
    } else {
        for (const auto& item : first)
            c.push_back(item);
    }
    if constexpr (sizeof...(Rest) > 0) {
        concat_as_vector_impl(c, rest...);
    }
    return c;
}


template<typename T>
auto concat_as_vector(const auto& ... Ts) {
    auto c = vector<T>{};
    return concat_as_vector_impl(c, Ts...);
}

auto print(const auto& c) {
    for (const auto& item : c)
        std::cout << item << " ";
    std::cout << endl;
    return c;
}

auto printer() {
    return [](const auto& c) { return print(c); };
}

auto operator|(const auto& f1, const auto& f2) {
    return [f1, f2](auto& item) {
        return f2(f1(item));
    };
}

struct PowerSequence {
    int a;
    int pow;
    int value;
    PowerSequence(int a) : a(a), pow(0), value(1) { }
    int operator()() {
        auto r = value;
        value *= a;
        return r;
    }
};

auto ps_lambda = [a=3, pow=2, value=9]() mutable {
    auto r = value;
    value *= a;
    return r;
};

int main(int argc, char* argv[])
{
    // Q1a (20 pts): Implement PowerSequence function object
    auto ps = PowerSequence(2);
    for(int i=0; i<6; i++)
        cout << ps() << " ";
    cout << endl;
    // 1, 2, 4, 8, 16, 32

    // Q1b (10 pts): Implement ps_lambda lambda function
    for(int i=0; i<6; i++)
        cout << ps_lambda() << " ";
    cout << endl;
    // 9 27 81 243 729 2187

    // Q2 (25 pts): implement concat_as_vector_impl function
    auto v = concat_as_vector<double>(vector{12, 144}, list{1, 0}, -1);
    // std::vector<double>{12, 144, 1, 0, -1} instance is returned

    // below code already given to you
    auto v_copy = v;
    print(v_copy); // 12 144 1 0 -1
    sort(v_copy, DESC); // v_copy gets descending sorted, v_copy content changes
    print(v_copy); // 144 12 1 0 -1

    // Q3: write code for solving below
    // a) (10 pts) overload | operator for composing two functions
    // b) (10 pts) printer() higher order function
    // c) (15 pts) sorter(so) higher order function with run-time SortOrder
    // d) (10 pts) sorter<SortOrder> higher order function with compile-time SortOrder
    auto pipe1 = printer() | sorter(DESC) | printer();
    auto pipe2 = printer() | sorter<ASC>() | printer();

    pipe1(v);
    // 12 144 1 0 -1
    // 144 12 1 0 -1

    pipe2(v);
    // 12 144 1 0 -1
    // -1 0 1 12 144

    return 0;
}
