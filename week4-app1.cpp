// operators, [] operator and operator overloading

// function pointers
// for_each

// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with caller via c-tors, assignment operators, and casting
// ctor/dtor
// implicit/explicit constructors
// copy-ctor, copy-assignment
// casting
// inheritance (will discuss later)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference

// operator== and operator+ overloads for Celsius/Fahrenheit

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Vector {
private:
    int num_dims; // 4 bytes in my arch.
    T* data;      // 8 bytes in my arch.

public:
    Vector(int num_dims) : num_dims(num_dims), data(new T[num_dims]) {
        for(int i=0; i<num_dims; i++) {
            this->data[i] = i * 1.1f;
        }
    }

    ~Vector() {
        delete[] this->data;
    }

    void print_vector(/*IntVector* iv*/) {
        auto sz = this->num_dims;
        for(int i=0; i<sz; i++) {
            cout << this->data[i] << ", ";
        }
        cout << endl;
    }

    T operator[](int index) {
        if(index < 0 || index >= this->num_dims) {
            // shout
        }
        return this->data[index];
    }

};

// void print_vector(IntVector* iv) {
//     auto sz = iv->num_dims;
//     for(int i=0; i<sz; i++) {
//         cout << iv->data[i] << ", ";
//     }
//     cout << endl;
// }

int main(int argc, char* argv[])
{
    auto vi = Vector<int>(5);
    cout << sizeof(vi) << endl;

    // print_intvector(&vi);
    vi.print_vector();

    auto vf = Vector<float>(10);
    vf.print_vector();

    // int*  +
    // cout << *(vi.data - 1) << endl;
    // cout << *(2 + vi.data) << endl;
    // cout << *(vi.data + 2) << endl;
    // cout << 2[vi.data] << endl;
    // cout << vi.data[2] << endl;

    // cout << vi.get(2) << endl;
    cout << vi[2] << endl;
    // cout << operator[](vi, 2) << endl;
    // cout << vi.operator[](2) << endl;

    // a + b;
    // operator+(a, b);

    // int k = 5;
    // int m = -k; // unary minus operator
    // // operator-(k);
    // int l = 5 - 2; // binary minus operator
    // // operator-(5, 2);

    auto V = std::vector<int>(10);

    return 0;
}
