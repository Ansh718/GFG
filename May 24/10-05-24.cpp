//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void findCombinations(vector<int> &arr, int index, int target, vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i < arr.size(); ++i)
        {
            if (arr[i] > target)
            {
                continue;
            }
            if (i > index && arr[i] == arr[i - 1])
            {
                continue;
            }
            current.push_back(arr[i]);
            findCombinations(arr, i + 1, target - arr[i], current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(arr, 0, k, current, result);
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto obj = ob.CombinationSum2(arr, n, k);
        for (int i = 0; i < obj.size(); i++)
        {
            for (int j = 0; j < obj[i].size(); j++)
            {
                cout << obj[i][j] << " ";
            }
            cout << "\n";
        }
        if (obj.size() == 0)
            cout << "\n";
    }
    return 0;
}
// } Driver Code Ends