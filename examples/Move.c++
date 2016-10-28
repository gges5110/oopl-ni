// --------
// Move.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
struct A {
    A () {
        cout << "A() ";}

    A (const A& rhs) {
        cout << "A(const A&) ";}

    A (A&&) {
        cout << "A(A&&) ";}

    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;}

    A& operator = (A&&) {
        cout << "=(A&&) ";
        return *this;}

    ~A() {
        cout << "~A() ";}};

template <typename T>
struct B {
    A<T> _x;

    B ( ) :
            _x () {
        cout << "B() ";}

    B (const B& rhs) :
            _x (rhs._x) {
        cout << "B(const B&) ";}

    B& operator = (const B& rhs) {
        _x = rhs._x;
        cout << "=(const B&) ";
        return *this;}

    ~B() {
        cout << "~B() ";}};

template <typename T>
struct C {
    A<T> _x;

    C () :
            _x () {
        cout << "C() ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

    C (C&& rhs) :
            _x (move(rhs._x)) {
        cout << "C(C&&) ";}

    C& operator = (const C& rhs) {
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    C& operator = (C&& rhs) {
        _x = move(rhs._x);
        cout << "=(C&&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

B<int> f () {
    return B<int>();}

C<int> g () {
    return C<int>();}

int main() {
    {
    cout << "1. ctor: ";
    B<int> x;             // 1. ctor: A() B()
    cout << endl;

    cout << "2. ctor: ";
    B<int> y;             // 2. ctor: A() B()
    cout << endl;

    cout << "3. copy: ";
    x = y;                // 3. copy: =(const A&) =(const B&)
    cout << endl;

    cout << "4. copy: ";
    x = f();              // 4. copy: A() B() =(const A&) =(const B&) ~B() ~A()
    cout << endl;

    cout << "5. dtor: ";
    }                     // 5. dtor: ~B() ~A() ~B() ~A()
    cout << endl << endl;



    {
    cout << "1. ctor: ";
    C<int> x;            // 1. ctor: A() C()
    cout << endl;

    cout << "2. ctor: ";
    C<int> y;            // 2. ctor: A() C()
    cout << endl;

    cout << "3. copy: ";
    x = y;               // 3. copy: =(const A&) =(const C&)
    cout << endl;

    cout << "4. move: ";
    x = g();             // 4. move: A() C() =(A&&) =(C&&) ~C() ~A()
    cout << endl;

    cout << "5. dtor: ";
    }                    // 5. dtor: ~C() ~A() ~C() ~A()
    cout << endl;

    return 0;}

/*
1. ctor: A() B()
2. ctor: A() B()
3. copy: =(const A&) =(const B&)
4. copy: A() B() =(const A&) =(const B&) ~B() ~A()
5. dtor: ~B() ~A() ~B() ~A()

1. ctor: A() C()
2. ctor: A() C()
3. copy: =(const A&) =(const C&)
4. move: A() C() =(A&&) =(C&&) ~C() ~A()
5. dtor: ~C() ~A() ~C() ~A()
*/
