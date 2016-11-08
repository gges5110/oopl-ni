// ---------
// Shapes3.h
// ---------

#ifndef Shapes3_h
#define Shapes3_h

#include <utility> // !=

using std::rel_ops::operator!=;

class Circle : public AbstractShape {
private:
	int _radius;

protected:
	bool equals (const AbstractShape& rhs) const {
		try {
			const Circle& r = dynamic_cast<const Circle&>(rhs);
			return r._radius == _radius && AbstractShape::equals(rhs);
		} catch (const std::bad_cast& e) {
			return false;
		}	
	}	

	std::istream& read(std::istream& in) {
		return AbstractShape::read(in) >> _radius;
	}

	std::ostream& write(std::ostream& out) const {
		return AbstractShape::write(out) << " " << _radius;
	}

public:

	Circle(int x, int y, int radius) :
	AbstractShape(x, y),
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

	virtual Circle* clone() const {
		return new Circle(*this);
	}

};
#endif // Shapes3_h
