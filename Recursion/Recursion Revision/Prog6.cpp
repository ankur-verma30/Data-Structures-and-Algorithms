//Find the nth fibonacci number

#include<bits/stdc++.h>

using namespace std;

int sum=0;
int Fibonacci(int n){
    if(n<=1) return n;
    return Fibonacci(n-1)+Fibonacci(n-2);

}
int main(){
    int n;
    cout<<"Enter the number ";
    cin >> n;
    cout<<"The nth fibonacci number is "<<Fibonacci(n)<<endl;

}