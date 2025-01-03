//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        vector<int> hash(26, 0);
        priority_queue<int> priorQ;
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > 0)
            {
                priorQ.push(hash[i]);
            }
        }
        while (k > 0 && priorQ.size() > 0)
        {
            int temp = 0;
            temp = priorQ.top();
            priorQ.pop();
            temp -= 1;
            if (temp)
            {
                priorQ.push(temp);
            }
            k -= 1;
        }
        while (priorQ.size() > 0)
        {
            result += (priorQ.top() * priorQ.top());
            priorQ.pop();
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
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends