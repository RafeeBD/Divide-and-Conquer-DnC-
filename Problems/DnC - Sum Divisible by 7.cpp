// Find the sum of all elements divisible by 7 in an array using the Divide and Conquer technique.
// Base case: subarray size = 0 or 1
// No loop
// Pure recursion (DnC)

#include<bits/stdc++.h>
using  namespace std;
int sumdivisibleby7(int arr[], int left, int right)
{

    if (left > right)
        return 0;


    if (left == right)
    {
        if (arr[left] % 7 == 0)
            return arr[left];
        else
            return 0;
    }

    int mid = left + (right - left) / 2;

    int leftPart =  sumdivisibleby7(arr, left, mid);
    int rightPart =  sumdivisibleby7(arr, mid + 1, right);

    return leftPart + rightPart;
}



int main()
{
    int arr[] = {14, 3, 21, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = sumdivisibleby7(arr, 0, n - 1) ;

       cout <<"Sum :"<< result<< endl;

    return 0;
}
