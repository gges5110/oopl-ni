// -------
// AllOf.h
// -------
<<<<<<< HEAD

#ifndef AllOf_h
#define AllOf_h

template <typename II, typename UP>
bool my_all_of (II b, II e, UP f) {
    while (b != e) {
        if (!f(*b))
            return false;
        ++b;}
    return true;}

#endif // AllOf_h
=======
// Checks if unary predicate p returns true for all elements in the range [first, last).


template <typename InputIt, typename UnaryPredicate>
bool my_all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) {
            return false;
        }
    }
    return true;    
}
>>>>>>> AllOf.h
