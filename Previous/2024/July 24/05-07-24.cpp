class Solution
{
public:
    int verticalWidth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int miN = 0, maX = 0;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int hd = q.front().second;
            q.pop();
            miN = min(miN, hd);
            maX = max(maX, hd);
            if (node->left)
            {
                q.push({node->left, hd - 1});
            }
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }
        return maX - miN + 1;
    }
};