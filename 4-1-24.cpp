//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int singleElement(int arr[], int N)
    {
        vector<int> bit(32, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                bit[j] += arr[i] & 1;
                arr[i] >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++)
            if (bit[i] % 3 != 0)
                res += 1 << i;

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
        int N;

        cin >> N;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.singleElement(arr, N);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends