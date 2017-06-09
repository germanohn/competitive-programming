struct point {
    // Variables
    double x, y;

    // Constructors
    point() {}
    point(double x, double y) : x(x), y(y) {}

    // Operators
    point operator+ (const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator- (const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator* (double a) const {
        return point(a * x, a * y);
    }
    point operator* (const point &a) const {
        return point(x * a.x, y * a.y);
    }
    double operator^ (const point &a) const {
        return x * a.y - y * a.x; 
    }
    bool operator< (const point &a) const {
        if (fabs(x - a.x) < eps) return (y < a.y + eps);
        return (x < a.x + eps);
    }

    // Functions
    double dist2() const {
        return x * x + y * y;
    }
    double dist() const {
        return sqrt(dist2());
    }
    point proj(const point &a) const {
        double lambda = (*this * a) / a.dist2();
        return lambda * a;
    }
}
