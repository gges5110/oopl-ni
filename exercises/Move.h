template <typename T>
struct C {
    A<T> _x;

    explicit C (int s) :
            _x (s) {
        cout << "C(int) ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

	C (C&& that) : _x(std::move(that._x)) {
		cout << "C(C&&) ";
	}

	C& operator = (C&& rhs) {
		_x = std::move(rhs._x);
		cout << "=(C&&) ";
		return *this;
	}


    C& operator = (const C& rhs) {
        if (this == &rhs)
            return *this;
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

