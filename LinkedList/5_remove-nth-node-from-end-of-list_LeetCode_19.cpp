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
// google amazon meta microsft meta apple oracle bloomberg accenture qualcomm goldman
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL){
            count += 1;
            curr = curr->next;
        }
        if(count == n){
            return head->next;
        }
        int reach = count - n-1;
        ListNode *temp = head;
        while(reach--){
            temp = temp->next;
        }
        temp ->next = temp->next->next;
        return head;
    }
};
