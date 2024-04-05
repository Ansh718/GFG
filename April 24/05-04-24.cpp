//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int longestIS(vector<int> &arr)
    {
        int n = 0;
        n = arr.size();
        vector<int> dP(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && (arr[i] - arr[j]) >= (i - j))
                {
                    dP[i] = max(dP[i], (1 + dP[j]));
                }
            }
        }
        int maX = 0;
        for (auto itr : dP)
        {
            maX = max(maX, itr);
        }
        return maX;
    }
    int min_operations(vector<int> &nums)
    {
        int l = 0;
        l = longestIS(nums);
        int n = 0;
        n = nums.size();
        int res = 0;
        res = n - l;
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends