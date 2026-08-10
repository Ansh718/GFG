class Solution
{
public:
    string matrixChainOrder(int p[], int n)
    {
        vector<vector<pair<long long, int>>> dP(n, vector<pair<long long, int>>(n, {1e18, -1}));
        for (int i = 0; i < n - 1; i++)
        {
            dP[i][i] = dP[i][i + 1] = {0, -1};
        }
        dP[n - 1][n - 1] = {0, -1};
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    long long current = (long long)p[i] * (long long)p[j] * (long long)p[k] + dP[i][k].first + dP[k][j].first;

                    if (current < dP[i][j].first)
                    {
                        dP[i][j].first = current;
                        dP[i][j].second = k;
                    }
                }
            }
        }
        vector<string> result(n + n - 1, "");
        char c;
        for (int i = 1, c = 'A'; i < n + n - 1; i += 2, c++)
        {
            result[i] += c;
        }
        fillBrackets(result, dP, 0, n - 1);
        string ans = "";
        for (auto i : result)
        {
            ans += i;
        }
        return ans;
    }

private:
    void fillBrackets(vector<string> &result, vector<vector<pair<long long, int>>> &dP, int i, int j)
    {
        if (j - i < 2)
        {
            return;
        }
        int s = i * 2;
        int e = j * 2;
        result[s] += '(';
        result[e] += ')';
        fillBrackets(result, dP, i, dP[i][j].second);
        fillBrackets(result, dP, dP[i][j].second, j);
    }
};
