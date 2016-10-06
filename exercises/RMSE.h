<<<<<<< HEAD
// --------
// RMSE.c++
// --------

#include <algorithm> // transform
#include <cmath>     // sqrt
#include <cstddef>   // ptrdiff_t
#include <iterator>  // back_inserter, distance
#include <list>      // list
#include <numeric>   // accumulate

template <typename II1, typename II2, typename T>
T rmse_while (II1 b, II1 e, II2 c, T v) {
    if (b == e)
        return v;

    const std::ptrdiff_t s = std::distance(b, e);

    while (b != e) {
        const T d = (*b - *c);
        v += (d * d);
        ++b;
        ++c;}

    return std::sqrt(v / s);}

template <typename II1, typename II2, typename T>
T rmse_transform_accumulate (II1 b, II1 e, II2 c, T v) {
    if (b == e)
        return v;

    const std::ptrdiff_t s = std::distance(b, e);

    std::list<T> x(s);
    std::transform(b, e, c, begin(x),
        [] (T a, T p) -> T {const T d = a - p; return (d * d);});
    v = std::accumulate(begin(x), end(x), v);

    return std::sqrt(v / x.size());}

template <typename II1, typename II2, typename T>
T rmse_back_inserter (II1 b, II1 e, II2 c, T v) {
    if (b == e)
        return v;

    std::list<T> x;

    std::transform(b, e, c, std::back_inserter(x),
        [] (T a, T p) -> T {const T d = a - p; return (d * d);});
    v = std::accumulate(begin(x), end(x), v);

    return std::sqrt(v / x.size());}
=======
#include <iterator>
#include <cmath>
#include <list>

template <typename It1, typename It2, typename T>
T rmse_while(It1 b, It1 e, It2 c, T v) {
    if (b == e)
        return v;
   
    ptrdiff_t s = distance(b, e); 
    while (b != e) {
        T d = (*b - *c);
        v += (d * d);
        ++b; ++c;
    }
   
    return sqrt(v/s);
}


template <typename II1, typename II2, typename OI, typename BF>
OI my_transform(II1 b, II1 e, II2 c, OI output, BF f) {
    while (b != e) {
        *output = f(*b);
        ++b; ++output;
    }
    return output;
}

template <typename II, typename T>
T accumulate(II b, II e, T v) {
    while (b != e) {
        v += *b;
        ++b;
    }
    return v;
}

template <typename II1, typename II2, typename T>
T rmse_transform_accumulate(II1 b, II1 e, II2 c, T v) { 
    if (b == e)
        return v;
    auto s = distance(b, e);
    std::list<T> x(s);
    my_transform(b, e, c, x.begin(), [] (const T& a, const T& p) -> T{return pow((a - p), 2);});
    v = accumulate(x.begin(), x.end(), v);
    return sqrt(v / s);
}
>>>>>>> another commit
