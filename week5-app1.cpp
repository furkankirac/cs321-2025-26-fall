// encapsulating functions:
//   1) functions themselves (with func pointers),
//   2) function objects (a struct with operator() overloaded)
//   3) lambda functions

// generic "transform" algorithm for all items on a container

// iterators and range-for-loop

// unified/universal construction:
//   stricter construction with {} instead of (),
//   copy constructor
//   copy assignment
//   initializer_list support for ctors

#include <iostream>
#include <vector>

using namespace std;

struct FunctionObject {
    int coef;

    FunctionObject() : coef() { } // default c-tor
    FunctionObject(int coef) : coef(coef) { } // default c-tor

    FunctionObject(float) { }

    void run (/* const FunctionObject* this */) const {
        cout << "Hello " << coef << endl;
    }

    void operator() () {
        cout << "Hello " << coef << endl;
    }
};

void FunctionObject_run (const FunctionObject* ptr) {
    cout << "Hello " << ptr->coef << endl;
}


struct Adder {
    int add_what;

    Adder(int value) : add_what(value) {}

    int operator() (int value) { return value + add_what; }
};

int main(int argc, char* argv[])
{
    auto fo_1 = FunctionObject();
    auto fo_2 = FunctionObject(5);

    // auto* ptr = &fo_1;
    // ptr->run();
    fo_1.run();
    FunctionObject_run(&fo_1);

    fo_2.run();
    FunctionObject_run(&fo_2);

    fo_1.operator() ();
    fo_2.operator() ();

    fo_1();
    fo_2();

    auto add10 = Adder(10);
    cout << add10(25) << endl;

    auto minus5 = Adder(-5);
    cout << minus5(4) << endl;


    struct XYZ {
        int add_what;

        XYZ(int value) : add_what(value) {}

        int operator() (/* const XYZ* this  ,*/ int value) const {
            // add_what = 100;
            return value + add_what;
        }
    };
    auto minus5_lambda_ = XYZ(5);

    // below lambda is equivalent to above code
    auto minus5_lambda = [add_what=5] (int value) mutable {
        add_what = 100;
        return value - add_what;
    };


    cout << minus5_lambda(4) << endl;

    return 0;
}
