// ---------
// Range.c++
// ---------

#ifndef Range_h
#define Range_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag, iterator
#include <utility>  // !=

/*
namespace std {

template <typename C, typename T, typename D = ptrdiff_t, typename P = T*, typename R = T&>
struct iterator {
    using iterator_category = C;
    using value_type        = T;
    using difference_type   = D;
    using pointer           = P;
    using reference         = R;};

} // std
*/

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

} // rel_ops
} // std;
*/

using std::rel_ops::operator!=;


template <typename T>
class Range {
private: 
	T b, e;
public:
	class iterator: public std::iterator<std::input_iterator_tag, T> {
/*
            public:
                using iterator_category = input_iterator_tag;
                using value_type        = T;
                using difference_type   = ptrdiff_t;
                using pointer           = T*;
                using reference         = T&;
*/
		T it;
	public:
		iterator(T _it): it(_it) {}

		T operator*() const {
			return it;
		}

		iterator& operator++() {
			++it;
			return *this;
		}

		iterator operator++(int) {
			iterator temp(it);
			++*this;
			return temp;
		}

        friend bool operator == (const iterator& lhs, const iterator& rhs) {
            return (lhs.it == rhs.it);}

	};

	Range(const T& _b, const T& _e): b(_b), e(_e) {}

	iterator begin() const {
		return b;
	}	

	iterator end() const {
		return e;
	}

};


#endif // Range_h
