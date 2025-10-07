// destructors

// Vector object with dynamic dimensions
// print function for Vector
// static variables, static member variables
// Generic Programming = Templates in C++
// curly bracket usage for deeper lower scopes

// auto, AAA rule (almost always auto)

#include <iostream>

using namespace std;

template<typename T>
struct Vector {
    int num_dims;   // 4 bytes in my arch.
    T* data;      // 8 bytes in my arch.

    Vector(int num_dims) : num_dims(num_dims), data(new T[num_dims]) {
        // this->num_dims = num_dims;
        // this->data = new int[num_dims];
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
    // ALMOST ALWAYS AUTO (aaa)
    // auto a = IntVector(5);
    auto a = Vector<int>(5);
    cout << sizeof(a) << endl;
    // print_intvector(&a);
    a.print_vector();

    auto f = Vector<float>(10);
    f.print_vector();

    return 0;
}
