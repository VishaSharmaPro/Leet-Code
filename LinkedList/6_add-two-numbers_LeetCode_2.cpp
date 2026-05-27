// google amazon bloomberg meta microsoft jane street apple adobe earnin oracle nvidia goldman zoho yandex accenture avito
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * s1 = l1;
        ListNode* s2 = l2;
        ListNode * head = new ListNode(0);
        ListNode* curr = head; 
        int car = 0;
        while(s1 != NULL && s2 != NULL){
            int num = s1->val + s2->val + car;
            int x = num%10;
            car = num/10;
            curr->next = new ListNode(x);
            curr = curr->next;
            s1 = s1->next;
            s2 = s2->next;
        }
        while(s1 != NULL){
            int num = s1->val  + car;
            int x = num%10;
            car = num/10;
            curr->next = new ListNode(x);
            curr = curr->next;
            s1 = s1->next;
        }
        while(s2 != NULL){
            int num = s2->val  + car;
            int x = num%10;
            car = num/10;
            curr->next = new ListNode(x);
            curr = curr->next;
            s2 = s2->next;
        }
        if(car != 0){
            curr->next = new ListNode(car);
        }
        return head->next;
    }
};
