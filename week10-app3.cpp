// IsSame

#include <iostream>
#include <vector>

using namespace std;


template<typename T1, typename T2> struct IsSame       { static constexpr bool value = false; };
template<typename T>               struct IsSame<T, T> { static constexpr bool value = true; };


template<typename T1, typename T2>
constexpr bool isSameType() {
    return IsSame<T1, T2>::value;
}

int main(int argc, char* argv[])
{

    // if constexpr(isSameType<int, float>())
    //     cout << "They are of the same type" << endl;

    if constexpr(IsSame<int, float>::value)
        cout << "They are of the same type" << endl;


    return 0;
}
