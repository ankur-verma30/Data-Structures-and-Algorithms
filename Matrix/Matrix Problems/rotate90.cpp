#include<bits/stdc++.h>

using namespace std;

vector<int>Rotate90Deg(int A[][3],int m ,int n){

    vector<int>results;
    int row=m;
    int col=n;

    for(int j=0;j<=col-1;j++){
        for(int i=row-1;i>=0;i--){
            results.push_back(A[i][j]);
        }
    }


    return results;
}

int main(){
    int A[3][3];

    cout << "Enter the elements of the matrix " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }

    // displaying input
    cout << "display the elements of the matrix " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Displaying the results..."<<endl;

    vector<int>results=Rotate90Deg(A,3,3);

     for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }

    return 0;
}