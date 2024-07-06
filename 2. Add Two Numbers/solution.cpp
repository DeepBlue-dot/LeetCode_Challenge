#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int reminder = 0)
    {
        if (l1 == nullptr && l2 == nullptr && reminder == 0)
        {
            return nullptr;
        }

        int sum = reminder;
        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode *curr = new ListNode(sum % 10);
        curr->next = addTwoNumbers(l1, l2, sum / 10);
        return curr;
    }
};

#include <iostream>

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating two lists: 342 (3 -> 4 -> 2) and 465 (4 -> 6 -> 5)
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(2);

    ListNode* l2 = new ListNode(4);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // The result should be 807 (8 -> 0 -> 7)
    std::cout << "Result: ";
    printList(result);

    // Clean up memory
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
