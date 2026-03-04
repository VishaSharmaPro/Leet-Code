// Google amazon microsoft apple meta bloomberg linkedin tiktok uber mongodb oracle phonepe walmart blend tesco
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> vec;
        while(i<n){
            if(intervals[i][1]< newInterval[0]){
                vec.push_back(intervals[i]);
                i++;
            }
            else if(intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
                i++;
            }
            else if(intervals[i][0] > newInterval[1]){
                break;
            }
        }
        vec.push_back({newInterval[0],newInterval[1]});
        while(i<n){
            vec.push_back(intervals[i]);
            i++;
        }
        return vec;
    }
};
