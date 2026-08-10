//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> kTop(vector<int> &arr, int N, int K)
    {
        vector<vector<int>> result;
        vector<int> top(K + 1);
        unordered_map<int, int> umP;
        for (int i = 0; i < N; i++)
        {
            umP[arr[i]]++;
            top[K] = arr[i];
            auto itr = find(top.begin(), top.end() - 1, arr[i]);
            for (int i = distance(top.begin(), itr) - 1; i >= 0; i--)
            {
                if (umP[top[i]] < umP[top[i + 1]])
                {
                    swap(top[i], top[i + 1]);
                }
                else if ((umP[top[i]] == umP[top[i + 1]]) && (top[i] > top[i + 1]))
                {
                    swap(top[i], top[i + 1]);
                }
                else
                {
                    break;
                }
            }
            vector<int> currentTop;
            for (int j = 0; j < K && top[j] != 0; j++)
            {
                currentTop.push_back(top[j]);
            }
            result.push_back(currentTop);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        vector<int> a(N);
        Array::input(a, N);

        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);

        for (auto it : res)
            Array::print(it);
    }
}

// } Driver Code Ends