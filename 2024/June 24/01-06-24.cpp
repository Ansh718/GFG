//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string oddEven(string s)
    {
        map<char, int> mp;
        for (auto S : s)
        {
            mp[S]++;
        }
        int x = 0;
        int y = 0;
        for (auto m : mp)
        {
            if ((m.first - 'a' + 1) % 2)
            {
                if (m.second % 2)
                {
                    y++;
                }
            }
            else
            {
                if (!(m.second % 2))
                {
                    x++;
                }
            }
        }
        int chc = 0;
        chc = x + y;
        if (chc % 2)
        {
            return "ODD";
        }
        else
        {
            return "EVEN";
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends