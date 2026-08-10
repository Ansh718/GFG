//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
public:
    struct Node *mergeResult(Node *first, Node *second)
    {
        if (second == NULL)
        {
            Node *p1 = first;
            Node *p2 = NULL;
            Node *p3 = NULL;
            while (p1 != NULL)
            {
                p3 = p1->next;
                p1->next = p2;
                p2 = p1;
                p1 = p3;
            }
            return p2;
        }
        if (first == NULL)
        {
            Node *p1 = second;
            Node *p2 = NULL;
            Node *p3 = NULL;
            while (p1 != NULL)
            {
                p3 = p1->next;
                p1->next = p2;
                p2 = p1;
                p1 = p3;
            }
            return p2;
        }
        if (first->data > second->data)
        {
            swap(first, second);
        }
        Node *res = first;
        while (first != NULL && second != NULL)
        {
            Node *temp = NULL;
            while (first != NULL && first->data <= second->data)
            {
                temp = first;
                first = first->next;
            }
            temp->next = second;
            swap(first, second);
        }
        Node *p1 = res;
        Node *p2 = NULL;
        Node *p3 = NULL;
        while (p1 != NULL)
        {
            p3 = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = p3;
        }
        return p2;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int nA;
        cin >> nA;
        int nB;
        cin >> nB;

        struct Node *headA = NULL;
        struct Node *tempA = headA;

        for (int i = 0; i < nA; i++)
        {
            int ele;
            cin >> ele;
            if (headA == NULL)
            {
                headA = tempA = newNode(ele);
            }
            else
            {
                tempA->next = newNode(ele);
                tempA = tempA->next;
            }
        }

        struct Node *headB = NULL;
        struct Node *tempB = headB;

        for (int i = 0; i < nB; i++)
        {
            int ele;
            cin >> ele;
            if (headB == NULL)
            {
                headB = tempB = newNode(ele);
            }
            else
            {
                tempB->next = newNode(ele);
                tempB = tempB->next;
            }
        }

        Solution ob;
        struct Node *result = ob.mergeResult(headA, headB);

        print(result);
        cout << endl;
    }
}

// } Driver Code Ends