// amazon adobe qualcomm
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node*,int> position;
        unordered_map<Node*,int> vis;
        Node* temp = head;
        Node*prev = NULL;
        vis[prev] = true;
        position[prev] = 0;
        while(temp->next !=  NULL){
            if(vis[temp]){
                return position[prev] - position[temp]+1;
            }
            vis[temp] = true;
            position[temp] = position[prev]+1;
            prev = temp;
            temp = temp->next;
            
        }
        return 0;
    }
};
