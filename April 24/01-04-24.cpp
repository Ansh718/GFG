//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution
{
public:
    long long int mergE(vector<int> &arr, long long l, long long m, long long h)
    {
        long long temp[h - l + 1];
        long long int k = 0;
        long long int i = 0;
        i = l;
        long long int j = 0;
        j = m + 1;
        long long int invers = 0;
        while (i <= m && j <= h)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                invers += m - i + 1;
                temp[k++] = arr[j++];
            }
        }
        while (i <= m)
        {
            temp[k++] = arr[i++];
        }
        while (j <= h)
        {
            temp[k++] = arr[j++];
        }
        for (int x = l; x <= h; x++)
        {
            arr[x] = temp[x - l];
        }
        return invers;
    }
    long long int mergeS(vector<int> &arr, long long int l, long long int h)
    {
        if (l >= h)
        {
            return 0;
        }
        long long int invers = 0;
        long long m = 0;
        m = (l + h) / 2;
        invers += mergeS(arr, l, m);
        invers += mergeS(arr, m + 1, h);
        invers += mergE(arr, l, m, h);
        return invers;
    }

    long long int inversionCount(vector<int> &arr, long long N)
    {
        long long int ans = mergeS(arr, 0, N - 1);
        return ans;
    }
    void inord(Node *root, vector<int> &arr)
    {
        if (root)
        {
            inord(root->left, arr);
            arr.push_back(root->data);
            inord(root->right, arr);
        }
        return;
    }
    int pairsViolatingBST(int n, Node *root)
    {
        vector<int> arr;
        inord(root, arr);
        long long N = n;
        return int(inversionCount(arr, N));
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    getchar();

    while (t--)
    {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node *root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends