//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/
class Solution
{
public:
    long long max_sum(int a[], int n)
    {
        long long sum1 = 0;
        for (long long i = 0; i < n; i++)
        {
            sum1 += a[i];
        }

        long long initial1 = 0, max1 = 0;
        for (long long i = 0; i < n; i++)
        {
            initial1 += i * a[i];
        }
        max1 = initial1;

        for (long long i = 1; i < n; i++)
        {
            long long next1 = initial1 - (sum1) + 1LL * (n)*a[i - 1];
            initial1 = next1;
            if (max1 < initial1)
            {
                max1 = initial1;
            }
        }
        return max1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends