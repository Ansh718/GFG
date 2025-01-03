//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// } Driver Code Ends
// User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution
{
public:
    Node *insertionSort(struct Node *headref)
    {
        helper(headref);
        return headref;
    }

private:
    void helper(struct Node *node)
    {
        if (!node)
        {
            return;
        }
        helper(node->next);
        int key = 0;
        key = node->data;
        Node *next = NULL;
        next = node->next;
        while (next)
        {
            if (next->data < key)
            {
                node->data = next->data;
                node = next;
                next = node->next;
            }
            else
            {
                break;
            }
        }
        node->data = key;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends