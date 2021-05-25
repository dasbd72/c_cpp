#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape
	{
	public:
		double getArea();
		double getPerimeter();

	protected:
		void setArea(double a);
		void setPerimeter(double p);

	private:
		double area;
		double perimeter;
	};

	class Triangle : public Shape
	{
	public:
		Triangle(double edge1, double edge2, double edge3);

	private:
		double edge1;
		double edge2;
		double edge3;
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle(double width, double height);

	private:
		double width;
		double height;
	};

	class Circle : public Shape
	{
	public:
		Circle(double radius, double pi);

	private:
		double radius;
		double pi;
	};
}

#endif

#include <iostream>
#include <cmath>
namespace oj
{
	Triangle::Triangle(double edge1, double edge2, double edge3)
	{
		double s = (edge1 + edge2 + edge3) / 2;
		if (edge1 <= 0 || edge2 <= 0 || edge3 <= 0 || edge1 > edge2+edge3 || edge2 > edge1+edge3 || edge3 > edge1+edge2)
		{
			setArea(0);
			setPerimeter(0);
		}
		else
		{
			setArea(sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)));
			setPerimeter(edge1 + edge2 + edge3);
		}
	}
	Rectangle::Rectangle(double width, double height)
	{
		if (width <= 0 || height <= 0)
		{
			setArea(0);
			setPerimeter(0);
		}
		else
		{
			setArea(width * height);
			setPerimeter(2.0 * (width + height));
		}
	}
	Circle::Circle(double radius, double pi)
	{
		if (radius <= 0 || pi <= 0)
		{
			setArea(0);
			setPerimeter(0);
		}
		else
		{
			setArea(pi * radius * radius);
			setPerimeter(2 * pi * radius);
		}
	}
}
