


template <typename T>
class my_vector {
private:
	T* _data;
	int _size;	 

public:
	int size() const {
		return _size;
	}

	my_vector(const int size = 0, const T& value = T()): _size(size), _data(new T[size]) {
		std::fill(begin(), end(), value);
	}

	my_vector(const std::initializer_list<T> l) : _size(l.size()), _data(new T[l.size()]) {
    	std::copy(l.begin(), l.end(), begin());
	}

	T& operator[](const int index) {
		return _data[index];
	}

	const T& operator[](const int index) const {
		return _data[index];
	}


	T* begin() const {
		return _data;
	}

	T* end() const {
		return _data + _size;
	}

	~my_vector() {
		delete [] _data;
	}

};
