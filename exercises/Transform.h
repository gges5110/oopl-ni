// -------------
// Transform.c++
// -------------

// http://www.cplusplus.com/reference/algorithm/transform

#ifndef Transform_h
#define Transform_h

template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator my_transform(InputIterator b, InputIterator e, OutputIterator c, UnaryFunction f) {
    for (; b != e; ++b, ++c) {
        *c = f(*b);
    }
    return c;
}


#endif // Transform_h

