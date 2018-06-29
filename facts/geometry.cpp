struct Point {
    // Variables
    double x, y;

    // Constructors
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    // Operators
    Point operator+ (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator- (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator* (double k) const {
        return Point(p * x, p * y);
    }
    Point operator* (const Point &p) const {
        return Point(x * p.x, y * p.y);
    }
    double operator^ (const Point &p) const {
        return x * p.y - y * p.x; 
    }
    bool operator< (const Point &p) const {
        if (fabs(x - p.x) < eps) return (y < p.y + eps);
        return (x < p.x + eps);
    }

    // Functions
    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(dist2()); }
    double arg() { return atan2(y, x); } // [-PI, PI]
    Point rotate(double alpha) {
        return Point(x * cos(alpha) - y * sin(alpha), 
                     x * sin(alpha) + y * cos(alpha));
    }
    Point proj(const Point &p) const {
        double lambda = (*this * p) / p.dist2();
        return lambda * p;
    }
};

template<class T> using Vector = Point<T>; // ou só using Vector = Point
