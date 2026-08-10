//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = 0;
        n = stations.size();
        double low = 0;
        double high = 0;
        high = *max_element(stations.begin(), stations.end()) - *min_element(stations.begin(), stations.end());
        while (high - low > 1e-6)
        {
            double mid = 0;
            mid = low + (high - low) / 2.0;
            if (canPlaceStations(stations, n, k, mid))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
    }

private:
    bool canPlaceStations(const vector<int> &stations, int n, int k, double d)
    {
        int requiredStations = 0;
        for (int i = 1; i < n; i++)
        {
            double distance = 0;
            distance = stations[i] - stations[i - 1];
            requiredStations += (int)(distance / d);
        }
        return requiredStations <= k;
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends