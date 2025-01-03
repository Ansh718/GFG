class Solution
{
public:
    void populateNext(Node *root)
    {
        if (!root)
        {
            return;
        }
        Node *prev = NULL;
        stack<Node *> st;
        Node *current = root;
        while (!st.empty() || current != NULL)
        {
            while (current != NULL)
            {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            if (prev != NULL)
            {
                prev->next = current;
            }
            prev = current;
            current = current->right;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
    }
};

// /*
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
//     struct Node *next;

//     Node(int x)
//     {
//         data = x;
//         left = NULL;
//         right = NULL;
//         next = NULL;
//     }
// };
// */
// class Solution
// {
// public:
//     void populateNext(Node *root)
//     {
//         Node *prev = NULL;
//         populateNextUtil(root, &prev);
//     }

//     void populateNextUtil(Node *root, Node **prev)
//     {
//         if (root)
//         {
//             populateNextUtil(root->left, prev);
//             if (*prev != NULL)
//             {
//                 (*prev)->next = root;
//             }
//             *prev = root;
//             populateNextUtil(root->right, prev);
//         }
//     }
// };