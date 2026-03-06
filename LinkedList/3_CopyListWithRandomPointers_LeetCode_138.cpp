/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Company = Google , meta, microsoft, Amazon, Apple, bloomber, Nvidia, oracle, intel, TikTok, Flipkart, Walmart, morgan Stanley
class Solution {
public:
    unordered_map<Node*,Node*> randommp;
    Node* formLinkedList(Node* curr){
        if(curr == NULL) return NULL;
        Node* newn = new Node(curr->val);
        randommp[curr] = newn;
        newn->next = formLinkedList(curr->next); 
        return newn;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* newh = new Node(head->val);
        Node* curr = head;
        randommp[curr] = newh;
        newh->next = formLinkedList(curr->next);
        Node* oldcurr = head;
        Node* newcurr = newh;
        while(newcurr != NULL){
            if(oldcurr->random != NULL){
                newcurr->random = randommp[oldcurr->random];
            }
            newcurr = newcurr->next;
            oldcurr = oldcurr->next;
        }
        return newh;
    }
};


// another solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        if(head == NULL) return NULL;
        Node* curr = head->next;
        Node* newh = new Node(head->val);
        mp[head] = newh;
        Node* temp = newh;
        while(curr != NULL){
            Node* newn = new Node(curr->val);
            mp[curr] = newn;
            temp->next = newn;
            temp = newn;
            curr = curr->next;
            
        }
        Node* newcurr = newh;
        curr = head;
        while(newcurr != NULL){
            if(curr->random != NULL){
                newcurr->random = mp[curr->random];
            }
            newcurr = newcurr->next;
            curr = curr->next;
        }
        return newh;
    }
};
