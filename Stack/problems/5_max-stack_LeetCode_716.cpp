/*
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
 

Constraints:

-107 <= x <= 107
At most 105 calls will be made to push, pop, top, peekMax, and popMax.
There will be at least one element in the stack when pop, top, peekMax, or popMax is called.
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
1,86,114/405K
Acceptance Rate
46.0%

*/
// google amazon meta tiktok oracle linkedin walmart nutanix lyft wolven_by_toyota
class MaxStack {
public:
    map<int,int> index;           
    map<int, set<int>> element;   
    int i = 0;

    void push(int x) {
        index[i] = x;
        element[x].insert(i);     
        i++;
    }
    
    int pop() {
        auto it = index.rbegin();
        int id = it->first;
        int el = it->second;
        index.erase(id);
        element[el].erase(id);                         
        if(element[el].empty()) element.erase(el);     
        return el;
    }
    
    int top() {
        return index.rbegin()->second;
    }
    
    int peekMax() {
        return element.rbegin()->first;
    }
    
    int popMax() {
        auto it = element.rbegin();
        int el = it->first;
        int id = *it->second.rbegin();  
        element[el].erase(id);
        if(element[el].empty()) element.erase(el);
        index.erase(id);
        return el;
    }
};

// method 2 by vector inside elemnt map in placce of set

class MaxStack {
public:
    map<int,int> index;           
    map<int, vector<int>> element;   
    int i = 0;

    void push(int x) {
        index[i] = x;
        element[x].push_back(i);     
        i++;
    }
    
    int pop() {
        auto it = index.rbegin();
        int id = it->first;
        int el = it->second;
        index.erase(id);
        element[el].pop_back();                         
        if(element[el].empty()) element.erase(el);     
        return el;
    }
    
    int top() {
        return index.rbegin()->second;
    }
    
    int peekMax() {
        return element.rbegin()->first;
    }
    
    int popMax() {
        auto it = element.rbegin();
        int el = it->first;
        int id = it->second.back();  
        element[el].pop_back();
        if(element[el].empty()) element.erase(el);
        index.erase(id);
        return el;
    }
};
