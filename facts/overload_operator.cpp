struct point {
    int x, y;

    point(int x, int y) : x(x), y(y) {}
    point() : x(0), y(0) {}

    point operator + (point aux) {
        return point(x + aux.y, y + aux.y);
    }

    point operator * (point c) {
        return point(x * c, y * c);
    }

    int operator * (point p) {
        return x * p.x + y * p.y;
    }
};
