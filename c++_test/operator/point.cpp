#include <iostream>

using namespace std;

class Point{
	double x; 
	double y;
	
public:
	double get_x() {
		return x;
	}

	double get_y() {
		return y;
	}

	Point(double X=0.0, double Y=0.0):x(X),y(Y){};

	Point operator+ (const Point& p);

    friend double get_sum(const Point& p1, const Point& p2);
    
	friend Point sum(const Point& p1, const Point& p2);
};

Point Point::operator +(const Point& p) {
	double x = this->x + p.x;
	double y = this->y + p.y;

    Point tmp(x, y);
	return tmp;
}
    
double get_sum(const Point& p1, const Point& p2) {
    return p1.x+p2.x;
}

Point sum(Point& p1, const Point& p2) {
	return p1+p2;
}

int main(int argc, char** argv) {

	Point p1(1.2,3.1);
	Point p2(1.1, 3.2);
    
    Point p3 = p1+p2;
    cout << p3.get_x() << " " <<p3.get_y() << endl;

    cout << get_sum(p1, p2) <<endl;

	Point p4 = sum(p1, p2);
    cout << p4.get_x() << " " <<p4.get_y() << endl;


    return 0;
}


