#include <iostream>
#include <vector>

using namespace std;

// increment and decrement for ints
int increment(int i) { return i + 1; }
int decrement(int i) { return i - 1; }

// increment and decrement for floats
float increment_float(float i) { return i + 1; }
float decrement_float(float i) { return i - 1; }


// function pointer for all functions that take one int and return int
using ONE_INTER = int (*)(int);

// function pointer for all functions that take one float and return float
using ONE_FLOATER = float (*)(float);

// generic print function for all T types on vector<T>
template<typename T>
void print(vector<T>& k) {
    auto sz = k.size();
    for(int i=0; i<sz; i++) {
        cout << k[i] << ", ";
    }
    cout << endl;
}

// global variable hack for injecting an extra variable (called "what" here)
float what;

// increment_by_k uses global what
// and relies on the caller of this function
// to first initialize "what"
float increment_by_k(float i) { return i + what; }
float decrement_by_k(float i) { return i - what; }

// FUNCTION OBJECT
// for combining the essential auxilary stuff with the business logic
// auxilary stuff is the "what" attribute
// business logic is "float operator() (float i) { return i + what; }" part
// operator() is the function call operator in overloaded form
// this allows anyone to call the instance of an Adder as if it's a function
struct Adder {
    float what;

    Adder(float what) : what(what) { }
    float operator() (float i) { return i + what; }
};

// Generic for_each function for vector<T>'s all elements one by one
template<typename T>
// takes the vector<T> container and an extra function object
// for the time being that function object is fixed as Adder
// we'll improve on that
void for_each(vector<T>& v, Adder adder) {
    auto sz = v.size();
    for(int i=0; i<sz; i++) {
        // v[i] = adder.run(v[i]);
        v[i] = adder(v[i]);
        // cout << v[i] << ", ";
    }
}


int main(int argc, char* argv[])
{
    auto v = vector<float>{1, 2, 3, 10, 20, -5, 6, 7};
    print<float>(v);

    auto adder = Adder(-15);

    what = 15;
    for_each(v, adder);
    print<float>(v);

    // ONE_INTER func_ptr = &increment;

    // auto result = increment(10);
    // auto result = (*func_ptr)(10);

    // if(input == 1) {
    //     func_ptr = &incrment;
    // } else if (input == 2) {
    //     func_ptr = &decrement;
    // }


    // auto result = func_ptr(10);

    // func_ptr = &decrement;
    // auto result2 = func_ptr(10);

    // cout << result << endl;
    // cout << result2 << endl;

    // void* is a memory pointer, points to memory and we don't know what it is there
    return 0;
}
