// ---------
// Vector3.h
// ---------

#ifndef Vector_h
#define Vector_h

#include <algorithm> // copy, fill, swap
#include <cstddef>   // ptrdiff_t, size_t
#include <utility>  // !=
#include <initializer_list>

using std::rel_ops::operator!=;
using std::rel_ops::operator>=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;


#include <memory>
#include "Memory.h"

template <typename T, typename A = std::allocator<T>>
class my_vector {
private:
	A _x;
	int _size;	 
	T* _data;

public:
	using allocator_type = A;	

	friend bool operator==(const my_vector& lhs, const my_vector& rhs) {
		return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator<(const my_vector& lhs, const my_vector& rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	// Default constructor
	my_vector(int size = 0, const T& value = T(), const A& x = A()) : 
		_x (x),
		_size (size),
		_data (_x.allocate(size)) {
		for (int i = 0; i < _size; ++i) {
			_x.construct(_data + i, value);
		}
	}

	// Copy constructor
	my_vector(const my_vector& that, const A& x = A()) : 
		_x (x),
		_size (that._size),
		_data (_size == 0 ? nullptr : _x.allocate(_size)) {
		my_uninitialized_copy(_x, that.begin(), that.end(), begin());
	}

	// Copy assignment
	my_vector& operator=(my_vector that) {
		std::swap(_size, that._size);
		std::swap(_data, that._data);		
		return *this;
	}

	// Initializer list constructor
	my_vector(std::initializer_list<T> l, const A& x = A()) :
		_x (x), 
		_size(l.size()), 
		_data(_x.allocate(_size)) {
		my_uninitialized_copy(_x, l.begin(), l.end(), begin());
	}

	T& operator[](int index) {
		return _data[index];
	}
	
	// Without the const_cast, this function will also call the const version of bracket operator, which is itself. In order to call the non-const version, we need the const_cast to cast away the constness of this.
	const T& operator[](int index) const {
		return (*const_cast<my_vector*>(this))[index];
	}

	T& at(int index) {
		if (index >= _size) throw std::out_of_range("Index out of range.");
		return (*this)[index];
	}

	const T& at(int index) const {		
		return (*const_cast<my_vector*>(this))[index];
	}


	T* begin() {
		return _data;
	}

	T* begin() const {
		return (*const_cast<my_vector*>(this)).begin();
	}

	T* end() {
		return _data + _size;
	}

	T* end() const {
		return (*const_cast<my_vector*>(this)).end();
	}

	// Destructor
	~my_vector() {
		for (int i = 0; i < _size; ++i) {
			_x.destroy(_data + i);
		}
		_x.deallocate(_data, _size);	
	}

	int size() const {
		return _size;
	}

};

#endif // Vector_h
