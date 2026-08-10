//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        if (nums.size() % 2 != 0)
        {
            return false;
        }

        vector<int> count(k, 0);

        for (auto n : nums)
            ++count[n % k];

        int left = 1;
        int right = k - 1;

        while (left < right)
        {
            if (count[left] != count[right])
            {
                return false;
            }
            ++left;
            --right;
        }

        if ((left == right && count[left] % 2 != 0) || count[0] % 2 != 0)
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends