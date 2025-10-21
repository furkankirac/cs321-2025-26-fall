#include <iostream>
#include <vector>
#include <list>


using namespace std;

bool do_it() {
    // ...
    return true;
}


template<typename Container, typename Func>
void transform(Container& container, Func func) {
    for(auto& item : container) {
        item = func(item);
    }
}


int main(int argc, char* argv[])
{
    // v is on the stack
    // v has internal attribute for data pointer
    // 1.1f, 2.2f, 3.3f are alloced in the heap memory
    // internal data ptr, points to that heap block
    auto v = list<float>{1.1f, 2.2f, 3.3f};
    v.push_back(10.10f);

    // v.begin(); // iterator (high level ptr) to the 1st element of v
    // v.end(); // iterator (high level ptr) to the element after the last element of v
    // v.size(); // number of elements in a container

    // 5;

    // for(int i=0; i<v.size(); i++) {
    //     cout << v[i] << endl;
    // }

    for(auto it=v.begin(); it != v.end(); it++) {
        auto& item = *it;
        cout << item << endl;
    }

    for(auto& item : v) {
        cout << item << endl;
    }

    auto what_to_add = 100;
    transform(v, [&](float f) { return f + what_to_add; });
    for(auto& item : v) {
        cout << item << endl;
    }

    // do_it();

    return 0;
}
