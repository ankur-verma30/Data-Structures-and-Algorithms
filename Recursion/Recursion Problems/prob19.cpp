#include <iostream>
using namespace std;

int Sum(int n) {
    if (n == 0) // Base case: If n is 0, return 0
        return 0;
        
    int a = n / 2;
    int b = n / 3;
    int c = n / 4;
    int sum = a + b + c; // Sum up the fractions
    if (sum > n) 
        return Sum(a) + Sum(b) + Sum(c); // Recursive call with fractions
    else 
        return n; // If sum is not greater than n, return n
}

int maxSum(int n) {
    int res = Sum(n);
    return (res > n) ? res : n;
}

int main() {
    int n = 24; // Example input
    cout << "Max Sum: " << maxSum(n) << endl;
    return 0;
}
