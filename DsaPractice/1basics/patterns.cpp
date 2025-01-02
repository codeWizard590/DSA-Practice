#include <bits/stdc++.h>
using namespace std;
class MatrixPatterns
{
public:
    void squarePattern()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout<<i<<j<<" ";
            }
            cout << endl;
        }
    }
    // we can get these patterns by limting upto which index j or i should iterate .
    void rightAngled()
    {
        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < i + 1; j++)
            {
                // cout<<i<<j<<" ";
                // cout<<j<<" ";
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void invertedRA()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5 - i; j++)
            {
                // cout<<i<<j<<" ";
                // cout<<j<<" ";
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void triangle(int N)
    {
        // for(int i=0;i<n;i++){
        //     // triangle works as printing 1,3,5,7,9.... n -> uses odd numbers

        //     for(int j=0;j<n;j++){
        //        cout<<"*";
        //     }
        //     cout<<endl;
        // }
        for (int i = 0; i < N; i++)
        {
            // For printing the spaces before stars in each row
            // n=5 -> 0 -> 5-0-1 =4 ;
            for (int j = 0; j < N - i - 1; j++)
            {
                cout << " ";
            }

            // For printing the stars in each row
            for (int j = 0; j < 2 * i + 1; j++)
            {

                cout << "*";
            }

            // For printing the spaces after the stars in each row
            for (int j = 0; j < N - i - 1; j++)
            {
                cout << " ";
            }

            // As soon as the stars for each iteration are printed, we move to the
            // next row and give a line break otherwise all stars
            // would get printed in 1 line.
            cout << endl;
        }
    }
};
int main()
{
    MatrixPatterns pattern;
    pattern.squarePattern();
    cout << endl;
    pattern.rightAngled();
    cout << endl;
    pattern.invertedRA();
    cout << endl;
    pattern.triangle(5);
}