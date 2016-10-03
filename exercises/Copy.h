// ------
// Copy.h
// ------

#ifndef Copy_h
#define Copy_h

template <typename InputIt, typename OutputIt>
OutputIt my_copy(InputIt first1, InputIt last1, OutputIt first2) {
    for (;first1 != last1; ++first1, ++first2) {
        *first2 = *first1;
    }
    return first2;
}

#endif
