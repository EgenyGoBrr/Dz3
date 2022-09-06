#include <locale.h>
#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double area() { return 0.0; }
	virtual double volume() { return 0.0; }
	virtual void printShapeName() = 0;
	virtual void print() = 0;
};

class Point : public Shape
{
	friend ostream& operator << (ostream&, Point&);
private:
	float x, y;
public:
	Point(float = 0, float = 0);
	void setPoint(float, float);
	float getX() { return x; }
	float getY() { return y; }
	virtual void printShapeName() { cout << "Точка : "; }
	virtual void print();
};

Point::Point(float a, float b) { setPoint(a, b); }

void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}

void Point::print() { cout << "[" << x << ", " << y << "]"; }

ostream& operator<<(ostream& output, Point& p)
{
	p.print();
	return output;
}


class Circle : public Point
{
	friend ostream& operator << (ostream&, Circle&);
private:
	float radius;
public:
	Circle(float r = 0.0, float x = 0.0, float y = 0.0);
	void setRadius(float);
	float getRadius();
	virtual double area();
	virtual void printShapeName() { cout << "Круг : "; }
	virtual void print();
};

Circle::Circle(float r, float a, float b) : Point(a, b)
{
	radius = r > 0 ? r : 0;
}
void Circle::setRadius(float r) { radius = r > 0 ? r : 0; }
float Circle::getRadius() { return radius; }
double Circle::area() { return 3.14159 * radius * radius; }
void Circle::print()
{
	cout << "[" << getX() << ", " << getY() << "]; радиус = " << radius;
}
ostream& operator << (ostream& output, Circle& c)
{
	c.print();
	return output;
}

class Cylinder : public Circle
{
	friend ostream& operator << (ostream&, Cylinder&);
private: 
	float height;

public:
	Cylinder(float r = 0.0, float x = 0.0, float y = 0.0, float h = 0.0);
	void setHeight(float);
	float getHeight();
	virtual double area();
	virtual void printShapeName() { cout << "Цилиндр : "; }
	virtual void print();
	virtual double volume();
};

Cylinder::Cylinder(float r, float x, float y, float h) : Circle(r,x,y)
{
	height = h > 0 ? h : 0;
}

double Cylinder::volume()
{
	return 3.14159 * getRadius() * getRadius() * height;
}

void Cylinder::setHeight(float h)
{
	height = h > 0 ? h : 0;
}

float Cylinder::getHeight()
{
	return height;
}

double Cylinder::area()
{
	return 2 * 3.14159 * getRadius() * (height + getRadius());
}

void Cylinder::print()
{
	cout << "[" << getX() << ", " << getY() << "]; радиус = " << getRadius() << "; высота = "<< height;
}

ostream & operator<<(ostream & output, Cylinder & c)
{
	c.print();
	return output;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Пробный вывод на экран" << std::endl;
	system("cls");
	Point point(7, 11);
	Circle circle(3.56, 22, 9);
	Cylinder cylinder(4.6, 5.1, 4.6, 6.1);
	point.printShapeName();
	cout << point << '\n';
	circle.printShapeName();
	cout << circle << '\n';
	cylinder.printShapeName();
	cout << cylinder << '\n';
	Shape* array[3];
	array[0] = &point;
	array[1] = &circle;
	array[2] = &cylinder;
	for (int i = 0; i < 3; i++)
	{
		array[i]->printShapeName();
		cout << '\n';
		array[i]->print();
		cout << "\n площадь = " << array[i]->area() << "\n объем = " << array[i] -> volume() << "\n\n";
	}
	return 0;
}