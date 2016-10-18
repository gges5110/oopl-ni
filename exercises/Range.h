#include <iterator>

template <typename T>
class Range {
private: 
	T b, e;
public:
	class iterator: public std::iterator<std::input_iterator_tag, T> {
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

		bool operator==(const iterator& that) const {
			return it == that.it;
		}

		bool operator!=(const iterator& that) const {
			return !(*this == that);
		}
	};

	Range(const T& _b, const T& _e): b(_b), e(_e) {}

	iterator begin() const {
		return b;
	}	

	iterator end() const {
		return e;
	}

};
