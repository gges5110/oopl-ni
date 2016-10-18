#include <iterator>

template <typename T> 
class Range_Iterator: public std::iterator<std::input_iterator_tag, T> {
	private:
		T t;
	public:
		Range_Iterator(const T& _t): t(_t) {}

		T operator*() const{
			return t;
		}

		Range_Iterator& operator++() {
			++t;
			return *this;
		}

		Range_Iterator operator++(int) {
			Range_Iterator<T> temp(*this);
			++*this;
			return temp;
		}

		bool operator==(const Range_Iterator& that) const{
			return (t == that.t);
		}

		bool operator!=(const Range_Iterator& that) const{
			// This is inside the header file and is a templated class, so the compiler will inline the invocation of == on *this.
			return !(*this == (that));
		}

};
