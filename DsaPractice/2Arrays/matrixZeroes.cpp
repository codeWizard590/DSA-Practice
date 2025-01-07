// https://leetcode.com/problems/set-matrix-zeroes/description/
// https://leetcode.com/problems/rotate-image/description/
// https://leetcode.com/problems/spiral-matrix/description/
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    void print(vector<vector<int>> &arr, int m, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void matrixX_BF(vector<vector<int>> &arr)
    {
        // {{1,1,1},{1,0,1},{1,1,1}}
        // intuition -> we want to keep a track of true or false value of elements against the rows and cols they are in
        int n = arr.size();
        int m = arr[0].size();
        vector<int> cols(m, false);
        vector<int> rows(n, false);
        //
        vector<vector<int>> tempArr;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                {
                    cols[j] = true;
                    rows[i] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cols[j] || rows[i])
                {
                    arr[i][j] = 0;
                }
            }
        }
        print(arr, m, n);
    }

    void matrix_OA(vector<vector<int>> &nums)
    {
        int m = nums.size();
        int n = nums[0].size();
        int col0;
        // intution
        // instead of maintaining differently , we can use first row and first column of the array
        // we have one row and col at 0th index coinciding , to remove that we can take one extra variable to store col value

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    nums[i][0] = 0;
                    // nums[0][j]=0; // but in order to eliminate the overriding -> use col0 for storing at j==0;
                    if (j == 0)
                    {
                        col0 = 0;
                    }
                    else
                    {
                        nums[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (nums[0][j] == 0 || nums[i][0] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
        // Mark the first row
        if (nums[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                nums[0][j] = 0;
        }

        // Mark the first column
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
                nums[i][0] = 0;
        }
        print(nums, m, n);
    }

    /*
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
    DO NOT allocate another 2D matrix and do the rotation.
    */
    void matrixxRotation_BF(vector<vector<int>> &nums)
    {
        // first of all i want to observe a pattern and match how i and j are behaving when rotated
        /*
        when [0][0] -> [0][3]   |   [1][0] ->  [0][2]
             [0][1] -> [1][3]   |   [1][1] ->  [1][2]
             [0][2] -> [2][3]   |   [1][2] ->  [2][2]
             [0][3] -> [3][3]   |   [1][3] ->  [3][2]

             one thing is clear that jth index of matrix becomes the ith index ..
             and the relation between ith index and jth  of the temp matrix should be
             n=4 , consider i to j relations such that as i increases j decreases by i n=4 it basically means n-1

        */
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> tempArr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tempArr[j][n - i - 1] = nums[i][j];
            }
        }
        cout << endl;
        print(tempArr, m, n);
    }

    // we don't want to use extra space ..
    // we will try to do this in place ..
    void matrixxRotation_OA(vector<vector<int>> &matrix)
    {
        // intutiion is we take the transpose of the matrix and reverse the order of the rows
        int n = matrix.size();
        int m = matrix[0].size();
        // transpose of the matrix is done
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // next step is to take the reverse of the rows
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (m / 2); j++)
            {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        // we can also use reverse STL

        cout << endl;
        print(matrix, m, n);
    }

    /*
    Given an m x n matrix, return all elements of the matrix in spiral order.
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
    */
    

    // mistakes i made in this ...
    /*
    NOT ABLE TO IDETIFY WHICH VARIABLE TO INCREMENT OR DECREMENT 
    ------------------->SIMPLE SOLUTION IS <-----------------
    got through the dimension identify which variable's task is done 
    as when we go from left to right we know top is not required change it 
    l->r :: top ++;
    r->d :: r-- ; as we need new right now since we have already taken bottom right value 
    r->l :: down -- ; not needed done as sma ecase with the right
    d->u :: l++ ;
    now things to consider are the test cases for 1d matrix also .. keep little things in mind 
    */
    void spiralMatrix(vector<vector<int>> &matrix)
    {
        // to print a spiral matrix
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, u = 0, r = m - 1, d = n - 1;
        // loop through the first spiral and put a while loop
        vector<int> result;
        while (l <= r && u <= d)
        {

            for (int i = l; i <= r; i++)
            {
                result.push_back(matrix[u][i]);
            }
            u++;
            for (int i = u; i <= d; i++)
            {
                result.push_back(matrix[i][r]);
            }
            r--;
            
            if (u <= d)
            {

                for (int i = r; i >= l; i--)
                {
                    result.push_back(matrix[d][i]);
                }
                d--;
            }
            if (l <= r)
            {
                for (int i = d; i >= u; i--)
                {
                    result.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
};
int main()
{
    Matrix matrix;
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    matrix.matrixX_BF(arr);
    matrix.matrix_OA(nums);
    vector<vector<int>> rotate = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    matrix.matrixxRotation_BF(rotate);
    vector<vector<int>> rotate_OA = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    matrix.matrixxRotation_OA(rotate_OA);
    vector<vector<int>> spiral = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    matrix.spiralMatrix(spiral);
}