#include <iostream>
//#include <vector>
#include <array>


struct Point{
	double x;
	double y;
	double z;
};

int main(int argc, char ** argv) {
	//std::vector<Point> pa = {{1.0, 1.1, 1.2}, {2.0,2.1,2.2}};
	std::array<Point, 2> pa = {{1.0, 1.1, 1.2}, {2.0,2.1,2.2}};

	Point pb[pa.size()]; //ok

	Point* pp = (Point*)&pa;

	std::cout << pp->x << std::endl;
	std::cout << pp->y << std::endl;
	std::cout << pp->z << std::endl;
}
