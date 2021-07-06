#include<iostream>
#include<string>
#include<vector>
#include"task1.h"
using namespace std;

#pragma region Point2D
float Point2D::distCalc(float px, float py) 
{

    return sqrt(pow(px - x, 2) + pow(py - y, 2));

}

string Point2D::toString() 
{

    string sx = to_string(x);
    string sy = to_string(y);

    return "[" + sx + "," + sy + "]";
}

Point2D Point2D::operator+(const Point2D& p)
{
	Point2D pt;
	pt.x = this->x + p.x;
	pt.y = this->y + p.y;
	return pt;
}

Point2D& Point2D::operator=(const Point2D& p)
{
	x = p.x;
	y = p.y;
	return *this;
}

bool Point2D::operator==(const Point2D& p)
{
	return (x == p.x && y == p.y);
}
#pragma endregion

void testRendering(vector<Shape*>shapes)
{
	shapes[0]->render();
	shapes[1]->render();
	shapes[2]->render();
}

int main()
{
	int arr[4] = { 10, 53, 32, 186 };
	Point2D p(4, 3);

	vector<Shape*>shapes;

	Rectangle r(p, arr, 36, 15);
	Triangle t(p, arr, 45, 60);
	Circle c(p, arr, 13);

	shapes.push_back(&r);
	shapes.push_back(&t);
	shapes.push_back(&c);

	testRendering(shapes);

	return 0;
}