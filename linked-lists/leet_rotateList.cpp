#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    ListNode* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    k = k % n;
    if (k == 0)  return head;

    tail->next = head;

    ListNode* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << " -> NULL" << std::endl;
}


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    std::cout << "Rotated by " << k << ": ";
    printList(head);

    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}