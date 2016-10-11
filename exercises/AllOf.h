// -------
// AllOf.h
// -------
// Checks if unary predicate p returns true for all elements in the range [first, last).

#ifndef AllOf_h
#define AllOf_h


template <typename InputIt, typename UnaryPredicate>
bool my_all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) {
            return false;
        }
    }
    return true;    
}
#endif // AllOf_h
