//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int splitArray(int arr[], int N, int K)
    {
        int l = 0;
        int h = 0;

        for (int i = 0; i < N; i++)
            h += arr[i], l = max(l, arr[i] - 1);

        while (l < h - 1)
        {
            int m = l + (h - l) / 2;

            auto chc = [&]() -> bool
            {
                int partitions = 0;

                int s = 0;

                for (int i = 0; i < N; i++)
                {
                    if (s + arr[i] > m)
                    {
                        ++partitions;
                        s = arr[i];
                    }
                    else
                    {
                        s += arr[i];
                    }
                }

                return partitions < K;
            };

            if (chc())
                h = m;
            else
                l = m;
        }

        return h;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;

        cin >> N >> K;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.splitArray(arr, N, K);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends