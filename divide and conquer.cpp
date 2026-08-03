#include <bits/stdc++.h>
using namespace std;

void divideandconquer(vector<int> v)
{

    if (v.size() == 1)
    {
        return;
    }

    vector<int> lefthalf, righthalf;


    for (int i = 0; i < v.size() / 2; i++)
    {
        lefthalf.push_back(v[i]);
    }

    for (int i = v.size() / 2; i < v.size(); i++)
    {
        righthalf.push_back(v[i]);
    }

  
    divideandconquer(lefthalf);
    divideandconquer(righthalf);

   
}

int main()
{
    vector<int> v = {-1, 3, 5, 6, 7, 5};

    divideandconquer(v);

    return 0;
}