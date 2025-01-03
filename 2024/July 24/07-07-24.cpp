class Solution
{
public:
    bool helper(Node *root, int target, vector<int> &result)
    {
        if (!root)
        {
            return false;
        }
        if (root->data == target)
        {
            return true;
        }
        if (helper(root->left, target, result) || helper(root->right, target, result))
        {
            result.push_back(root->data);
            return true;
        }
        return false;
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> result;
        helper(root, target, result);
    }
};