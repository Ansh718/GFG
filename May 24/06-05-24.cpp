//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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
vector<int> noSibling(Node *root);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void dfs(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q1;
    q1.push(root);
    int flag = 0;
    while (q1.empty() == false)
    {
        struct Node *temp = q1.front();
        q1.pop();
        if (temp->left != NULL &&
            temp->right == NULL)
        {
            flag = 1;
            v.push_back(temp->left->data);
        }

        if (temp->left == NULL &&
            temp->right != NULL)
        {
            flag = 1;
            v.push_back(temp->right->data);
        }
        if (temp->left != NULL)
        {
            q1.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q1.push(temp->right);
        }
    }
}

vector<int> noSibling(Node *node)
{
    vector<int> result;
    dfs(node, result);
    if (result.empty())
    {
        result.push_back(-1);
        return result;
    }
    sort(result.begin(), result.end());
    return result;
}