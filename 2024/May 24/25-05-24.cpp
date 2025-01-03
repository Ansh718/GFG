//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
// #include<Windows.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k)
    {
        // Your code here
        long long res = 0, temp = 0;
        int i = 0;
        while (i < n)
        {
            if (arr[i] <= k)
            {
                temp += arr[i];
            }
            else
            {
                temp = 0;
            }
            res = max(res, temp);
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends