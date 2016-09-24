// ----------
// StrCmp.h
// ----------

int my_strcmp( const char *lhs, const char *rhs ) {
    int tmp = 0;
    while (*lhs != 0 && * rhs != 0) {
        if (*lhs != *rhs) {
            tmp += *lhs - *rhs;
        }
        lhs++; rhs++;
    }


    while (*lhs != 0) {
        tmp += *(lhs++);
    }

    while (*rhs != 0) {
        tmp -= *(rhs++);
    }

    return tmp;
}
