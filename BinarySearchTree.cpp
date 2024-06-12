#include <iostream>
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
        root = nullptr;
    }
    void insert(int d)
    {
        if (root == NULL)
        {
            root = new node(d);
        }
        else
        {
            node *ptr = root,*ptr1;
            node *newNode = new node(d);
            while ((ptr->left != nullptr) && (ptr->right != nullptr))
            {
                if (ptr->data > d)
                {
                    ptr = ptr->left;
                    ptr=ptr1;
                }
                else
                {
                    ptr = ptr->right;
                    ptr=ptr1;
                }
            }
            if (ptr->data > d)
            {
                ptr->left=newNode;
            }
            else
            {
                ptr->right=newNode;
            }
        }
    }
    void Inorder(node *root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << "  ";
            Inorder(root->right);
        }
        cout<<endl;
    }
    void Preorder(node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << "  ";
            Inorder(root->left);
            Inorder(root->right);
        }
        cout<<endl;
    }
    void Postorder(node *root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            Inorder(root->right);
            cout << root->data << "  ";
        }
        cout<<endl;
    }
};
int main()
{
    int choice, choice1;
    int num;
    BST tree;
    while (true)
    {
        cout << "What do you want to do:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Traversal" << endl;
        cout << "3. deletion" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter the number : ";
            cin >> num;
            cout << endl;
            tree.insert(num);
            break;
        case 2:
            cout << "Which type of traversal of want to do" << endl;
            cout << "1. BFS" << endl;
            cout << "2. Inorder Traversal" << endl;
            cout << "3. Preorder Traversal" << endl;
            cout << "4. Postorder traversal" << endl;
            cout << "5. None" << endl;
            cout<<"Enter the choice : ";
            cin>>choice1;
            cout<<endl;
            switch (choice1)
            {
            case 1:

                break;
            case 2:
                tree.Inorder(tree.root);
                break;
            case 3:
                tree.Preorder(tree.root);
                break;
            case 4:
                tree.Postorder(tree.root);
                break;
            case 5:
                break;    
            default: 
            break;
            }
        case 3:
            break;
        case 4:
            cout<<"Thank for visiting my code!!!!!"<<endl;
            exit(0);
        default:
            break;
        }
    }
    return 0;
}