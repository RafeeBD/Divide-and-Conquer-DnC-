#include<bits/stdc++.h>
using namespace std;

int findmin(vector<int> v)
{
    if(v.size() == 1)
    {
        return v[0];
    }
    vector <int> lefthalf,righthalf;

    for(int i = 0;i<v.size()/2;i++)
    {
        lefthalf.push_back(v[i]);
    }

    for(int i = v.size()/2;i<v.size();i++)
    {
        righthalf.push_back(v[i]);
    }


    return  min(findmin(lefthalf),findmin(righthalf));


}
int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0;i < n ; i++ )
    {
    cin >> v[i];
    }

    cout<< "Min is : "<< findmin(v) << endl;

}
