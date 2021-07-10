#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: Merge in Between.cpp
    author: Akhil
    date: 2021-07-09
    time: 18:57:08
    ==================================================
*/
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int data) {
        this->data = data;
    }
};

SinglyLinkedListNode* mergeInBetween(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2, int a, int b) {
    typedef SinglyLinkedListNode sn;
    sn *ath = nullptr, *bth = nullptr, *aprev = nullptr, *bnext = nullptr;
    sn *ptr = l1;
    int count = 1;
    while (ptr) {
        if (count == a - 1) {
            aprev = ptr;
        }
        else if (count == a) {
            ath = ptr;
        }
        else if (count == b) {
            bth = ptr;
        }
        else if (count == b + 1) {
            bnext = ptr;
        }
        count++;
        ptr = ptr -> next;
    }
    sn *tail2 = l2;
    while (tail2->next) {
        tail2 = tail2->next;
    }
    if (aprev) {
        cout << aprev->data << endl;
        aprev->next = l2;
        tail2->next = bnext;
        return l1;
    }
    else {
        tail2->next = bnext;
        return l2;
    }
}
void print(SinglyLinkedListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    SinglyLinkedListNode *l1, *l2, *h1, *h2;
    l1 = new SinglyLinkedListNode(1);
    h1 = l1;
    l1-> next = new SinglyLinkedListNode(2); l1 = l1->next;
    l1-> next = new SinglyLinkedListNode(3); l1 = l1->next;
    l1-> next = new SinglyLinkedListNode(4); l1 = l1->next;
    l1-> next = new SinglyLinkedListNode(5); l1 = l1->next;
    l1-> next = new SinglyLinkedListNode(6); l1 = l1->next;
    l2 = new SinglyLinkedListNode(10);
    h2 = l2;
    l2-> next = new SinglyLinkedListNode(12); l2 = l2->next;
    l2-> next = new SinglyLinkedListNode(13); l2 = l2->next;
    l2-> next = new SinglyLinkedListNode(14); l2 = l2->next;
    l2-> next = new SinglyLinkedListNode(15); l2 = l2->next;
    print(mergeInBetween(h1, h2, 1, 3));
    return 0;
}