#include<bits/stdc++.h>
using namespace std;
vector<int>mymerge(vector <int> lefthalf ,vector <int> righthalf)
{
    vector <int> result;
    int i = 0;
    int j = 0;
    lefthalf.push_back(INT_MAX);
    righthalf.push_back(INT_MAX);
    while(!(lefthalf[i] == INT_MAX && righthalf[j] == INT_MAX ))
    {
        if(lefthalf[i] < righthalf[j])
        {
            result.push_back(lefthalf[i]);
            i++;
        }
    else
        {
        result.push_back(righthalf[j]);
        j++;
        }

    }
        return result;
}
vector<int>mergesort(vector<int> v)
{
 if(v.size() == 1)
 {
     return v;
 }
 vector<int> lefthalf,righthalf;
 for(int i =0;i < v.size()/2;i++)
 {
 lefthalf.push_back(v[i]);
 }
 for(int i = v.size()/2;i < v.size();i++)
 {
     righthalf.push_back(v[i]);
 }
 lefthalf = mergesort(lefthalf);
 righthalf =  mergesort(righthalf);

 vector <int> result = mymerge(lefthalf,righthalf);
 return result;
}

int main()
{
    int n;
    cout << "Enter Element Number" << endl;

    cin >> n;

    vector <int> v(n);
    cout << "Elements : " << endl;
    for(int i = 0 ; i < n;i++)
    {
        cin >> v[i];
    }
    v = mergesort(v);
    cout << "Output is :" << endl ;
    for( int i =0 ;i<n ;i++)
    {
        cout << v[i] << " " ;
    }

    return 0;
}
