#include <iostream>
using namespace std;
class Rectangle
{
    int length;
    int breadth;

public:
    // and we have to make a constructor for the initilization of the values
    Rectangle(int l, int b)
    // void initialize(int l,int b)//instead of using an extra function for initialization it can be done in main itself infront of the objects;
    {
        length = l, breadth = b;
    }
    void changelenght(int l)
    {
        length = l;
    }
    int area()
    {
        return length * breadth;
    }
};
int main()
{
    Rectangle r(10, 20);
    // r.initialize(10,20);
    r.changelenght(20);
    cout << "Area of the Rectangle = " << r.area();
    return 0;
}
