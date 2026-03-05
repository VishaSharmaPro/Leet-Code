//company = amazon google paypal microsoft oracle meta bloomberg visa flipkart nvidia
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i = 0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size() != 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(x-y);
        }
        return pq.top();
    }
};
