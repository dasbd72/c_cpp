// AC
#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape3D
	{	
		double volume;

	public:
		double getVolume();
	
	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D
	{
		double radius;
		double pi;
	
	public:
		Sphere(double, double);
	};

	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};

	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;
	
	public:
		Cuboid(double, double, double);
	};

	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
}
#include <cmath>
namespace oj{
	Sphere::Sphere(double radius, double pi):radius(radius), pi(pi) {
		if(radius < 0 || pi < 0) setVolume(0);
		else setVolume(4.0/3.0 * pi * pow(radius, 3));
	}

	Cone::Cone(double radius, double height, double pi):radius(radius), height(height), pi(pi){
		if(radius < 0 || height < 0 || pi < 0) setVolume(0);
		else setVolume(1.0/3.0 * pi * radius * radius * height);
	}

	Cuboid::Cuboid(double length, double width, double height):length(length), width(width), height(height){
		if(length < 0 || width < 0 || height < 0) setVolume(0);
		else setVolume(length * width * height);
	}

	Cube::Cube(double length):Cuboid(length, length, length){
		if(length < 0) setVolume(0);
	}
}

#endif
