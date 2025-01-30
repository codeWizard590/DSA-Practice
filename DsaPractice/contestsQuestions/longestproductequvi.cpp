// https://leetcode.com/contest/weekly-contest-431/problems/maximum-subarray-with-equal-products/

#include<bits/stdc++.h>
using namespace std;

/*
You are given an array of positive integers nums.
An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.

Example 1:
Input: nums = [1,2,1,2,1,1,1]
Output: 5
Explanation: 
The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:
Input: nums = [2,3,4,5,6]
Output: 3
Explanation: 
The longest product equivalent subarray is [3, 4, 5].
*/


int main(){
    int x=__gcd(2,3);
    cout<<x;
}