#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node() {}
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class bst : public node
{
public:
    // node *root;
    // node *tail;
    // bst()
    // {
    //     root = NULL;
    //     tail = NULL;
    // }
    void insert(node *&root, int val)
    {
        node *ptr = new node(val);
        if (root == NULL)
        {
            root = ptr;
            return;
        }
        else
        {
            node *temp = root;
            while (temp != NULL)
            {
                if ((temp->data < ptr->data) && (temp->right == NULL))
                {
                    temp->right = ptr;
                    return;
                }
                else if (temp->data < ptr->data)
                {
                    temp = temp->right;
                }
                else if ((temp->data > ptr->data) && (temp->left == NULL))
                {
                    temp->left = ptr;
                    return;
                }
                else if (temp->data > ptr->data)
                {
                    temp = temp->left;
                }
            }
        }
    }
    void inorder(node *&root)

    {
        node *temp = root;
        if (temp == NULL)
        {
            return;
        }
        inorder(temp->left);
        cout << " ";
        cout << temp->data << " ";

        inorder(temp->right);
        cout << " ";
    }
    void preorder(node *&root)
    {
        node *temp = root;
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";
        preorder(temp->left);

        preorder(temp->right);
    }
    void postorder(node *&root)
    {
        node *temp = root;
        if (temp == NULL)
        {
            return;
        }
        postorder(temp->left);

        postorder(temp->right);

        cout << temp->data << " ";
    }
};
int main()
{
    int ch, data;
    node *root;

    bst b;
    root = NULL;

    do
    {
        cout << "\n1. insert \n2. display by inorder \n3. display by preorder \n4. display by post order \n5 exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number " << endl;
            cin >> data;
            b.insert(root, data);

            break;
        case 2:
            b.inorder(root);
            break;
        case 3:

            b.preorder(root);
            break;
        case 4:
            b.postorder(root);
            break;

        default:
            cout << " ";
            break;
        }
    } while (ch != 5);
}