/*Longest Substring with k-unique characters */
#include <bits/stdc++.h>

using namespace std;

int LongestSubstring(string nums, int unique)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int len = nums.length();
    int mx = 0;
    while (j < len)
    {

        mp[nums[j]]++;

        if (mp.size() < unique)
        {
            if (j < len)
                j++;
        }

        if (mp.size() == unique)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        if (mp.size() > unique)
        {
            while (mp.size() > unique)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}
int main()
{
    string nums;
    cout << "Enter the string ";
    cin >> nums;
    cout << "Enter the number of unique characters ";
    int unique;
    cin >> unique;
    int result = LongestSubstring(nums, unique);
    cout << "the length of the longesst substring is " << result << endl;

    return 0;
}