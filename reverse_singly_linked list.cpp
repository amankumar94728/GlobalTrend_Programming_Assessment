#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
             cout << current->val << " ";
        current = current->next;
    }
       cout << endl;
}


ListNode* createListFromInput() {
    int n, value;
         cout << "Enter the number of elements in the list: ";
         cin >> n;
    
    if (n == 0) return nullptr;

         cout << "Enter the elements: ";
         cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* current = head;
    
    for (int i = 1; i < n; ++i) {
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }
    
    return head;
}

int main() {
    
    ListNode* head = createListFromInput();

    cout << "Original list: ";
    printList(head);

    
    ListNode* newHead = reverseList(head);

    cout << "Reversed list: ";
    printList(newHead);

    return 0;
}
