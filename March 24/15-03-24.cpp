//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    void split(Node *head, Node **ascH, Node **descH)
    {
        *ascH = new Node(0);
        *descH = new Node(0);
        Node *ascN = *ascH;
        Node *descN = *descH;
        Node *current = head;
        while (current)
        {
            ascN->next = current;
            ascN = ascN->next;
            current = current->next;
            if (current)
            {
                descN->next = current;
                descN = descN->next;
                current = current->next;
            }
        }
        ascN->next = NULL;
        descN->next = NULL;
        *ascH = (*ascH)->next;
        *descH = (*descH)->next;
    }
    void reverse(Node *&head)
    {
        Node *ptr1 = NULL;
        Node *ptr2 = NULL;
        Node *ptr3 = head;
        while (ptr3 != NULL)
        {
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3->next;
            ptr2->next = ptr1;
        }
        head = ptr2;
    }
    Node *merge(Node *h1, Node *h2)
    {
        if (!h1)
        {
            return h2;
        }
        if (!h2)
        {
            return h1;
        }
        Node *temp = NULL;
        if (h1->data < h2->data)
        {
            temp = h1;
            h1->next = merge(h1->next, h2);
        }
        else
        {
            temp = h2;
            h2->next = merge(h1, h2->next);
        }
        return temp;
    }
    void sort(Node **head)
    {
        Node *ascH;
        Node *descH;
        split(*head, &ascH, &descH);
        reverse(descH);
        *head = merge(ascH, descH);
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends