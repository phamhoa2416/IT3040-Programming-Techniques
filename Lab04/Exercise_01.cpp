#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node *prepend(Node *head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// print the list content on a line
void print(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;
    while (current != NULL)
    {
        // Using pointer next to store the next node of the current node
        next = current->next;
        // Reverse the link
        current->next = prev;
        // Move the pointer to the next node
        prev = current;
        // Move the pointer to the next node
        current = next;
    }
    return prev;
}

int main()
{
    int n, u;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}