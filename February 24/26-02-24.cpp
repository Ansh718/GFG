//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string helper(string s, int ind)
    {
        int k = 0;
        string res;
        while (ind > 0)
        {
            if (ind & 1)
            {
                res.push_back(s[k]);
            }
            k += 1;
            ind = ind >> 1;
        }
        return res;
    }
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> result;
        for (int i = 1; i <= ((1 << s.size()) - 1); i++)
        {
            result.push_back(helper(s, i));
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends