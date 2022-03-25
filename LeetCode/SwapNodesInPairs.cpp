#include <iostream>
using namespace std;
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
    ListNode *reverse(ListNode *head)
    {
        ListNode *temp=head;
        head=head->next;
        head->next=temp;
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *fHead = NULL;
        ListNode *fTail = NULL;
        ListNode *temp = head;
        while (temp != NULL && temp->next!=NULL)
        {
            int count = 1;
            ListNode *node = temp;
            ListNode *tempHead = temp;
            node = node->next;
            temp = node->next;
            node->next = NULL;
            if (fHead == NULL)
            {
                fHead = reverse(tempHead);
                fTail = fHead;
            }
            else
            {
                fTail->next = reverse(tempHead);
            }
        }

        if(temp!=NULL){
            
        }
    }
};
int main()
{

    return 0;
}