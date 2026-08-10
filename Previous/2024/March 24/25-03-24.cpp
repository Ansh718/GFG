//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void helper(vector<string> &result, string number, int extra1, int rem)
    {
        if (0 == rem)
        {
            result.push_back(number);
            return;
        }
        helper(result, number + "1", extra1 + 1, rem - 1);
        if (0 < extra1)
        {
            helper(result, number + "0", extra1 - 1, rem - 1);
        }
    }
    vector<string> NBitBinary(int n)
    {
        vector<string> result;
        string str = "";
        helper(result, str, 0, n);
        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends