//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> jugglerSequence(int n)
    {
        vector<int> result;
        result.push_back(n);
        while (result.back() != 1)
        {
            if (result.back() % 2)
            {
                int temp = 0;
                temp = result.back();
                result.push_back(floor(pow(temp, 3.0 / 2.0)));
            }
            else
            {
                int temp = 0;
                temp = result.back();
                result.push_back(floor(pow(temp, 1.0 / 2.0)));
            }
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
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends