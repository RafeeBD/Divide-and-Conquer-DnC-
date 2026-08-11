/*
divide and conquer: maximum subarray product

write a program to find the maximum product of a contiguous
subarray within an integer array using a divide-and-conquer strategy.

constraints:
- array may contain positive, negative, and zero integers.
- use divide and conquer with o(n log n) time complexity or better.
- do not use nested loops over the entire array (brute force is not allowed).

sample input:
array: [2, 3, -2, 4]

sample output:
maximum product: 6

sample input:
array: [-2, 0, -1]

sample output:
maximum product: 0
*/
#include <bits/stdc++.h>
using namespace std;

long long maxcrossingproduct(vector<int>& arr, int left, int mid, int right)
{
    long long leftmax = LLONG_MIN;
    long long leftmin = LLONG_MAX;
    long long rightmax = LLONG_MIN;
    long long rightmin = LLONG_MAX;

    long long product = 1;

    for (int i = mid; i >= left; i--)
    {
        product *= arr[i];
        leftmax = max(leftmax, product);
        leftmin = min(leftmin, product);
    }

    product = 1;

    for (int i = mid + 1; i <= right; i++)
    {
        product *= arr[i];
        rightmax = max(rightmax, product);
        rightmin = min(rightmin, product);
    }

    return max({
        leftmax * rightmax,
        leftmax * rightmin,
        leftmin * rightmax,
        leftmin * rightmin
    });
}

long long maxproduct(vector<int>& arr, int left, int right)
{
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;

    long long leftproduct = maxproduct(arr, left, mid);
    long long rightproduct = maxproduct(arr, mid + 1, right);
    long long crossproduct = maxcrossingproduct(arr, left, mid, right);

    return max({leftproduct, rightproduct, crossproduct});
}

int main()
{
    vector<int> arr1 = {2, 3, -2, 4};

    cout << "array: [2, 3, -2, 4]" << endl;
    cout << "maximum product: "
         << maxproduct(arr1, 0, arr1.size() - 1) << endl;

    cout << endl;

    vector<int> arr2 = {-2, 0, -1};

    cout << "array: [-2, 0, -1]" << endl;
    cout << "maximum product: "
         << maxproduct(arr2, 0, arr2.size() - 1) << endl;

    return 0;
}
