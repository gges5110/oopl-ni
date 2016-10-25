#include <memory>


template <typename T, typename A = std::allocator<T>>
class my_vector {
private:
	A _x;
	T* _data;
	int _size;	 

public:
	int size() const {
		return _size;
	}

	my_vector(int size = 0, const T& value = T(), const A& x = A()): 
		_x (),
		_data (_x.allocate(size)),
		_size (size) {
		for (int i = 0; i < _size; ++i) {
			_x.construct(_data + i, value);
		}
	}

	my_vector(const my_vector& that): _size(that._size) {
		if (_size == 0) {
			_data = nullptr;
			return;
		} else {
			_data = new T[_size];
			std::copy(that.begin(), that.end(), begin());
		}
	}

	my_vector& operator=(my_vector that) {
		std::swap(_size, that._size);
		std::swap(_data, that._data);		
		return *this;
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

	friend bool operator==(const my_vector& lhs, const my_vector& rhs) {
		return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}


	T* begin() const {
		return _data;
	}

	T* end() const {
		return _data + _size;
	}

	~my_vector() {
		for (int i = 0; i < _size; ++i) {
			_x.destroy(_data + i);
		}
		_x.deallocate(_data, _size);	
	}

};
