#include <iostream>
#include <SDL.h>
#include <vector>
#include <ctime>
#include "task2.h"


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

void testRendering(vector<Shape*>shapes, SDL_Renderer* r)
{
	shapes[0]->render(r);
	shapes[1]->render(r);
	shapes[2]->render(r);
}
/*
int main(int arg, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("fynster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	int col[4] = { 255, 0, 0, 255 };
	int col2[4] = { 0, 255, 0, 255 };
	int col3[4] = { 0, 0, 255, 255 };
	
	Point2D p(220, 260);

	vector<Shape*>shapes;

	Rectangle r(p, col, 158, 231);
	Triangle t(p, col2, 111, 99);
	Circle c(p, col3, 100);

	shapes.push_back(&r);
	shapes.push_back(&t);
	shapes.push_back(&c);

	testRendering(shapes, renderer);

	return 0;
}*/

int main(int arg, char* args[])
{

}