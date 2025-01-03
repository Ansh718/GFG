//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string removeDuplicates(string str)
    {
        string result;
        vector<char> s;
        for (char c : str)
        {
            if (find(s.begin(), s.end(), c) == s.end())
            {
                s.push_back(c);
            }
        }
        for (char c : s)
        {
            result += c;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends