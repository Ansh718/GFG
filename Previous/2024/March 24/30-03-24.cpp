class Solution
{
public:
    int minValue(Node *root)
    {
        if (!root)
        {
            return -1;
        }
        int res;
        while (root)
        {
            res = root->data;
            root = root->left;
        }
        return res;
    }
};