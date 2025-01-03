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
    Node *LowestCommonAncestor(Node *root, int n1, int n2)
    {
        if (!root)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        else if (root->data < n1 && root->data < n2)
        {
            return LowestCommonAncestor(root->right, n1, n2);
        }
        else if (root->data > n1 && root->data > n2)
        {
            return LowestCommonAncestor(root->left, n1, n2);
        }
        else
        {
            return root;
        }
    }

    void func(Node *root, Node *lowCA, vector<int> &route)
    {
        route.push_back(root->data);
        if (root->data == lowCA->data)
        {
            return;
        }
        else if (root->data > lowCA->data)
        {
            func(root->left, lowCA, route);
        }
        else
        {
            func(root->right, lowCA, route);
        }

        return;
    }
    int kthCommonAncestor(Node *root, int k, int n1, int n2)
    {
        Node *lowCA = LowestCommonAncestor(root, n1, n2);
        vector<int> route;
        func(root, lowCA, route);
        int n = route.size();
        if (route.size() < k)
        {
            return -1;
        }
        return route[n - k];
    }
};