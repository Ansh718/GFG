class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        Node *ptr = root;
        int result = 0;
        result = -1;
        while (ptr)
        {
            if (ptr->key <= k)
            {
                result = ptr->key;
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        return result;
    }
};