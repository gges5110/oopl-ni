


template <typename T>
class my_vector {
private:
	T* _data;
	int _size = 0;	 

public:
	int size() const {
		return _size;
	}

	my_vector(const int size = 0, const T& value = T()): _size(size), _data(new T[size]) {
		std::fill(begin(), end(), value);
	}

	my_vector(const my_vector<T>& that) {
		if (_size != 0) {
			delete [] _data;
		} 
		_size = that._size;
		_data = new T[_size];
		std::copy(that.begin(), that.end(), begin());
	}

	my_vector<T>& operator=(const my_vector<T>& that) {
		
		if (_size != 0) {
			delete [] _data;
		} 
		_size = that._size;
		_data = new T[_size];
		std::copy(that.begin(), that.end(), begin());
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

	bool operator==(const my_vector<T>& that) const {
		return std::equal(begin(), end(), that.begin());
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
