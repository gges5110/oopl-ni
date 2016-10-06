<<<<<<< HEAD
// ------
// Fill.h
// ------

#ifndef Fill_h
#define Fill_h

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}

#endif // Fill_h
=======

// We need a ForwardIt to compare the two iterators and write to it.

template <typename ForwardIt, typename T>
void my_fill(ForwardIt first, ForwardIt last, T value) {
    for (; first != last; ++first) {
        *first = value;
    }
    return;
}
>>>>>>> Fill.h
