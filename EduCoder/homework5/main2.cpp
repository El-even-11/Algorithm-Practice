#include <iostream>
using namespace std;

struct Item
{
    int key[2];
    int value;
};

class Node
{
public:
    Node *left, *right;
    Item item;

    Node(Item _item) : item(_item), left(nullptr), right(nullptr)
    {
    }
};

bool keyEqual(int a[2], int b[2])
{
    return a[0] == b[0] && a[1] == b[1];
}

Node *minNode(Node *a, Node *b, int dimCmp)
{
    if (a->item.key[dimCmp] < b->item.key[dimCmp])
    {
        return a;
    }
    return b;
}

Node *maxNode(Node *a, Node *b, int dimCmp)
{
    if (a->item.key[dimCmp] < b->item.key[dimCmp])
    {
        return b;
    }
    return a;
}

void insert(Node *&root, Item item, int dim)
{
    // TODO
    if (!root)
    {
        root = new Node(item);
        return;
    }
    if (keyEqual(root->item.key, item.key))
    {
        return;
    }
    if (item.key[dim] < root->item.key[dim])
    {
        insert(root->left, item, (dim + 1) % 2);
        return;
    }
    insert(root->right, item, (dim + 1) % 2);
}

// If the queried key doesn't exist, return NULL.
Node *search(Node *root, int key[2], int dim)
{
    // TODO
    if (!root)
    {
        return nullptr;
    }
    if (keyEqual(key, root->item.key))
    {
        return root;
    }
    if (key[dim] < root->item.key[dim])
    {
        return search(root->left, key, (dim + 1) % 2);
    }
    return search(root->right, key, (dim + 1) % 2);
}

// Find the minimum value in a dimension(dimCmp)
Node *findMin(Node *root, int dimCmp, int dim)
{
    // TODO
    if (!root)
    {
        return nullptr;
    }

    if (dimCmp == dim)
    {
        if (!root->left)
        {
            return root;
        }
        return findMin(root->left, dimCmp, (dim + 1) % 2);
    }
    else
    {
        if (!root->left && !root->right)
        {
            return root;
        }

        if (!root->left)
        {
            Node *min = findMin(root->right, dimCmp, (dim + 1) % 2);
            return minNode(root, min, dimCmp);
        }

        if (!root->right)
        {
            Node *min = findMin(root->left, dimCmp, (dim + 1) % 2);
            return minNode(root, min, dimCmp);
        }

        Node *a = findMin(root->left, dimCmp, (dim + 1) % 2);
        Node *b = findMin(root->right, dimCmp, (dim + 1) % 2);

        Node *min = minNode(a, b, dimCmp);
        return minNode(root, min, dimCmp);
    }
}

Node *findMax(Node *root, int dimCmp, int dim)
{
    // TODO
    if (!root)
    {
        return nullptr;
    }

    if (dimCmp == dim)
    {
        if (!root->right)
        {
            return root;
        }
        return findMax(root->right, dimCmp, (dim + 1) % 2);
    }
    else
    {
        if (!root->left && !root->right)
        {
            return root;
        }

        if (!root->left)
        {
            Node *max = findMax(root->right, dimCmp, (dim + 1) % 2);
            return maxNode(root, max, dimCmp);
        }

        if (!root->right)
        {
            Node *max = findMax(root->left, dimCmp, (dim + 1) % 2);
            return maxNode(root, max, dimCmp);
        }

        Node *a = findMax(root->left, dimCmp, (dim + 1) % 2);
        Node *b = findMax(root->right, dimCmp, (dim + 1) % 2);

        Node *max = maxNode(a, b, dimCmp);
        return maxNode(root, max, dimCmp);
    }
}

Node *_remove(Node *t, int key[2], int dim)
{
    if (!t)
    {
        return nullptr;
    }

    if (keyEqual(t->item.key, key))
    {
        if (t->left || t->right)
        {
            if (t->right)
            {
                t->item = findMin(t->right, dim, (dim + 1) % 2)->item;
                t->right = _remove(t->right, t->item.key, (dim + 1) % 2);
            }
            else
            {
                t->item = findMax(t->left, dim, (dim + 1) % 2)->item;
                t->left = _remove(t->left, t->item.key, (dim + 1) % 2);
            }
        }
        else
        {
            t = nullptr;
        }
    }
    else if (key[dim] < t->item.key[dim])
    {
        t->left = _remove(t->left, key, (dim + 1) % 2);
    }
    else
    {
        t->right = _remove(t->right, key, (dim + 1) % 2);
    }

    return t;
}

void remove(Node *&root, int key[2], int dim)
{
    root = _remove(root, key, 0);
}

// searchRange contains 4 values [x_min, x_max, y_min, y_max]
// Our test program will call this function with dim=0 treeRange={-9999, 9999, -9999, 9999}
int rangeSearch(Node *root, int dim, int searchRange[4], int treeRange[4])
{
    // TODO
    if (!root)
    {
        return 0;
    }
    if (root->item.key[0] >= searchRange[0] && root->item.key[0] <= searchRange[1] && root->item.key[1] >= searchRange[2] && root->item.key[1] <= searchRange[3])
    {
        return 1 + rangeSearch(root->left, dim, searchRange, treeRange) + rangeSearch(root->right, dim, searchRange, treeRange);
    }
    return rangeSearch(root->left, dim, searchRange, treeRange) + rangeSearch(root->right, dim, searchRange, treeRange);
}

// int main()
// {
//     Node *root = nullptr;
//     Item a;
//     a.key[0] = 1;
//     a.key[1] = 1;
//     a.value = 1;
//     insert(root, a, 0);
//     a.key[0] = 3;
//     a.key[1] = 4;
//     a.value = 2;
//     insert(root, a, 0);
//     a.key[0] = 6;
//     a.key[1] = 5;
//     a.value = 3;
//     insert(root, a, 0);

//     int key[] = {3, 4};
//     remove(root, key, 0);

//     int searchRange[] = {2, 8, 0, 6};
//     int treeRange[] = {-9999, 9999, -9999, 9999};
//     cout << rangeSearch(root, 0, searchRange, treeRange) << endl;

//     return 0;
// }