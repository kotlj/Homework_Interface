
#include <iostream>
#include <math.h>

class Base
{
protected:
	double first;
	double second;
public:
	Base()
	{
		first = 0;
		second = 0;
	}
	Base(double _first, double _second)
	{
		first = _first;
		second = _second;
	}
	double virtual area() = 0;
};
class Rectangle : public Base
{
private:
public:
	Rectangle() : Base()
	{}
	Rectangle(double _first, double _second) : Base(_first, _second)
	{}
	double area() override
	{
		return first * second;
	}
};
class Circle : public Base
{
private:
public:
	Circle() : Base()
	{}
	Circle(double radius) : Base(radius, 3.14)
	{}
	double area() override
	{
		return second * pow(first, 2);
	}
};
class RightTriangle : public Base
{
private:
public:
	RightTriangle() : Base()
	{}
	RightTriangle(double firstLeg, double secondLeg) : Base(firstLeg, secondLeg)
	{}
	double area() override
	{
		return (first * second) / 2;
	}
};
class Trapezoid : public Base
{
private:
	double height;
public:
	Trapezoid() : Base()
	{
		height = 0;
	}
	Trapezoid(double firstBasis, double secondBasis, double _height) : Base(firstBasis, secondBasis)
	{
		height = _height;
	}
	double area() override
	{
		return (first * second) / 2 * height;
	}
};

int main()
{
	int size = 4;
	Rectangle test_Re(4, 5);
	Circle test_C(1);
	RightTriangle test_Ri(5, 8);
	Trapezoid test_T(2, 4, 3);
	Base** obj = new Base*[size];
	obj[0] = dynamic_cast<Base*>(&test_Re);
	obj[1] = dynamic_cast<Base*>(&test_C);
	obj[2] = dynamic_cast<Base*>(&test_Ri);
	obj[3] = dynamic_cast<Base*>(&test_T);
	std::cout << obj[0]->area() << '\n';
	delete[] obj;
}
