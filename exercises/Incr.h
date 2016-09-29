
template <typename T>
T& pre_incr (T& that) {
    return ++that;
}

template <typename T>
T post_incr (T& that) {
    return that++;
}
