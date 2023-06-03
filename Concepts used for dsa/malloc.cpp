#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int a = 10;
  int *p;
  p = &a;
  cout << a << endl
       << *p << endl;
  cout << p << endl
       << &a << endl;
  p = new int[5];
  for (int i = 0; i < 5; i++)
    cin >> p[i];
  for (int i = 0; i < 5; i++)
    cout << p[i] << endl;
  delete[] p;

  return 0;
}
