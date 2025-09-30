#include <iostream>

// C notation
// typedef struct { int dim1; int dim2; } Vector2d;

// C++ notation
struct Vector2d {
    int dim1;
    int dim2;
    // whatever* ptr;

    // member function
    Vector2d(/*Vector2d* v, */int dim1, int dim2) {
        // this->ptr = new ....
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
};

// free function
void constructVector2d(Vector2d& v, int dim1, int dim2) {
    v.dim1 = dim1;
    v.dim2 = dim2;
}

Vector2d addVectors(const Vector2d& a, const Vector2d& b) {
    // a.dim1 = 10000;
    Vector2d r(a.dim1 + b.dim1, a.dim2 + b.dim2); // resulting 2d vector dimension values
    // constructVector2d(&r, a.dim1 + b.dim1, a.dim2 + b.dim2);
    // r.dim1 = a.dim1 + b.dim1;
    // r.dim2 = a.dim2 + b.dim2;
    return r;
}

int main(int argc, char* argv[])
{
    Vector2d a(5, 3);
    // constructVector2d(a, 5, 3);
    // a.constructVector2d(5, 3);

    Vector2d b(10, -5);
    // constructVector2d(b, 10, -5);

    Vector2d r = addVectors(a, b);
    std::cout << "R = (" << r.dim1 << ", " << r.dim2 << ")" << std::endl;

    Vector2d* from_heap = new Vector2d(20, 30);
    delete from_heap;
    // addVectors(15, 13, 20, -35);

    return 0; // 0 means everything is okay
}
