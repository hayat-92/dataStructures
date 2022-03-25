#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        if (l1 == NULL)
        {
            return l2;
        }
        else
        {
            return l1;
        }
        int c = 0;
        ListNode *newHead = NULL;
        ListNode *tail = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            int digSum = l1->val + l2->val;
            digSum += c;
            c = digSum / 10;
            ListNode *node = new ListNode(digSum % 10);
            if (newHead != NULL)
            {
                tail->next = node;
                tail = tail->next;
            }
            else
            {
                newHead = node;
                tail = node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != NULL)
        {
            while (l1 != NULL)
            {
                int value = l1->val;
                value += c;
                c = value / 10;
                ListNode *node = new ListNode(value % 10);
                tail->next = node;
                tail = tail->next;
                l1 = l1->next;
            }
        }
        else if (l2 != NULL)
        {
            while (l2 != NULL)
            {
                int value = l2->val;
                value += c;
                c = value / 10;
                ListNode *node = new ListNode(value % 10);
                tail->next = node;
                tail = tail->next;
                l2 = l2->next;
            }
        }

        if (c != 0)
        {
            ListNode *node = new ListNode(c);
            tail->next = node;
        }

        return newHead;
    }
};
int main()
{

    return 0;
}