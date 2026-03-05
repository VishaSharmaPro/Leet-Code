// amazon microsoft meta google bloomberg
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 1) return 1;
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[position[i]] = speed[i];
        }
        sort(position.begin(),position.end());
        for(int i = 0;i<n;i++){
            int pos = position[i];
            speed[i] = mp[pos];
        }
        int count = 0;
        stack<double> st;
        for(int i = n-1;i>=0;i--){
            double time = double(target - position[i])/speed[i];
            if(st.empty()){
                st.push(time);
                count++;
            }
            else if(time <= st.top()){
                continue;
            }
            else if(time > st.top()){
                while(!st.empty()){
                    st.pop();
                }
                st.push(time);
                count++;
            }
        }
        return count;
    }
};
