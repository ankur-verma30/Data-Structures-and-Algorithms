#include <iostream>
using namespace std;
class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle()
    {
        length = breadth = 1;
    }
    Rectangle(int l, int b);
    int area();
    int perimeter();
    int getlength()
    {
        return length;
    }
    void setlength(int l)
    {
        length = l;
    }
    ~Rectangle();
};
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
Rectangle::~Rectangle()
{
}
int main()
{
    Rectangle r(10, 20);
    cout << "Area is =" << r.area() << endl;
    cout << "Perimeter is =" << r.perimeter() << endl;
    r.setlength(20);
    cout << "Lenght of the Rectangle is=" << r.getlength();
    return 0;
}