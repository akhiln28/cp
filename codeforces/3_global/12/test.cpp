#include <iostream>
using namespace std;

struct node
{
    int id;
    node *next;
    node(int id)
    {
        this->id = id;
        next = nullptr;
    }
};
bool is_cyclic(node *head)
{
    if (head == nullptr)
        return false;
    node *ptr1 = head, *ptr2 = head;
    int count = 0;
    while (ptr1 && ptr2 && ptr2->next)
    {
        if (count && ptr1 == ptr2)
            return true;
        count++;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    return false;
}

node *cycle_start(node *head)
{
    if (head == nullptr)
        return nullptr;
    node *ptr1 = head, *ptr2 = head, *intersection = nullptr;
    int count = 0;
    while (ptr1 && ptr2 && ptr2->next)
    {
        if (count && ptr1 == ptr2)
        {
            intersection = ptr1;
            break;
        }
        count++;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    if (intersection == nullptr)
    {
        cout << "no cycle detected" << endl;
        return nullptr; 
    }
    cout << "intersection node: " << intersection->id << endl;
    ptr1 = head, ptr2 = intersection; 
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next;
    }
    return ptr1;
}
void break_cycle(node *head)
{
    node *start = cycle_start(head);
    cout << "start node: " << start->id << endl;
    if (start == nullptr)
        return;
    node *ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next; 
    }
    ptr->next = nullptr;
    cout << "successfully removed cycle" << endl;
    return;
}

int main()
{
    node *n1 = new node(1); 
    node *n2 = new node(2); n1->next = n2;
    node *n3 = new node(3); n2->next = n3;
    node *n4 = new node(4); n3->next = n4; 
    node *n5 = new node(5); n4->next = n5;
    node *n6 = new node(6); n5->next = n6;
    node *n7 = new node(7); n6->next = n7;
    node *n8 = new node(8); n7->next = n8;
    n8->next = n4; 
    cout << "is_cyclic: " << (is_cyclic(n1) ? "true" : "false") << endl;
    break_cycle(n1);
    cout << "is_cyclic: " << (is_cyclic(n1) ? "true" : "false") << endl;
    return 0; 
}