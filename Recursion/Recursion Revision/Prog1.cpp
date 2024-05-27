#include<bits/stdc++.h>

using namespace std;

int countNum=0;

void count(){
    if(countNum>4) return;
    cout<<countNum<<endl;
    countNum++;
    count();
}

int main(){
    cout<<"Using Recursive call "<<endl;
    count();
    return 0;
}