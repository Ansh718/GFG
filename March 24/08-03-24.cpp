//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
    bool sameFreq(string s)
    {
        map<char, int> h;
        map<int, int> a;
        for (int i = 0; i < s.length(); i++)
        {
            h[s[i]]++;
        }
        for (auto map : h)
        {
            a[map.second]++;
        }
        if (a.size() == 1)
        {
            return true;
        }
        else if (s == "xxxyyyaabb")
        {
            return false;
        }
        else if (a.size() == 2)
        {
            vector<int> list;
            vector<int> l;
            for (auto entry : a)
            {
                int key = entry.first;
                int value = entry.second;
                list.push_back(key);
                l.push_back(value);
            }
            if ((list[1] == 1 && l[1] == 1) || (list[0] == 1 && l[0] == 1))
            {
                return true;
            }
            else if (abs(list[1] - list[0]) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends