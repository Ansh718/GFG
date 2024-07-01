//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    static bool compare(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
    {
        return get<0>(a) > get<0>(b);
    }

    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<tuple<int, int, int>> diffs;
        for (int i = 0; i < n; ++i)
        {
            diffs.push_back(make_tuple(abs(arr[i] - brr[i]), arr[i], brr[i]));
        }

        sort(diffs.begin(), diffs.end(), compare);

        long long totalTips = 0;
        int aCount = 0, bCount = 0;

        for (auto &diff : diffs)
        {
            int tipA = get<1>(diff);
            int tipB = get<2>(diff);

            if ((tipA >= tipB && aCount < x) || bCount == y)
            {
                totalTips += tipA;
                aCount++;
            }
            else
            {
                totalTips += tipB;
                bCount++;
            }
        }

        return totalTips;
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

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends