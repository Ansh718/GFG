//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    bool isNodePresent(Node *root, int d)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == d)
        {
            return true;
        }
        return isNodePresent(root->left, d) ||
               isNodePresent(root->right, d);
    }
    int findLevel(Node *root, Node *node, int level)
    {
        if (root == nullptr)
        {
            return INT_MIN;
        }
        if (root == node)
        {
            return level;
        }
        int left = findLevel(root->left, node, level + 1);
        if (left != INT_MIN)
        {
            return left;
        }
        return findLevel(root->right, node, level + 1);
    }
    Node *findLCA(Node *root, int x, int y)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->data == x || root->data == y)
        {
            return root;
        }
        Node *left = findLCA(root->left, x, y);
        Node *right = findLCA(root->right, x, y);
        if (left && right)
        {
            return root;
        }
        if (left)
        {
            return left;
        }
        if (right)
        {
            return right;
        }
        return nullptr;
    }
    int findDist(Node *root, int x, int y)
    {
        Node *lca = nullptr;
        if (isNodePresent(root, y) && isNodePresent(root, x))
        {
            lca = findLCA(root, x, y);
        }
        else
        {
            return INT_MIN;
        }
        Node *nodeX = nullptr, *nodeY = nullptr;
        queue<Node *> q;
        q.push(root);
        while (!q.empty() && (!nodeX || !nodeY))
        {
            Node *curr = q.front();
            q.pop();
            if (curr->data == x)
            {
                nodeX = curr;
            }
            if (curr->data == y)
            {
                nodeY = curr;
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        return findLevel(lca, nodeX, 0) + findLevel(lca, nodeY, 0);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}

// } Driver Code Ends