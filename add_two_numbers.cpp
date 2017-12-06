#include <iostream>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if((nullptr == l1) || (nullptr == l2)) 
        {
            return nullptr;    
        }

        ListNode* result = new ListNode(0);
        ListNode* head = result;
        ListNode* l1_sentinel = l1;
        ListNode* l2_sentinel = l2;
        auto over = 0;
        int sum_value = 0;
        for(;;)
        {
            sum_value = 0;
            if((nullptr == l1_sentinel) && (nullptr == l2_sentinel))
            {
                if(1 == over)
                {
                    ListNode* temp = new ListNode(over);
                    result->next = temp;
                    result = result->next;
                }
                break;
            }
            else if(nullptr == l1_sentinel)
            {
                sum_value = l2_sentinel->val + over;
                l2_sentinel = l2_sentinel->next;
            }
            else if(nullptr == l2_sentinel)
            {
                sum_value = l1_sentinel->val + over;
                l1_sentinel = l1_sentinel->next;
            }
            else
            {
                sum_value = l1_sentinel->val + l2_sentinel->val + over;
                l1_sentinel = l1_sentinel->next;
                l2_sentinel = l2_sentinel->next;

            }

            if(10 <= sum_value)   
            {
                over = 1;
                sum_value -= 10;
            }
            else
            {
                over = 0;
            }
            ListNode* temp = new ListNode(sum_value);
            result->next = temp;
            result = result->next;
        }
        return head->next;
    }
};

int main(void)
{
    ListNode l1_1(9);
    ListNode l1_2(8);
    //ListNode l1_3(9);
    l1_1.next = &l1_2;
    //l1_2.next = &l1_3;
    ListNode l1_4(5);

    ListNode l2_1(1);
    //ListNode l2_2(1);
    //ListNode l2_3(1);
    //l2_1.next = &l2_2;
    //l2_2.next = &l2_3;
    ListNode l2_4(5);
    //l2_4.next = &l2_1;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(&l1_1,&l2_1);
    ListNode* ptr = nullptr;
    for(ptr = result; ptr != nullptr;ptr = ptr->next)
    {
        std::cout << ptr->val;
    }
    std::cout << std::endl;
    return 0;
}
