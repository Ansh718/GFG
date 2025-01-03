//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string compareFrac(string str)
    {
        double num1 = 0;
        double denom1 = 0;
        double num2 = 0;
        double denom2 = 0;
        bool first = false;
        string temp = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ',')
            {
                denom1 = stod(temp);
                temp = "";
                continue;
            }
            if (str[i] == '/')
            {
                if (first)
                {
                    num2 = stod(temp);
                    temp = "";
                }
                else
                {
                    num1 = stod(temp);
                    temp = "";
                    first = true;
                }
            }
            else
            {
                temp += str[i];
            }
        }
        denom2 = stod(temp);
        if ((num1 / denom1) > (num2 / denom2))
        {
            string temp = "";
            temp += to_string((int)num1);
            temp += '/';
            temp += to_string((int)denom1);
            return temp;
        }
        if ((num1 / denom1) < (num2 / denom2))
        {
            string temp = "";
            temp += to_string((int)num2);
            temp += '/';
            temp += to_string((int)denom2);
            return temp;
        }
        return "equal";
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends