// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<bits/stdc++.h>
using namespace std;
class Stocks{
    /*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy
    one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction.
    If you cannot achieve any profit, return 0.
    */
    public : 
    /*
        brute force says check by buying on day 0->n
        in the inner loop sell at i+1;
        check the max value which can be gained by subtrating the sellvalue from the buy value 
    */
        void stocks_BF(vector<int> nums){
            // [7,1,5,3,6,4] 
            int n=nums.size();
            int maxProfit=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    maxProfit=max(maxProfit,nums[j]-nums[i]);
                }
            }
            cout<<maxProfit<<endl;
        }
        void stocks_OA(vector<int> nums){
            int n=nums.size();
            int bought=nums[0],profit=0;
            //[7,2,5,10,1,6,4] 
            // --> 7>2 -> bought at 2 -> 5-2=3,3-2=1,1-2 --> none,6-2 -> 4 --> 4-2 ->2
            // --> if profit is in - i know 
            for(int i=1;i<n;i++){
                // i will check if i have bought the stock at the right price and the 
                // profit i will make selling that at remaining iterations
                //if i have bought at incorrect price i will simply update that price with the new price 
                if(bought>nums[i]){
                    bought=nums[i];
                } 
                profit=max(profit,nums[i]-bought);
            }
            cout<<profit;
        }
};
int main(){
    vector<int> nums={7,1,5,3,6,4};
    Stocks stocks;
    stocks.stocks_BF(nums);
    stocks.stocks_OA(nums);
}