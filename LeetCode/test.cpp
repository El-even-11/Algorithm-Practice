#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159
#define square(x) ((x) * (x))

class Point
{
    int x, y;

public:
    void setPoint(int X, int Y)
    {
        x = X;
        y = Y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void moveOff(int xOff, int yOff)
    {
        x += xOff;
        y += yOff;
    }
};

class ClosedShape
{
public:
    virtual void moveOff(int xOff, int yOff)=0;
    virtual double getArea()=0;
    virtual double getPerimeter()=0;
    virtual void show()=0;
};

class Circle : public ClosedShape
{
    Point p;
    int r;

public:
    Circle(int X, int Y, int R) : r(R)
    {
        p.setPoint(X, Y);
    }
    void moveOff(int xOff, int yOff) override
    {
        p.moveOff(xOff, yOff);
    }
    double getArea() override
    {
        return PI * r * r;
    }
    double getPerimeter() override
    {
        return 2 * PI * r;
    }
    void show() override
    {
        cout << "circle's center is: (" << p.getX() << "," << p.getY() << ")\n";
        cout << "circle's radius: " << r << endl;
        cout << "circle's area: " << getArea() << endl;
        cout << "cirle's perimeter:" << getPerimeter() << endl;
    }
};

class Rectangle : public ClosedShape
{
    Point topLeft;
    int wide;
    int high;

public:
    Rectangle(int X, int Y, int W, int H) : wide(W), high(H)
    {
        topLeft.setPoint(X, Y);
    }
    void moveOff(int xOff, int yOff) override
    {
        topLeft.moveOff(xOff, yOff);
    }
    double getArea() override
    {
        return (double)wide * high;
    }
    double getPerimeter() override
    {
        return ((double)wide + (double)high) * 2.0;
    }
    void show() override
    {
        cout << "rectangle's topleft:(" << topLeft.getX() << "," << topLeft.getY() << ")\n";
        cout << "rectangle's width: " << wide << endl;
        cout << "rectangle's hight: " << high << endl;
        cout << "rectangle's area: " << getArea() << endl;
        cout << "rectangle's perimeter : " << getPerimeter() << endl;
    }
};

class Triangle : public ClosedShape
{
    Point v[3];

public:
    Triangle(int x0, int y0, int x1, int y1, int x2, int y2)
    {
        v[0].setPoint(x0, y0);
        v[1].setPoint(x1, y1);
        v[2].setPoint(x2, y2);
    }
    void moveOff(int xOff, int yOff) override
    {
        v[0].moveOff(xOff, yOff);
        v[1].moveOff(xOff, yOff);
        v[2].moveOff(xOff, yOff);
    }
    double getArea() override
    {
        double AB = sqrt(square(v[0].getX() - v[1].getX()) + square(v[0].getY() - v[1].getY()));
        double AC = sqrt(square(v[0].getX() - v[2].getX()) + square(v[0].getY() - v[2].getY()));
        double vec = (((double)v[0].getX() - (double)v[1].getX()) * ((double)v[0].getX() - (double)v[2].getX()) + ((double)v[0].getY() - (double)v[1].getY()) * ((double)v[0].getY() - (double)v[2].getY()));
        double cos = vec / (AB * AC);
        double sin = sqrt(1 - square(cos));
        return 2 * AB * AC * sin;
    }
    double getPerimeter() override
    {
        return sqrt(square(v[0].getX() - v[1].getX()) + square(v[0].getY() - v[1].getY())) + sqrt(square(v[0].getX() - v[2].getX()) + square(v[0].getY() - v[2].getY())) + sqrt(square(v[1].getX() - v[2].getX()) + square(v[1].getY() - v[2].getY()));
    }
    void show() override
    {
        cout << "triangle's points:(" << v[0].getX() << "," << v[0].getY() << "),(" << v[1].getX() << "," << v[1].getY() << "),(" << v[2].getX() << "," << v[2].getY() << ")\n";
        cout << "triangle's area: " << getArea();
        cout << "triangle's perimeter: " << getPerimeter();
    }
};

int main()
{
    ClosedShape *ptr1, *ptr2, *ptr3;
    ptr1 = new Circle(1, 2, 3);
    ptr2 = new Rectangle(1, 2, 3, 4);
    ptr3 = new Triangle(0, 0, 3, 0, 3, -3);
    ptr1->show();
    ptr2->show();
    ptr3->show();
    return 0;
}