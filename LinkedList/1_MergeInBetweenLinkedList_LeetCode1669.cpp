company = amazon
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* amove = list1;
        int i = 0;
        while(i < a-1){
            amove = amove->next;
            i++;
        }
        int j = 0;
        ListNode* bmove = list1;
        while(j < b){
            bmove = bmove->next;
            j++;
        }

        ListNode*tail = list2;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = bmove->next;
        amove->next = list2;
        return list1;
    }
};
