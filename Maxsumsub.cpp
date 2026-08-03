#include<bits/stdc++.h>
using namespace std;

int crossingsum(vector<int> lefthalf, vector<int> righthalf)
{
    int sum = 0;
    int leftsum = INT_MIN;
    int rightsum = INT_MIN;

    // Left part (right to left)
    for(int i = lefthalf.size() - 1; i >= 0; i--)
    {
        sum += lefthalf[i];
        leftsum = max(leftsum, sum);
    }

    // Reset sum
    sum = 0;

    // Right part (left to right)
    for(int i = 0; i < righthalf.size(); i++)
    {
        sum += righthalf[i];
        rightsum = max(rightsum, sum);
    }

    return leftsum + rightsum;
}

int mss(vector<int> &v, int n)
{
    if(n == 0)
        return INT_MIN;

    if(n == 1)
        return v[0];

    vector<int> lefthalf, righthalf;

    int mid = n / 2;

    for(int i = 0; i < mid; i++)
    {
        lefthalf.push_back(v[i]);
    }

    for(int i = mid; i < n; i++)
    {
        righthalf.push_back(v[i]);
    }

    int leftsum = mss(lefthalf, lefthalf.size());
    int rightsum = mss(righthalf, righthalf.size());
    int crosssum = crossingsum(lefthalf, righthalf);

    return max(leftsum, max(rightsum, crosssum));
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Maximum Sum: " << mss(v, n) << endl;

    return 0;
}
