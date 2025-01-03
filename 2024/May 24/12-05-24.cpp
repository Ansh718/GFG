//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int steps(int source, int step, int dest)
    {
        if (abs(source) > dest)
        {
            return INT_MAX;
        }
        if (source == dest)
        {
            return step;
        }

        if (memo.count(source) && memo[source].count(step))
        {
            return memo[source][step];
        }
        int pos = steps(source + step + 1, step + 1, dest);
        int neg = steps(source - step - 1, step + 1, dest);
        memo[source][step] = min(pos, neg);
        return memo[source][step];
    }

    int minSteps(int d)
    {
        memo.clear();
        int answer = steps(0, 0, d);
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends