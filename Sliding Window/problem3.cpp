#include <bits/stdc++.h>
using namespace std;

vector<int> CountAnagrams(string &str1, string &str2)
{
    int len = str2.length();
    int ASCIIsum = 0;
    
    // Calculate the sum of ASCII values for characters in str2
    for (int i = 0; i < len; i++)
        ASCIIsum += str2[i] - 'a';
    
    int start = 0, end = 0;
    int sum = 0;
    vector<int>count;

    while (end < str1.length())
    {
        if (end - start + 1 < len)
        {
            if (end < str1.length()) 
                sum += str1[end] - 'a';
                end++;
        }
        else if (end - start + 1 == len)
        {
            sum += str1[end] - 'a';//"cbaebabacd"
            if (sum == ASCIIsum)  count.push_back(start);  

            // Move the window
            sum -= str1[start] - 'a';
            start++;
            end++;
        }
    }
    return count;
}

int main()
{
    string str1, str2;
    vector<int> result;
    cout << "Enter the two string values " << endl;
    cin>>str1;
    cin>>str2;

    result = CountAnagrams(str1, str2);
    for(int i=0;i<result.size();i++)
    cout<<result[i]<<" ";

    return 0;
}
