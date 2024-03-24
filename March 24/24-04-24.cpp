//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        stack<int> res;
        stack<int> temp;
        while (!st.empty())
        {
            int i = 0;
            i = st.top();
            st.pop();
            temp.push(i);
        }
        temp.push(x);
        while (!temp.empty())
        {
            int i = 0;
            i = temp.top();
            temp.pop();
            res.push(i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp = ob.insertAtBottom(st, x);
        vector<int> v;
        while (tmp.size())
        {
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends