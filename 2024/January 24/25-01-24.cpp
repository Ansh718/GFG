//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n <= 3)
        {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }
    int solve(int Num1, int Num2)
    {
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(Num1);
        visited.insert(Num1);
        int moves = 0;
        while (qu.size())
        {
            int quS = 0;
            quS = qu.size();
            while (quS--)
            {
                int temp = 0;
                temp = qu.front();
                qu.pop();
                if (temp == Num2)
                {
                    return moves;
                }
                for (int i = 0; i < 4; i++)
                {
                    int f = 0;
                    f = pow(10, i);
                    int t = temp;
                    t -= (f * ((t / f) % 10));
                    for (int j = 0; j < 10; j++)
                    {
                        t += (f * j);
                        if (t > 1000 && !visited.count(t) && isPrime(t))
                        {
                            qu.push(t);
                            visited.insert(t);
                        }
                        t -= (f * j);
                    }
                }
            }
            moves++;
        }
        return moves;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int Num1, Num2;
        cin >> Num1 >> Num2;
        Solution obj;
        int answer = obj.solve(Num1, Num2);
        cout << answer << endl;
    }
}
// } Driver Code Ends