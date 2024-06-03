//finding the unique subsets in the given nums containing the duplicate elements

#include<bits/stdc++.h>

using namespace std;

void  findAllSubsets(int index,vector<int>& arr,vector<int>&ds,vector<vector<int>>&res){
    res.push_back(ds);
    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        findAllSubsets(i+1,arr,ds,res);
        ds.pop_back();
    }
}

int main(){
    vector<int>arr{1,2,3,2,3,2};

    sort(arr.begin(), arr.end());
    vector<int>ds;
    vector<vector<int> >res;

    findAllSubsets(0,arr,ds,res);

    cout<<"the unique subsets are ";
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}