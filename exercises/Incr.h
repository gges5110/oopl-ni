// --------
// Incr.c++
// --------
<<<<<<< HEAD
=======

#ifndef Incr_h
#define Incr_h
>>>>>>> merge

#ifndef Incr_h
#define Incr_h

<<<<<<< HEAD
int& pre_incr (int& r) {
    return r += 1;}

int post_incr (int& r) {
    int v = r;
    r += 1;
    return v;}
=======
template <typename T>
T post_incr (T& that) {
    return that++;
}
>>>>>>> merge

#endif // Incr_h
