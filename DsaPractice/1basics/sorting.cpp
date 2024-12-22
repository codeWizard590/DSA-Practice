#include <bits/stdc++.h>
using namespace std;
// the purpose of revisiting these sorting algorithms is it uses the basic of every logic that you can come up with in an array
// this is my 3rd time revising these algorithms since i started ..
// i still am making a lot of mistakes not able to think how to write the code brain just freezes and i have 2.5 years of experience in web dev.
// this is bad ..  really bad
// even if it takes 100 revisions i will still continue
class Solution
{
public:
    void printArr(vector<int> arr, string sortType)
    {
        int n = arr.size();
        cout << sortType << " : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // the intention behind selection sort is that we iterate through the array find the min element in the inner loop and swap the element
    // [3,6,9,1,2,6] ->1. first thing is to find the min element
    // time complexity for selection sort is O(n^2) ;
    void selectionSort(vector<int> arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int minEle = arr[i];
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (minEle > arr[j])
                {
                    minEle = arr[j];
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
        printArr(arr, "selection sort");
    }

    // bubble sort ->
    //  the intention is to check the adjacent elements and swap them if the element is smaller
    //[4,6 ,6,7,1,3] - >

    // mistakes i was making -> not able to compare adjacent elements simple answer to that is we should compare j and j+! for that
    // was not defining the boundary conditions correctly after each pass of the array the largest element is shifted to the last so n should be n-1 for outer loop
    // for inner loop it should be n-1-i as the last elements are already sorted with each i incrementing
    //  i was not considering the j comparison in the inner loop i should have compared j with the j for minimum error
    //  i am kind of obsessed with i i suppose
    // time complexity for bubble sort is O(n^2)
    void bubbleSort(vector<int> arr)
    {
        int n = arr.size();
        bool swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j + 1], arr[j]);
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }
        }
        printArr(arr, "bubble sort");
    }

    // insertion sort
    // the idea is to consider the array as a deck of cards and consider oen half of the array sorted and other half as not sorted
    // we wil pick a card and put it at its  correct position in the sorted array by shifting other elements one place right
    // [4, 6, 2, 6, 7, 1, 3]

    // mistakes i have been making in this
    // again i was not taking j inside the while loop
    // understand this when we are searching or traversing between two adjacent elements conider taking innner loop vaiable
    void insertionSort(vector<int> arr)
    {
        int n = arr.size();
        // we need a sorted array , so start iterating from 1
        // we need to keep in mind at which element are we looking
        for (int i = 1; i < n; i++)
        {
            int key = arr[i], j = i - 1;
            while (key < arr[j] && j >= 0)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            // cout<<"i: "<<i<<" j:"<<j<<" ";
            arr[j + 1] = key;
        }
        printArr(arr, "insertion Sort");
    }
};

class MergeSort:public Solution
{
public:
    void combine(vector<int> &arr ,int l,int mid,int r){
        vector<int> tempArr;
        int leftIterator=l;
        int rightIterator=mid+1;
        
        while(leftIterator<=mid && rightIterator<=r ){
            if(arr[leftIterator]>=arr[rightIterator]){
                tempArr.push_back(arr[rightIterator]);
                rightIterator++;
            }
            else{
                tempArr.push_back(arr[leftIterator]);
                leftIterator++;
            }
        }
        while(rightIterator<=r){
                tempArr.push_back(arr[rightIterator]);
                rightIterator++;
        }
        while(leftIterator<=mid){
                tempArr.push_back(arr[leftIterator]);
                leftIterator++;
        }

        for(int i=l;i<=r;i++){
            arr[i]=tempArr[i-l];
        }

               
    }
    // {4, 6, 2, 6, 7, 1, 3, 87, 46, 22, 0} // 11 -> 11/2 --> 5
    // 0 -> mid : ( 0 ,5 ) -> 
    void merge(vector<int> &arr,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            merge(arr,l,mid);
            merge(arr,mid+1,r);
            combine(arr,l,mid,r);
        }
    }
    // approach ->
    // the intention behind merge sort is we divide and conquer . basically dividing and backtracking -> reduces complecity to log n
    // reduce the element to its basic form and then join them again ..
    // hurdles faced -> i made a mistake while i was trying to put the temp array values  into the original array 
    // this i-l logic for getting the temp values from the array is because the temp array resets everytime it goes to the loop 
    // doen't know which position it is holding in the original array .... 

    void mergeSort(vector<int> &arr)
    {
        int n = arr.size();
        merge(arr,0,n);
        printArr(arr,"from merge/sort class");
    }

};

// quick sort works on the same approach of divide and conquer ..
// we pick an element which we refer aas pivot .. can be any element 
// for simplicity we take i->0 as pivot .. 
// pick a pivot place the elements around it  .. -> smaller to the left , larger to the right 
// over here we also use recursion ..


class QuickSort:public Solution{
    public:
        void quickSort(vector<int> arr){
            int n=arr.size();

        }
};
int main()
{
    vector<int> arr = {4, 6, 2, 6, 7, 1, 3, 87, 46, 22, 0};
    Solution solution;
    solution.selectionSort(arr);
    solution.bubbleSort(arr);
    solution.insertionSort(arr);
    MergeSort mergeSort;
    mergeSort.mergeSort(arr);

    // As array is passed by refernce now array is sorted in the main thread itself
    vector<int> arr1 = {4, 6, 2, 6, 7, 1, 3, 87, 46, 22, 0};
    QuickSort quickSort;
    quickSort.quickSort(arr1);
    // mergeSort.printArr(arr,"inheritence call");
}