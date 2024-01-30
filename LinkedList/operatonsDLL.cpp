#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void inserton(Node *&head, int data, int pos)
{
    Node *n = new Node(data);
    if(head==NULL){
        head = n;
        return;
    }
    if (pos == 0)
    {
        n->next = head;
        head->prev = n;
        head = n;       
        return;         
    }              

    Node *curr = head;
    int count = 0;
    while (curr != NULL && count != pos)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL)
        return;

    if (curr->next == NULL)
    {
        curr->next = n;
        n->prev = curr;
        return;
    }

    n->next = curr->next;
    n->prev = curr;
    curr->next->prev = n;
    curr->next = n;
}


void deletion(Node *&head, int pos)
{
    if(head==NULL)
        return;

    if (pos == 0)
    {
        head = head->next;
        return;
    }
    Node *curr = head;
    int count = 0;
    while (curr != NULL && count != pos - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL || curr->next == NULL)
        return; // if Pos is out of bound
    if (curr->next->next == NULL)
    {
        curr->next = NULL;
        return;
    }

    // curr->next->next->prev = curr;
    // curr->next = curr->next->next;

    curr->next = curr->next->next;
    curr->next->prev = curr;
}

void display(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    // Node *head = new Node(20);
    Node *head = NULL;
    inserton(head, 10, 0);
    inserton(head, 220, 1);
    inserton(head, 30, 2);
    inserton(head, 40, 3);
    inserton(head, 300, 4);
    deletion(head,5);
    display(head);
    
    return 0;
}
