// the union and the intersection of the two sorted array
#include <bits/stdc++.h>
using namespace std;
vector<int> UnionOfTwoArray(vector<int> &array1, vector<int> &array2)
{
    vector<int> UnionArray;
    int n1 = array1.size();
    int n2 = array2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (array1[i] <= array2[j])
        {
            if (UnionArray.size() == 0 || UnionArray.back() != array1[i])
            {
                UnionArray.push_back(array1[i]);
            }
            i++;
        }
        else
        {
            if (UnionArray.size() == 0 || UnionArray.back() != array2[j])
            {
                UnionArray.push_back(array2[j]);
            }
            j++;
        }
    }
    while (j > n2)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != array2[j])
        {
            UnionArray.push_back(array2[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != array1[i])
        {
            UnionArray.push_back(array1[i]);
        }
        i++;
    }
    return UnionArray;
}

vector<int> IntersectionOfTwoSortedArrayBruteForce(vector<int> &array1, vector<int> &array2)
{
    vector<int> ans;
    int visited[array2.size()] = {0};
    for (int i = 0; i < array1.size(); i++)
    {
        for (int j = 0; j < array2.size(); j++)
        {
            if (array1[i] == array2[j] && visited[j] == 0)
            {
                ans.push_back(array1[i]);
                visited[j] = 1;
                break;
            }
            if (array2[j] > array1[i])
                break;
        }
    }
    return ans;
}

vector<int> IntersectionOfTwoSortedArrayOptimal(vector<int> &array1, vector<int> &array2)
{
    int n1 = array1.size();
    int n2 = array2.size();
    vector<int> Intersection;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j])
            i++;
        else if (array2[j] < array1[i])
            j++;
        else
        {
            Intersection.push_back(array1[i]);
            i++;
            j++;
        }
    }
    return Intersection;
}

int main()
{
    vector<int> array1;
    vector<int> array2;
    vector<int> UnionArray;
    vector<int> Intersection;
    int Size1, Size2;
    cout << "Enter the size of the First array " << endl;
    cin >> Size1;
    cout << "Enter the size of the second array " << endl;
    cin >> Size2;
    int a;
    cout << "Input the elements of the first array " << endl;
    for (int i = 0; i < Size1; i++)
    {
        cin >> a;
        array1.push_back(a);
    }
    cout << "Enter the elements of the second array " << endl;
    for (int i = 0; i < Size2; i++)
    {
        cin >> a;
        array2.push_back(a);
    }

    // UnionArray = UnionOfTwoArray(array1, array2);
    // Intersection = IntersectionOfTwoSortedArrayBruteForce(array1, array2);
    Intersection = IntersectionOfTwoSortedArrayOptimal(array1, array2);

    for (int i = 0; i < Intersection.size(); i++)
        cout << Intersection[i] << " ";
    cout << endl;

    return 0;
}