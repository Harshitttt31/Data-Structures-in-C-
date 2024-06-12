#include <iostream>
#include <string>
using namespace std;
class node
{
    int data;
    node *left;
    node *right;
    friend class BST;

public:
    node() {}
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST
{

public:
    node *root;
    BST()
    {
        root = NULL;
    }
    void insert(int d)
    {
        node *newNode = new node(d);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            node *ptr = root;
            while ((ptr->left != NULL) && (ptr->right != NULL))
            {
                if (ptr->data > d)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            if (ptr->data > d)
            {
                ptr->left = newNode;
            }
            else
            {
                ptr->right = newNode;
            }
        }
    }
    void Inorder(node *root)
    {
        if (root != NULL)
        {
            Inorder(root->left);
            cout << root->data << "  ";
            Inorder(root->right);
        }
    }
    void Preorder(node *root)
    {
        if (root != NULL)
        {
            cout << root->data << "  ";
            Inorder(root->left);
            Inorder(root->right);
        }
    }
    void Postorder(node *root)
    {
        if (root != NULL)
        {
            Inorder(root->left);
            Inorder(root->right);
            cout << root->data << "  ";
        }
    }
};
int main()
{
    int choice, choice1;
    int num;
    BST tree;
    string choice2;
    while (true)
    {
        cout << "What do you want to do:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Traversal" << endl;
        cout << "3. deletion" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            choice2 = "yes";
            while (choice2 != "no")
            {
                cout << "Enter the number : ";
                cin >> num;
                tree.insert(num);
                cout << "Do want to enter more number(yes/no)" << endl;
                cin >> choice2;
            }
            break;
        case 2:
            cout << "Which type of traversal of want to do" << endl;
            cout << "1. BFS" << endl;
            cout << "2. Inorder Traversal" << endl;
            cout << "3. Preorder Traversal" << endl;
            cout << "4. Postorder traversal" << endl;
            cout << "5. None" << endl;
            cout << "Enter the choice : ";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
                break;
            case 2:
                cout << endl;
                tree.Inorder(tree.root);
                break;
                cout << endl;
            case 3:
                cout << endl;
                tree.Preorder(tree.root);
                break;
                cout << endl;
            case 4:
                cout << endl;
                tree.Postorder(tree.root);
                break;
                cout << endl;
            case 5:
                break;
            default:
                break;
            }
        case 3:
            break;
        case 4:
            cout << "Thank for visiting my code!!!!!" << endl;
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
