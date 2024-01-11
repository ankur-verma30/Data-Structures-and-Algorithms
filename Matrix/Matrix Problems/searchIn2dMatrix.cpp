#include<bits/stdc++.h>

using namespace std;

bool searchIn2DMatrix(int A[][4],int m, int n,int target){
    int low=0;
    int high=m*n-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        int elements=A[mid/n][mid%n];

        if(elements==target)  return 1;
        else if(elements<target)  low=mid+1;
        else high=mid-1;
    }
    return 0;
}

int main(){
    int A[3][4];

    cout << "Enter the elements of the matrix " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
        }
    }

    // displaying input
    cout << "display the elements of the matrix " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Enter the target element of the matrix " << endl;
    int target;
    cin >> target;

    cout<<"Displaying the results..."<<endl;
    cout<<boolalpha;

    cout<<"the element is present in the matrix ..."<<searchIn2DMatrix(A,3,4,target);

    return 0;

}