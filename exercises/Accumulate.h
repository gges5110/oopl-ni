// --------------
// Accumulate.c++
// --------------
 
// http://www.cplusplus.com/reference/algorithm/accumulate/


template <typename II, typename T, typename BF>
T my_accumulate(II b, II e, T v, BF f) {
    for(; b != e; ++b)
        v = f(v, *b);
    return v;
}
