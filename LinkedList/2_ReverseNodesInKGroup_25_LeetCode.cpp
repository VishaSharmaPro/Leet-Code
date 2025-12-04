
// Company = Microsoft, Google, Amazon, Meta, BloomBerg, Cisco, Goldman Sachs, Apple , Walmart, Adobe, Visa, Infosys, Salesforce, Zeta, Tik Tok
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
    ListNode* reverse(ListNode* head,ListNode *stop){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != stop){
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;
        while(end != NULL){
            for(int i = 0;i<k;i++){
                if(end== NULL){
                    if(prevTail) prevTail->next = start;
                    return newHead ? newHead : head;
                }
                end = end->next;
            }
            ListNode* reverseHead = reverse(start,end);
            if(newHead == NULL){
                newHead = reverseHead;
            }
            if(prevTail != NULL){
                prevTail->next = reverseHead;
            }
            start->next = end;
            prevTail = start;
            start = end;
        }
        return newHead;
    }
};
