#include<bits/stdc++.h>

using namespace std;

vector<int>SprialMatrix(int A[][5],int m, int n){

    int count=0;
    int total=m*n;

    vector<int>results;

    int starting_row=0;
    int starting_col=0;
    int ending_row=m-1;
    int ending_col=n-1;

    while(count<total){

        //print starting row

        for(int index=starting_col; count<total && index<=ending_col;index++){
            results.push_back(A[starting_row][index]);
            count++;
        }
        starting_row++;

        //ending_col printing

        for(int index=starting_row; count<total && index<=ending_row; index++){
            results.push_back(A[index][ending_col]);
            count++;
        }
        ending_col--;

        //priting ending row

        for(int index=ending_col; count<total && index>=starting_col; index--){
            results.push_back(A[ending_row][index]);
            count++;
        }
        ending_row--;

        for(int index=ending_row; count<total && index>=starting_row;index--){
            results.push_back(A[index][starting_col]);
            count++;

        }
        starting_col++;

    }

    return results; 

}

int main(){
    int A[5][5];

    cout << "Enter the elements of the matrix " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
        }
    }

    // displaying input
    cout << "display the elements of the matrix " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Displaying the results..."<<endl;

    vector<int>results=SprialMatrix(A,5,5);

     for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }

    return 0;
}