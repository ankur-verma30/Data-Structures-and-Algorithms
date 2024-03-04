#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int>nums{2,3,4,5,6,7,8,9,6,54,3,3,22,1};
    map<int,int,greater<int> >mp;//storing values in descending order 
    for(int i=0;i<nums.size();i++) mp[nums[i]]++;

    cout<<"the elements in nums"<<endl;

    for(auto x:mp){
        cout<<x.first <<" and "<<x.second<<endl;
    }

    priority_queue<int>pq;
    for(int x:nums) pq.push(x);
    cout<<"the elements of the queue "<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}