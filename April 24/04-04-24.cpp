class Solution
{
public:
    long long sumSubstrings(string str)
    {
        long long int result = 0;
        int m = 1e9 + 7;
        int n = str.size();
        long long p = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result += ((str[i] - '0') * p * (i + 1)) % m;
            result %= m;
            p = ((p * 10) + 1) % m;
        }
        return result;
    }
};
