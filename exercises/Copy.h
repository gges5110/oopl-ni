// ------
// Copy.h
// ------

#ifndef Copy_h
#define Copy_h

<<<<<<< HEAD
<<<<<<< HEAD
template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

#endif // Copy_h
=======
template <typename InputIt1, typename InputIt2>
InputIt2 my_copy(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
=======
template <typename InputIt, typename OutputIt>
OutputIt my_copy(InputIt first1, InputIt last1, OutputIt first2) {
>>>>>>> Fill.h
    for (;first1 != last1; ++first1, ++first2) {
        *first2 = *first1;
    }
    return first2;
}

#endif
>>>>>>> Copy.h
