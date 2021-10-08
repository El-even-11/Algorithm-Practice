#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read()
{
    List L, addNode, Rear;
    L = (List)malloc(sizeof(Node));
    L->Data = 0;
    L->Next = nullptr;
    Rear = L;

    int N;
    cin >> N;
    while (N--)
    {
        addNode = (List)malloc(sizeof(Node));
        cin >> addNode->Data;
        addNode->Next = nullptr;
        Rear->Next = addNode;
        Rear = Rear->Next;
    }
    return L;
}
void Print(List L)
{
    List t = L;
    if (!t)
    {
        cout << "NUll\n";
    }
    else
    {
        t = t->Next;
        while (t)
        {
            cout << t->Data << " ";
            t = t->Next;
        }
        cout << endl;
    }
}

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    cout << "\nmain函数：\n";
    cout << "L:";
    Print(L);
    cout << "L1:";
    Print(L1);
    cout << "L2:";
    Print(L2);
    // Print(L);
    // Print(L1);
    // Print(L2);
    return 0;
}

List Merge(List L1, List L2)
{
    List L = (List)malloc(sizeof(Node));
    L->Data = 0;
    L->Next = nullptr;
    List Rear = L;
    L1 = L1->Next;
    L2 = L2->Next;
    while (L1 && L2)
    {
        if (L1->Data <= L2->Data)
        {
            Rear->Next = L1;
            Rear = Rear->Next;
            L1 = L1->Next;
        }
        else
        {
            Rear->Next = L2;
            Rear = Rear->Next;
            L2 = L2->Next;
        }
    }
    while (L1)
    {
        Rear->Next = L1;
        Rear = Rear->Next;
        L1 = L1->Next;
    }
    while (L2)
    {
        Rear->Next = L2;
        Rear = Rear->Next;
        L2 = L2->Next;
    }
    
    // cout << "\nmerge函数：\n";
    // cout << "L:";
    Print(L);
    // cout << "L1:";
    printf("NULL\n");
    // cout << "L2:";
    printf("NULL\n");
    return L;
}
