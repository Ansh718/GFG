//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data)
{
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    struct Node *arrangeCV(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *vowel_head = NULL;
        Node *vowel_tail = NULL;
        Node *consonant_head = NULL;
        Node *consonant_tail = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            if (isVowel(curr->data))
            {
                if (vowel_head == NULL)
                {
                    vowel_head = curr;
                    vowel_tail = curr;
                }
                else
                {
                    vowel_tail->next = curr;
                    vowel_tail = curr;
                }
            }
            else
            {
                if (consonant_head == NULL)
                {
                    consonant_head = curr;
                    consonant_tail = curr;
                }
                else
                {
                    consonant_tail->next = curr;
                    consonant_tail = curr;
                }
            }
            curr = curr->next;
        }

        if (vowel_head == NULL)
        {
            return consonant_head;
        }
        else
        {
            vowel_tail->next = consonant_head;
            if (consonant_tail != NULL)
            {
                consonant_tail->next = NULL;
            }
            return vowel_head;
        }
    }

private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};

//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--)
        {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends