//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    int result;

private:
    int pp(int i, vector<int> &p)
    {
        while (p[i] != i)
        {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
    int Union(int a, int b, vector<int> &p, vector<int> &temp)
    {
        int rac = pp(a, p);
        int rbc = pp(b, p);
        if (rac == rbc)
        {
            return temp[rac] * temp[rac];
        }
        if (temp[rac] < temp[rbc])
        {
            swap(rac, rbc);
            swap(a, b);
        }
        result += temp[rac] * temp[rbc];
        p[rbc] = rac;
        temp[rac] += temp[rbc];
        return result;
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        result = 0;
        vector<int> p(n + 1, 0),
            temp(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            temp[i] = 1;
        }
        vector<pair<int, pair<int, int>>> weight;
        for (int i = 0; i < n - 1; i++)
        {
            weight.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
        }
        sort(weight.begin(), weight.end());
        map<int, int> mpp;
        for (int i = 0; i < n - 1; i++)
        {
            int a = 0;
            a = weight[i].first;
            int b = 0;
            b = weight[i].second.first;
            int c = 0;
            c = weight[i].second.second;
            mpp[a] = Union(b, c, p, temp);
        }
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            auto v = mpp.upper_bound(queries[i]);
            if (v == mpp.begin())
            {
                ans.push_back(0);
            }
            else
            {
                v--;
                ans.push_back(v->second);
            }
        }
        return ans;
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

        vector<vector<int>> edges(n - 1, vector<int>(3, 0));

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        Solution obj;
        vector<int> ans = obj.maximumWeight(n, edges, q, queries);

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends