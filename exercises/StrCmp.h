<<<<<<< HEAD
#ifndef StrCmp_h
#define StrCmp_h

=======
// ----------
// StrCmp.h
//
// This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
// ----------
>>>>>>> Correct Strcmp.h

int my_strcmp( const char *lhs, const char *rhs ) {
    while (*lhs && *rhs) {
        if (*lhs != *rhs)
            return *lhs - *rhs;
        lhs++; rhs++;
    }

    if (*lhs)         return *lhs;
    else if (*rhs)    return -*rhs;
    else              return 0;
}
#endif // StrCmp_h
