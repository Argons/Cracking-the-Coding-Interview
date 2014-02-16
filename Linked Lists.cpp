#include <iostream>
#include <set>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d, Node *Next = NULL): data(d), next(Next) {}
};

class LinkedList {
    public:
    Node *head;

    LinkedList(Node *node_head=NULL): head(node_head) {}
    Node* getHead() { return head; }
    int length()
    {
        int count = 0;
        Node *current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    void append(int newData)
    {
        Node *newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }
    void addToTail(int newData)
    {
        if (head == NULL) {
            head = new Node(newData);
            return;
        }
        Node *newNode = new Node(newData);
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    void deleteNode(int d)
    {
        Node *current = head;
        while (current != NULL) {
            if (current->next->data == d) {
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }
    void insertNth(int data, int n)
    {
        if (n > length())
            return;
        Node *current = head;
        for (int i = 1; i < n-1; i++) {
            current = current->next;
        }
        Node *temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
    void printLinkedList()
    {
        if (head == NULL)
            return;
        cout<<head->data;
        Node *current = head->next;
        while (current != NULL) {
            cout<<" -> "<<current->data;
            current = current->next;
        }
        cout<<endl;
    }
    void insertionSort()
    {
        if (head == NULL)
            return;
        Node *a;
        Node *b;
        for (a = head->next; a != NULL; a = a->next) {
            for (b = head; b != a; b = b->next) {
                if (a->data < b->data)
                    swap(a->data, b->data);
            }
        }
    }

    void removeDups();
    Node* findNthToLast(int);
};


/// 2.1 -Remove duplicates
void LinkedList::removeDups()
{
    if (head == NULL)
        return;

    set<int> table;
    Node *current = head;
    table.insert(current->data);
    while (current->next != NULL) {
        if (table.find(current->next->data) != table.end())
            current->next = current->next->next;
        else {
            table.insert(current->next->data);
            current = current->next; 
            // if current->next is deleted, pointer current retains.
        }
    }
}


/// 2.2 -Find the Nth to last element
Node* LinkedList::findNthToLast(int n)
{
    Node *ptr1 = head;
    for (int i = 0; i < n; i++) {
        if (ptr1 == NULL)
            return NULL; // if n>length, return NULL
        ptr1 = ptr1->next;
    }
    Node *current = head;
    for (Node *ptr2 = ptr1; ptr2 != NULL; ptr2 = ptr2->next) {
        current = current->next;
    }
    return current;
}


/// 2.3 -Delete node n in the middle of linked list given only the access of this node.
void deleteNode(Node *n)
{
    if (n == NULL || n->next == NULL)
        return;
    n->data = n->next->data;
    n->next = n->next->next;
}


/// 2.4 -Add up two numbers reversely stored in two lists, return the sum as a linked list.
LinkedList addReversedLists(LinkedList list1, LinkedList list2, int carry = 0)
{
    if (list1.head == NULL && list2.head == NULL && carry == 0)
        return NULL;
    int data = carry;
    if (list1.head != NULL) {
        data += list1.head->data;
    }
    if (list2.head != NULL) {
        data += list2.head->data;
    }
    carry = data / 10;
    LinkedList res = addReversedLists((list1.head == NULL ? NULL : list1.head->next),
                                      (list2.head == NULL ? NULL : list2.head->next),
                                      carry);
    res.addToTail(data % 10);
    return res;
}


/// 2.5 -Given a circular linked list, return node at the beginning of the loop.
bool hasCycle(Node*);
Node *FindBeginning(LinkedList list)
{
    if (!hasCycle(list.head)) {
        return NULL;
    }

    Node *a = list.head;
    Node *b = list.head;
    while (b->next != NULL) {
        a = a->next;
        b = b->next->next;
        if (a == b) {
            break;
        }
    }
    if (b->next == NULL) {
        return NULL;
    }
    a = list.head;
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}
bool hasCycle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    Node *n1 = head;
    Node *n2 = head->next;
    while (n2 != NULL) {
        if (n1 == n2) {
            return true; // n1(slower) and n2(faster) will meet if cycle exists.
        }
        n1 = n1->next;
        n2 = n2->next;
        if (n2 != NULL)
            n2 = n2->next;
        else
            break;
    }
    return false;
}
