//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    static vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B, long long m)
    {
        int size = A.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                long long sum = 0;
                for (int k = 0; k < size; ++k)
                {
                    sum += A[i][k] * B[k][j];
                    sum %= m;
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    static long long genFibNum(long long a, long long b, long long c, long long n, long long m)
    {
        if (n <= 2)
        {
            return 1L % m;
        }
        vector<vector<long long>> mat = {{a, b, 1L}, {1L, 0L, 0L}, {0L, 0L, 1L}};
        vector<vector<long long>> res = {{1L, 0L, 0L}, {0L, 1L, 0L}, {0L, 0L, 1L}};
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
            {
                res = multiply(res, mat, m);
            }
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, n, m;

        cin >> a >> b >> c >> n >> m;

        Solution ob;
        cout << ob.genFibNum(a, b, c, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends