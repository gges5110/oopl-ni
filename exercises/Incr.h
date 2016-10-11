// --------
// Incr.c++
// --------
#ifndef Incr_h
#define Incr_h

template <typename T>
T& pre_incr (T& that) {
    return ++that;
}

template <typename T>
T post_incr (T& that) {
    return that++;
}

#endif // Incr_h
