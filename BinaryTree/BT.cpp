#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    // cout << "Enter data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter left data of " << data << ": ";
    root->left = buildTree();

    cout << "Enter right data of " << data << ": ";
    root->right = buildTree();

    return root;
}

// 1 2 4 6 -1 -1 7 -1 -1 -1 3 -1 5 -1 -1

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildTreeLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter root data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter Right of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                // cout<<temp->left->data<<" ";
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                // cout<<temp->right->data<<" ";
                q.push(temp->right);
            }
        }
    }
}

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return max(lh, rh) + 1;
}

int countOfNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int lc = countOfNodes(root->left);
    int rc = countOfNodes(root->right);

    return (lc + rc) + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int ls = sumOfNodes(root->left);
    int rs = sumOfNodes(root->right);

    return ls + rs + root->data;
}

void printKthLevel(Node *root, int level, int k)
{
    if (root == NULL)
        return;

    if (level == k)
    {
        cout << root->data;
        return;
    }

    printKthLevel(root->left, level + 1, k);
    printKthLevel(root->right, level + 1, k);
}

int main()
{
    Node *root = NULL;
    root = buildTree();
    // buildTreeLevelOrder(root);

    cout << "\nPreorder " << endl;
    preOrder(root);

    // cout << "\nPostorder " << endl;
    // postOrder(root);

    // cout << "\nInorder " << endl;
    // inOrder(root);

    // cout << "\nLevelOrder " << endl;
    // LevelOrderTraversal(root);

    // cout << sumOfNodes(root);
    // printKthLevel(root, 1, 7);

    return 0;
}

// 1 2 3 4 -1 -1 5 6 7 -1 -1 -1 -1 -1 -1