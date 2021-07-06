#pragma once
#include<iostream>
#include<string>
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

	virtual void render() = 0;

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

	void render() 
	{
		cout << "Drawing rectangle with height: " << height << " and width: " << width << " at: " << getX() << ", " << getY() << endl;
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
	void render() 
	{
		cout << "Drawing triangle with base: " << base << " and height: " << height << " at: " << getX() << ", " << getY() << endl;
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

	void render()
	{
		cout << "Drawing circle with radius: " << rad << " at: " << getX() << ", " << getY() << endl;
	}
};