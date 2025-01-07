#include <bits/stdc++.h>
using namespace std;
class MajorityElement
{
public:
    // element which occurs more than n/2 times
    int majority_BF(vector<int> arr)
    {
        int n = arr.size();
        // {2,2,1,1,1,2,2};
        // i want to check how many times 2/1 is coming
        int focusFrequency = n / 2, maxOc = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > focusFrequency)
            {
                maxOc = arr[i];
            }
        }
        return maxOc;
    }

    // another approach that is coming to me is using hashmap
    void majority_BA(vector<int> arr)
    {
        // [2,2,1,1,1,2,2]
        // using hashmap to store the max frequency element s
        map<int, int> mpp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]] += 1;
            // mpp[3]=mpp[3]=mpp[3]+1;
        }
        int m = mpp.size();

        // for iterating inside a map we use this  .. first is key ----> and second is value .
        for (auto it : mpp)
        {
            if (it.second > n / 2)
            {
                cout << it.first;
            }
            // cout<<endl;
            // cout<<"map iteration : " << it.first << ":  " << it.second << endl;
        }
        // this will give results as  -> 0 , 0 , 0 as we are trying to access 0 ,1 ,2 which map doesn't have -> returns 0,0,0
        // but as we put mpp[arr[i]] -> it will take three outputs its frequency -> mpp[3] -> occurs 2 times again mpp[3] -> 2 times
        // and then mpp[4] -> which occurs one time ..

        // instead of this
        // for (int i = 0; i < n; i++)
        // {
        //     cout << mpp[i];
        // }
        // // use this .. this is also incorrect as 3 is doubled for giving output
        // for (int i = 0; i < n; i++)
        // {
        //     cout << mpp[arr[i]];
        // }
    }

    // we need to come up with a solution which has O(n) space ..
    void majority_OA(vector<int> arr)
    {
        // [2,2,1,1,1,2,2]
        // now without looking into this algorithm we cannot predict something like this beforehand . this feels like these
        // are just some areas where we learn to code but still let us learn their way
        // becuase these are some algorithms i feel are case specific
        int n = arr.size();
        int element = -1, count = 0;
        for (int i = 0; i < n; i++)
        {
            // the intution is to go iterate through the array
            // keep a count variable which just keeps a track of selected element occurence upto an index the count becomes zero
            // the track of count is kept in such a way that if the element at arr[i] is other than the selected element count -- else count++;
            // we take new element gets on iterating after the index count becomes zero agai same process
            // element=arr[i];
            if (count == 0)
            {
                element = arr[i];
                count++;
            }
            else
            {
                if (element == arr[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        //  now we have got the element which doesnot gets cancelled out
        // if there exists an element this is the element
        //  now we need to check if the element's frequency is more than n/2
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element)
            {
                val++;
            }
        }
        if (val > n / 2)
        {
            // cout<<element;
            cout << endl
                 << "using Bayers moore algorithm : " << element;
        }
        else
        {
            cout << "no element exists " << endl;
        }
    }
    
    // https://leetcode.com/problems/majority-element-ii/description/
    // Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
    void majority3_BF(vector<int> arr){
        int n=arr.size();
        vector<int> result;
       
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            if(count>n/3){
                result.push_back(arr[i]);
            }
            
        }
        cout<<"majority 3 using brute force :[";
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<"]";
    }

    void majority3_HT(vector<int> arr){
        // using hashmap
        vector<int> temparr;
        int n=arr.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int value=arr[i];
            mpp[value]+=1;            
        }
        for(auto it:mpp){
            if(it.second>n/3){
                temparr.push_back(it.first);
            }
        }
        cout<<"using hashing : ";
        for(int i=0;i<temparr.size();i++){
            cout<<temparr[i]<<" ";
        }
    }

    void majority3_OA(vector<int> arr){
        
    }
};
int main()
{
    MajorityElement majorityElement;
    vector<int> arr = {1, 2};
    int element = majorityElement.majority_BF(arr);
    cout << element << " " << endl;
    majorityElement.majority_BA(arr);
    majorityElement.majority_OA(arr);
    cout<<endl;
    majorityElement.majority3_BF(arr);
    cout<<endl;
    majorityElement.majority3_HT(arr);
}