// google amazon meta microsoft bloomber apple netapp airbnb zomato tiktok walamrt oracle linkedin citadel confluent pininterest
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i,vector<int>& candidates, int &target,int sum){
        if(sum> target || i>=candidates.size()){
            return;
        }
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        solve(i,candidates,target,sum+candidates[i]);
        temp.pop_back();

        solve(i+1,candidates,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0,candidates,target,0);
        return ans;
    }
};
