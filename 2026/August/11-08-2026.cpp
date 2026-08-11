class Solution
{
public:
    vector<int> largestSquare(vector<vector<int>> &mat, vector<vector<int>> &queries,
                              int k)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        vector<int> answer;

        for (auto &q : queries)
        {
            int i = q[0];
            int j = q[1];

            int maxRadius = min(min(i, j), min(n - 1 - i, m - 1 - j));

            int low = 0, high = maxRadius;
            int best = -1;

            while (low <= high)
            {
                int radius = low + (high - low) / 2;
                int top = i - radius;
                int bottom = i + radius;
                int left = j - radius;
                int right = j + radius;

                int ones = prefix[bottom + 1][right + 1] - prefix[top][right + 1] - prefix[bottom + 1][left] + prefix[top][left];

                if (ones <= k)
                {
                    best = radius;
                    low = radius + 1;
                }
                else
                {
                    high = radius - 1;
                }
            }

            if (best == -1)
            {
                answer.push_back(-1);
            }
            else
            {
                answer.push_back(2 * best + 1);
            }
        }

        return answer;
    }
};