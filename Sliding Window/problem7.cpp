/*Longest Substring with no repeating characters*/
#include<bits/stdc++.h>

using namespace std;

int LongestSubstringWithNoRepetition(string nums){
    int mx=0;
    int len=nums.length();
    int i=0,j=0;
    unordered_map<char,int>mp;


    while(j<len){
        mp[nums[j]]++;
        if((int)mp.size()==j-i+1){
            mx=max(mx,j-i+1);
            j++;
        }
        if((int)mp.size()<j-i+1){
            while((int)mp.size()<j-i+1){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
             j++;
        }
       
    }
    return mx;
}

int main(){
    string nums;
    cout << "Enter the string ";
    cin >> nums;
    int result = LongestSubstringWithNoRepetition("pwwkew");
    cout << "the length of the longest substring is " << result << endl;
}