
#include <math.h>

template <typename It1, typename It2, typename T>
T rmse_while(It1 first1, It1 last1, It2 first2, T v) {
    T sum();
    int times = 0;
    while (first1 != last1) {
        sum += pow(*first1 - *first2, 2);
        times++;
        ++first1; ++first2;
    }

    return sum / times;
}
