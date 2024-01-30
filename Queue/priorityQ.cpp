#include <iostream>
using namespace std;
struct Node
{
    int data;
    int priorty;
    Node *next;
};

Node *temp, *front, *rear;
void enqueue()
{
    struct Node *newnode = new Node();
    cout << "Enter data: ";
    cin >> newnode->data;
    cout << "Enter priorty: ";
    cin >> newnode->priorty;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else if (newnode->priorty > front->priorty)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        Node *prev;
        prev = temp = front;

        while (newnode->priorty <= temp->priorty && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = newnode;
            temp = newnode;
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void display()
{
    temp = front;
    if (front == NULL)
    {
        cout << "Queue is Underflow: " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << " Data: " << temp->data << " "
                 << "Priorty: " << temp->priorty;
            temp = temp->next;
        }
    }
    cout << endl;
}
void dequeue()
{
    temp = front;
    if (front == NULL)
    {
        cout << "Queue is Underflow: " << endl;
    }
    else
    {
        front = front->next;
        delete temp;
        temp = front;
    }
}
int main()
{
    int n;
    cout << "Enter 1 to start program: ";
    cin >> n;
    while (n)
    {
        int choice;
        cout << "1: Enqueue " << endl;
        cout << "2: Dequeue" << endl;
        cout << "3: Display" << endl;
        cout << "4: Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Choice: " << endl;
            break;
        }
    }
    return 0;
}