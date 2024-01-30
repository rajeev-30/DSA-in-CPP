#include <iostream>
using namespace std;
#define MAX_SIZE 10

bool isEmpty(int top)
{
    return (top == -1);
}

bool isFull(int top)
{
    return (top == MAX_SIZE - 1);
}

void push(int stack[], int &top, int item)
{
    if (isFull(top))
    {
        cout << "Stack is OverFlow" << endl;
        return;
    }
    stack[++top] = item;
}

void pop(int stack[], int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is UnderFlow" << endl;
        return;
    }
    top--;
}

void display(int stack[], int top)
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
}

int main()
{
    int stack[10];
    int top = -1;
    int item, choise;
    while (true)
    {
        cin >> choise;
        switch (choise)
        {
        case 1:
            cin >> item;
            push(stack, top, item);
            break;
        case 2:
            pop(stack, top);
            break;
        case 3:
            if (isEmpty(top))
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (isFull(top))
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choise" << endl;
        }
    }
    display(stack, top);
}