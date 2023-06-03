// in structure array can be passed as paramter by call by value if it is a data memeber of structure;
#include <iostream>
using namespace std;
struct test
{
    int a[5];
    int n;
};
void fun(struct test t1)
{
    cout << t1.a[0] << " " << t1.a[3];
}
int main()
{
    struct test t = {{2, 4, 6, 8, 10}, 5};
    fun(t);
    return 0;
}