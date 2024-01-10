//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        int s = 0;
        unordered_map<int, int> sfx;
        sfx[0] = n;

        int result = 0;

        for (int i = n - 1; i > -1; i--)
        {
            s = (s + (arr[i] % k) + k) % k;

            if (!sfx.count(s))
                sfx[s] = i;
            else
                result = max(result, sfx[s] - i);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.longSubarrWthSumDivByK(arr, n, k) << "\n";
    }
    return 0;
}

// } Driver Code Ends