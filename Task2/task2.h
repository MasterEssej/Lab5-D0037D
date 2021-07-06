#pragma once
#include<iostream>
#include<string>
#include<SDL.h>
#include<math.h>
using namespace std;

class Point2D
{
public:
	float x, y;
	Point2D()
	{
		x = 0;
		y = 0;
	}
	Point2D(const float& valuex, const float& valuey)
	{
		x = valuex;
		y = valuey;
	}
	float distCalc(float px, float py);
	string toString();

	Point2D operator+(const Point2D& p);
	Point2D& operator=(const Point2D& p);
	bool operator==(const Point2D& p);
};

class Shape
{
private:
	int colors[4];
	Point2D pos;

public:
	Shape(Point2D p, int* arr)
	{
		pos = p;
		for (int i = 0; i < 4; i++)
		{
			colors[i] = arr[i];
		}
	}

	string getColor()
	{
		return to_string(colors[0]) + ", " + to_string(colors[1]) + ", " + to_string(colors[2]) + ", " + to_string(colors[3]);
	}

	int getR()
	{
		return colors[0];
	}
	int getG()
	{
		return colors[1];
	}
	int getB()
	{
		return colors[2];
	}
	int getA()
	{
		return colors[3];
	}
	int getX()
	{
		return pos.x;
	}
	int getY()
	{
		return pos.y;
	}

	virtual void render(SDL_Renderer* r) = 0;

	void setR(int setR)
	{
		if (colors[0] < 0 || colors[0] > 255)
		{
			colors[0] = colors[0];
		}
		else
		{
			colors[0] = setR;
		}
	}
	void setG(int setG)
	{
		if (colors[1] < 0 || colors[1] > 255)
		{
			colors[1] = colors[1];
		}
		else
		{
			colors[1] = setG;
		}
	}
	void setB(int setB)
	{
		if (colors[2] < 0 || colors[2] > 255)
		{
			colors[2] = colors[2];
		}
		else
		{
			colors[2] = setB;
		}
	}
	void setA(int setA)
	{
		if (colors[3] < 0 || colors[3] > 255)
		{
			colors[3] = colors[3];
		}
		else
		{
			colors[3] = setA;
		}
	}
};

class Rectangle : public Shape
{
private:
	int width;
	int height;

public:
	Rectangle(Point2D p, int* arr, int nwidth, int nheight) :
		Shape(p, arr), width(nwidth), height(nheight)
	{

	}

	int getW()
	{
		return width;
	}
	int getH()
	{
		return height;
	}
	void setW(int nwidth)
	{
		width = nwidth;
	}
	void setH(int nheight)
	{
		height = nheight;
	}

	virtual void render(SDL_Renderer* r) 
	{

		int x = getX();
		int y = getY();
		cout << "Drawing rectangle with height: " << height << " and width: " << width << " at: " << getX() << ", " << getY() << endl;
		SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
		//SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getR(), getG(), getB(), getA());
		SDL_RenderDrawLine(r, x, y, x + width, y);
		SDL_RenderDrawLine(r, x + width, y, x + width, y - height);
		SDL_RenderDrawLine(r, x + width, y - height, x, y - height);
		SDL_RenderDrawLine(r, x, y - height, x, y);

		SDL_RenderPresent(r);

		SDL_Delay(3000);

	}
};

class Triangle : public Shape 
{
private:
	int base;
	int height;

public:
	Triangle(Point2D p, int* arr, int nbase, int nheight) :
		Shape(p, arr), base(nbase), height(nheight)
	{

	}

	int getB()
	{
		return base;
	}
	int getH()
	{
		return height;
	}
	void setB(int nbase)
	{
		base = nbase;
	}
	void setH(int nheight)
	{
		height = nheight;
	}
	virtual void render(SDL_Renderer* r)
	{
		int x = getX();
		int y = getY();
		cout << "Drawing triangle with base: " << base << " and height: " << height << " at: " << getX() << ", " << getY() << endl;
		SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
		//SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getR(), getG(), getB(), getA());
		SDL_RenderDrawLine(r, x, y, x + base / 2, y - height);
		SDL_RenderDrawLine(r, x + base / 2, y - height, x + base, y);
		SDL_RenderDrawLine(r, x + base, y, x, y);

		SDL_RenderPresent(r);

		SDL_Delay(3000);
	}
};

class Circle : public Shape
{
private:
	int rad;

public:
	Circle(Point2D p, int* arr, int nrad) :
		Shape(p, arr), rad(nrad)
	{

	}

	int getR()
	{
		return rad;
	}
	int setR(int nrad)
	{
		rad = nrad;
	}

	virtual void render(SDL_Renderer* r)
	{
		cout << "Drawing circle with radius: " << rad << " at: " << getX() << ", " << getY() << endl;

		SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
		//SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getR(), getG(), getB(), getA());
		int pos_x = getX();
		int pos_y = getY();
		int theta = 0;
		int h = 12;
		int k = 10;
		int step = 15;
		while (theta <= 2160) {
			int x = h + rad * cos(theta);
			int y = k + rad * sin(theta);
			SDL_RenderDrawPoint(r, pos_x + x, pos_y + y);
			theta += step;
		}

		SDL_RenderPresent(r);

		SDL_Delay(3000);
	}
};