


template <typename OutputIt, typename T>
void my_fill(OutputIt first, OutputIt last, T value) {
    for (; first != last; ++first) {
        *first = value;
    }
    return;
}
