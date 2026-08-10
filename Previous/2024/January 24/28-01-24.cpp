//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long ncr(long long n, long long r)
    {
        long long answer = 1;
        // n! / ((n - r)! * r!)
        for (long long i = n; i > max(r, n - r); i--)
        {
            answer *= i;
        }
        long long d = 1;
        for (long long i = 1; i <= min(r, n - r); i++)
        {
            d *= i;
        }
        answer /= d;
        return answer;
    }

    long long findNthNumber(long long n, long long k)
    {
        vector<vector<long long>> dP(63, vector<long long>(k + 1, 0));
        for (int i = 0; i < 63; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                for (int x = 0; x <= min(i + 1, j); x++)
                {
                    dP[i][j] += ncr(i + 1, x);
                }
            }
        }
        long long p = 0;
        for (int i = 0; i < 63; i++)
        {
            if (dP[i][k] >= n)
            {
                p = i;
                break;
            }
        }
        long long answer = 0;
        while (p > -1 and n > 0)
        {
            if (p + 1 <= k)
            {
                answer += n - 1;
                break;
            }

            if (p > 0 and dP[p - 1][k] < n)
            {
                answer |= (1LL << p);
                n -= dP[p - 1][k];
                k = max(k - 1, 0LL);
            }

            --p;
        }
        return answer;
    }
};
//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int k;
        scanf("%d", &k);

        Solution obj;
        long long res = obj.findNthNumber(n, k);

        cout << res << endl;
    }
}

// } Driver Code Ends