#include <bits/stdc++.h>
using namespace std;
/*
this type of algorithm / approach is basically used for finding two sum ,three sum trapping rain water .

*/
int lonestSubarr(vector<int> arr, int k)
{
    int n = arr.size();
    int i = 0;
    int j = 0;
    // the aim is to use  pointers i and j  to find the longest subarr with sum k
    // {10,5,2,7,1,9};
    int maxlength = 0;
    int count = 0; //  i=0 -> count =10 .i=1 -> count =15 .i=2 , maxlength =2-> count =17 ,j=1 count 7; i=3 ->count =14 ->
    while (i < n)
    {
        // i=4 count=15 maxlength->4-1+1 =4; ,i=5 ->24 -
        count += arr[i];
        if (count == k)
        {
            maxlength = max(maxlength, i - j + 1);
        }
        while (count > k && j <= i)
        {
            count = count - arr[j];
            j++;
        }
        i++;
    }
    return maxlength;
}
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int output = lonestSubarr(nums, k);
    cout << output;
}