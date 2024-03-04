#include<bits/stdc++.h>

using namespace std;

    bool isPossibleToSplit(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int len=nums.size();
        int distinct=nums[0];
        int count=0,maxCount=0;
        
        
        for(int i=0;i<len;i++){
            if(distinct==nums[i]){
                count++;
                maxCount=max(count,maxCount);
            }
            else{
                count=0;
                distinct=nums[i];
            }
        }
        return (maxCount<=2)?true:false;
    }

    int main(){
        vector<int>nums{6,1,3,1,1,8,9,2};
        cout<<boolalpha;
        cout<<isPossibleToSplit(nums)<<endl;
        return 0;
    }