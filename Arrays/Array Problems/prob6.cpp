//  rotate the array to the left with k positions
#include <bits/stdc++.h>

using namespace std;

void RotatedArrayToLeft(vector<int> &left, int k)
{
    k = k % left.size();
    int temp[k];

    for (int i = 0; i < k; i++)
        temp[i] = left[i]; // storing the values in the array which will be added at the back

    for (int i = k; i < left.size(); i++)
        left[i - k] = left[i]; // shifting the rest of the value to the front

    for (int i = left.size() - k; i < left.size(); i++)
        left[i] = temp[i - left.size() + k]; // adding the value at the back of the array
}
void RotateArrayUsingReverse(vector<int>&left, int k){
    k=k%left.size();
    reverse(left.begin(),left.begin()+k);
    reverse(left.begin()+k,left.end());
    reverse(left.begin(),left.end());
}
int main()
{
    vector<int> left;
    int N;
    cout << "the size of the array " << endl;
    cin >> N;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        left.push_back(a);
    }
    int k;
    cout << "the number of position you want to shift the array " << endl;
    cin >> k;
    // RotatedArrayToLeft(left, k);
    RotateArrayUsingReverse(left, k);
    cout << "the array is rotated by " << k << "position to the left" << endl;
    for (int i = 0; i < N; i++)
        cout << left[i] << " ";
    cout << endl;
}