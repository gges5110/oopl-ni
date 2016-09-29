// -------------------
// InitializerList.c++
// -------------------

// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <algorithm>        // equal
#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

int main () {
    using namespace std;
    cout << "InitializerList.c++" << endl;

    {
    initializer_list<int> x;
    vector<int>           y;
    vector<int>           z{x};
    assert(x.size() == 0);
    assert(y.size() == 0);
    assert(z.size() == 0);
    }

    {
//  initializer_list<int> x(); //  warning: empty parentheses interpreted as a function
//  vector<int>           y(); //  warning: empty parentheses interpreted as a function
    }

    {
    initializer_list<int> x{};
    vector<int>           y{};
    vector<int>           z{x};
    assert(x.size() == 0);
    assert(y.size() == 0);
    assert(z.size() == 0);
    }

    {
    initializer_list<int> x = {};
    vector<int>           y = {};
    vector<int>           z{x};
    assert(x.size() == 0);
    assert(x.size() == 0);
    assert(z.size() == 0);
    }

    {
//  initializer_list<int> x(2);  // error: no matching constructor for initialization of 'initializer_list<int>'
//  initializer_list<int> x = 2; // error: no matching constructor for initialization of 'initializer_list<int>'
    }

    {
    initializer_list<int> x{2};
    vector<int>           y{2};
    vector<int>           z{x};
    assert(x.size() == 1);
    assert(y.size() == 1);
    assert(z.size() == 1);
    }

    {
    initializer_list<int> x = {2};
    vector<int>           y = {2};
    vector<int>           z{x};
    assert(x.size() == 1);
    assert(y.size() == 1);
    assert(z.size() == 1);
    }

    {
    initializer_list<int> x{2, 3};
    vector<int>           y{2, 3};
    vector<int>           z{x};
    assert(x.size() == 2);
    assert(y.size() == 2);
    assert(z.size() == 2);
    }

    {
    initializer_list<int> x = {2, 3};
    vector<int>           y = {2, 3};
    vector<int>           z{x};
    assert(x.size() == 2);
    assert(y.size() == 2);
    assert(z.size() == 2);
    }

    {
    initializer_list<int> x{2, 3, 4};
    vector<int>           y{2, 3, 4};
    vector<int>           z{x};
    assert(x.size() == 3);
    assert(y.size() == 3);
    assert(z.size() == 3);
    }

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int>           y = {2, 3, 4};
    vector<int>           z{x};
    assert(x.size() == 3);
    assert(y.size() == 3);
    assert(z.size() == 3);
    }

    {
    initializer_list<int> x;
    vector<int>           y;
    vector<int>           z;
    x = {2, 3, 4};
    y = {2, 3, 4};
    z = x;
    assert(x.size() == 3);
    assert(y.size() == 3);
    assert(z.size() == 3);
    }

    {
    initializer_list<int> x = {2, 3, 4};
    initializer_list<int> y = x;
    assert(x.size() == 3);
    assert(y.size() == 3);
    assert(equal(begin(x), end(x), begin(y)));
    }

    {
    initializer_list<int> x = {2, 3, 4};
    initializer_list<int> y = {5, 6};
    assert(x.size() == 3);
    assert(y.size() == 2);
    x = y;
    assert(x.size() == 2);
    assert(y.size() == 2);
    assert(equal(begin(x), end(x), begin(y)));
    }

    cout << "Done." << endl;
    return 0;}
