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

void insert(Node *&root, Item item, int dim)
{
    // TODO
}

// If the queried key doesn't exist, return NULL.
Node *search(Node *root, int key[2], int dim)
{
    // TODO
}

// Find the minimum value in a dimension(dimCmp)
Node *findMin(Node *root, int dimCmp, int dim)
{
    // TODO
}

void remove(Node *&root, int key[2], int dim)
{
    // TODO
}

// searchRange contains 4 values [x_min, x_max, y_min, y_max]
// Our test program will call this function with dim=0 treeRange={-9999, 9999, -9999, 9999}
int rangeSearch(Node *root, int dim, int searchRange[4], int treeRange[4])
{
    // TODO
}
