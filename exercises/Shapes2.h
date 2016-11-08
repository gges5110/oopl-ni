#include <iostream>
#include <utility>

using std::rel_ops::operator!=;

class Circle : public Shape {
private:
	int _radius;

protected:
	bool equals (const Shape& rhs) const {
		try {
			const Circle& r = dynamic_cast<const Circle&>(rhs);
			return r._radius == _radius && Shape::equals(rhs);
		} catch (const std::bad_cast& e) {
			return false;
		}	
	}	

	std::istream& read(std::istream& in) {
		return Shape::read(in) >> _radius;
	}

	std::ostream& write(std::ostream& out) const {
		return Shape::write(out) << " " << _radius;
	}

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
