class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        int len = 0;
        vector<int> freq(26, 0);
        int n = 0;
        n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] > 1)
            {
                result = max(result, len);
                len = 0;
            }
            else
            {
                len++;
            }
        }
        return result;
    }
};