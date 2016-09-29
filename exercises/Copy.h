// ------
// Copy.h
// ------

#ifndef Copy_h
#define Copy_h

template <typename InputIt1, typename InputIt2>
InputIt2 my_copy(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    for (;first1 != last1; ++first1, ++first2) {
        *first2 = *first1;
    }
    return first2;
}

#endif
