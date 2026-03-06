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
//gogole amazon microsoft meta bloomberg udemyoracle servicenow apple goldman linkedin zoho tiktok rippling 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* x = i->next;
        ListNode* y = j->next;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        if(i->val <= j->val){
            head = i;
            prev = i;
            i = x;
            if(x) x = x->next;
        }else{
            head = j;
            prev = j;
            j= y;
            if(y) y = y->next;
        }
        
        while(i != nullptr && j != nullptr){
            if(i->val > j->val){
                prev->next = j;
                prev = j;
                j = y;
                if(y) y = y->next;
            }
            else if(i->val <= j->val){
                prev->next = i;
                prev = i;
                i = x;
                if(x) x = x->next;
            }
        }
        if( i!= nullptr){
            prev->next = i;
        }
        if(j != nullptr){
            prev->next = j;
        }
        return head;
    }
};
