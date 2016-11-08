#include <iostream>
#include <utility>

using std::rel_ops::operator!=;

class Circle : public Shape {
	friend bool operator==(const Circle& lhs, const Circle& rhs) {
		return static_cast<const Shape&>(lhs) == rhs && lhs._radius == rhs._radius;
	}

	friend std::istream& operator >> (std::istream& lhs, Circle& rhs) {
		return lhs >> static_cast<Shape&>(rhs) >> rhs._radius;
	}

	friend std::ostream& operator << (std::ostream& lhs, const Circle& rhs) {
		return lhs << static_cast<const Shape&>(rhs) << " " << rhs._radius;
	}
private:
	int _radius;

public:

	Circle(int x, int y, int radius) :
	Shape(x, y),
	_radius (radius) 
	{} 

	Circle (const Circle&) = default;
	Circle& operator = (const Circle&) = default;
	~Circle() = default;
	
	double area() const {
		return 3.14 * _radius * _radius;
	}

	int radius() const {
		return _radius;
	}

};
