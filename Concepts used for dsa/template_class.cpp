#include <iostream>
using namespace std;
template <class t>
class algebra
{
    t a;
    t b;

public:
    algebra(t a, t b);
    t add();
    t sub();
};
template <class t>
algebra<t>::algebra(t a, t b)
{
    this->a = a;
    this->b = b;
}
template <class t>
t algebra<t>::add()
{
    t c;
    c = a + b;
    return c;
}
template <class t>
t algebra<t>::sub()
{
    t c;
    c = a - b;
    return c;
}
int main()
{
    algebra<int> ar(10, 5);
    cout << "sum of the numbers are = " << ar.add() << endl;
    cout << "Difference of number is = " << ar.sub() << endl;
    algebra<float> ar2(10, 5);
    cout << "sum of the numbers are = " << ar2.add() << endl;
    cout << "Difference of number is = " << ar2.sub();
    return 0;
}
