#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    node() {}
};

class bst : public node
{
public:
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
    node *inordersucc(node *root)
    {
        node *current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    node *deleteinbst(node * root, int key)
    {
        if (key < root->data)
        {
            root->left = deleteinbst(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteinbst(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                node *temp = inordersucc(root->right);
                root->data = temp->data;
                root->right = deleteinbst(root->right, temp->data);
            }
            return root;
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
};

int main()
{
    int ch, data;
    node *root;

    bst b;
    root = NULL;

    do
    {
        cout << "\n1. insert \n2. display by inorder \n3. delete node \n5 exit" << endl;
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
            cout << "Enter the data which you want to delete" << endl;
            cin >> data;
            b.deleteinbst(root, data);
            break;

        default:
            cout << " ";
            break;
        }
    } while (ch != 5);
}