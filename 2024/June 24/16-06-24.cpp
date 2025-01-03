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
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n <= 3)
        {
            return true;
        }
        if (!(n % 2) || !(n % 3))
        {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
            if (!(n % (i)) || !(n % (i + 2)))
            {
                return false;
            }
        }
        return true;
    }
    vector<int> SieveOfEratosthenes(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                {
                    prime[i] = false;
                }
            }
        }
        vector<int> p1;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                p1.push_back(i);
            }
        }
        return p1;
    }
    vector<int> getPrimes(int n)
    {
        vector<int> result;
        if (n % 2)
        {
            int target = 0;
            target = n - 2;
            if (isPrime(target))
            {
                result.push_back(2);
                result.push_back(target);
                return result;
            }
            else
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        }
        else
        {
            vector<int> temp = SieveOfEratosthenes(n);
            unordered_map<int, int> ump;
            for (auto t : temp)
            {
                ump[t]++;
            }
            for (int i = 0; i < n; i++)
            {
                int current = 0;
                current = n - temp[i];
                if (ump[current] > 0)
                {
                    result.push_back(temp[i]);
                    result.push_back(current);
                    break;
                }
            }
            if (result.empty())
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            else
            {
                return result;
            }
        }
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

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends

