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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }

        if(length==n){
            return head->next;
        }

        temp = head;
        int val = length - n;
        while (val > 1)
        {
            temp = temp->next;
            val--;
        }
        temp->next = temp->next->next;
        return head;
    }
};
int main()
{

    return 0;
}