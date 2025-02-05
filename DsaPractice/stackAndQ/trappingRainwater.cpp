/*https://leetcode.com/problems/trapping-rain-water/description/*/

#include<bits/stdc++.h>
using namespace std;
class Rainwater{
    // there are four different approaches to this .
    // starting with brute force solution
    /*
    Brute force approach :
        the intution behind this is we look towards our right and left .
        we find out the max box in the left of the array as well as to the right .
        now we need to check the place at which we are iterating . 
        assume the tallest box to the left is 3 and the tallest box to the right is 4 . 
        if we are standing at say box which has a height 2 ->
        we will look at both sides -> 3 | 2 | 4
        we need to consider min(left and right) and subtract that value by 2
        min(left , right )-arr[i];
    */
    public:
    /*
    Brute force solution -> uses time complexity of (n-2)n -> n^2-2n-> 0(n^2) 
    */
        int maxWater_BF(vector<int> arr){
            int n=arr.size();
            int waterstored=0;
            for(int i=1;i<n-1;i++){
                int maxleft=arr[i];
                int maxright=arr[i];
                // finding max left 
                for(int j=0;j<i;j++){
                    maxleft=max(maxleft,arr[j]);
                }
                // finding max right
                for(int k=i;k<n;k++){
                    maxright=max(maxright,arr[k]);
                }
                // now i need to check from where i am standing what how much water that block can hold 
                int minWater=min(maxleft,maxright);
                waterstored+=minWater-arr[i];
            }
            return waterstored;
        }
/*
    Better approach . focusing on reducing time complexity and using extra space ; 2n
    we can store leftmax in an array and rightmax in another array .
*/
        int maxWater_BA(vector<int> arr){
            int n=arr.size();
            vector<int> leftmax(n,0),rightmax(n,0);
            int maxEl=0;int sum=0;
            for(int i=0;i<n;i++){
                maxEl=max(maxEl,arr[i]);
                leftmax[i]=maxEl;
            }
            maxEl=0;
            for(int i=n-1;i>=0;i--){
                maxEl=max(maxEl,arr[i]);
                rightmax[i]=maxEl;
            }
            
            for(int i=0;i<n;i++){
                int minLR=min(leftmax[i],rightmax[i]);
                if(leftmax[i]>arr[i]&&rightmax[i]>arr[i]){
                    sum+=minLR-arr[i];
                }
            }
            return sum;
        }
/*
    Using tow pointers approach ..
    the intuition over here is we don't need to maintain two space of leftmax and rightmax in order to check whether any bigger box
    is available ..
        
*/
        int maxWater_OA(vector<int> arr){
            int n=arr.size();int count=0;
            int leftmax=arr[0];int left=0;
            int rightmax=arr[n-1];int right=n-1;
            // doing != check will cause heap overflow .
            while(left<=right){
                // left and right will communnicate 
                // left will only rtell right to traverse backward if he says he found something greater than rightmax
                if(arr[left]<=arr[right]){
                    leftmax=max(leftmax,arr[left]);
                    count+=leftmax-arr[left];
                    left++;
                }
                else{
                    rightmax=max(rightmax,arr[right]);
                    count+=rightmax-arr[right];
                    right--;
                }
            } 
            return count;
        }

};
int main(){
    vector<int> arr={4,2,0,3,2,5};
    Rainwater maxharvest;
    int water= maxharvest.maxWater_BF(arr);
    cout<<"water stored using brute force is  : "<<water<<endl;
    int waterBA=maxharvest.maxWater_BA(arr);
    cout<<"water stored using better approach is  : "<<waterBA<<endl;
    int waterOA=maxharvest.maxWater_OA(arr);
    cout<<"water stored using optimal approach is : "<<waterOA;

}