#include <iostream>
#include <vector>

using namespace std;

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm

// template<typename Container>
void print(auto& v) {
    for(const auto& item : v) {
        cout << item << ", ";
    }
    cout << endl;
}


void transform_inline(auto& container, const auto& func) {
    for(auto it = container.begin(); it != container.end(); it++) {
        auto& item = *it;
        item = func(item);
    }
}

template<typename Container>
Container transform(const Container& container, const auto& func) {
    auto new_cont = Container();
    for(auto it = container.begin(); it != container.end(); it++) {
        auto& item = *it;
        new_cont.push_back(func(item));
    }
    return new_cont;
}

auto accumulate(const auto& container, const auto& func, auto initial_value) {
    auto accumulator = initial_value;
    for(const auto& item : container) {
        accumulator = func(accumulator, item);
    }
    return accumulator;
}


int main(int argc, char* argv[])
{
    auto v = vector<float>{1.1f, 2.2f, 3.3f};

    print(v);
    // transform_inline(v, [](float& item) { return item * 10; });
    auto multiply_by_10 = [](const float& item) { return item * 10; };

    auto new_cont = transform(v, multiply_by_10);
    print(new_cont);

    // auto sum = 0;
    // for(const auto& item : new_cont) {
    //     sum += item;
    // }
    auto sum = accumulate(new_cont, [](auto acc, auto item) {
        return acc + item;
    }, 0.0f);
    cout << "Sum of new_cont items is " << sum << endl;

    // auto product = 1;
    // for(const auto& item : new_cont) {
    //     product *= item;
    // }
    auto product = accumulate(new_cont, [](auto acc, auto item) {
        return acc * item;
    }, 1.0f);
    cout << "Product of new_cont items is " << product << endl;


    return 0;
}
