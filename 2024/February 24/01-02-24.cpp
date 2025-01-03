//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool checkPangram(string s)
    {
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            char c = tolower(s[i]);
            if (c >= 'a' && c <= 'z')
            {
                hash[c - 'a']++;
            }
        }
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return (0);
}

// } Driver Code Ends