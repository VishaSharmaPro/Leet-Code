// google amazon meta bloomberg microsoft apple zoho adobe ibm atlassian tiktok goldman linkedin tesla nvidia oracle uber okta citadel paypal salesforce netflix yandex walamrt tesco
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  
        int n = intervals.size();
        int i = 0;
        int j = 1;
        vector<vector<int>> vec;
        while(j<n){
            if(intervals[i][1] < intervals[j][0]){
                vec.push_back({intervals[i][0],intervals[i][1]});  
                i = j;  
                j++;
            }else{
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);  
                j++;
            }
        }
        vec.push_back({intervals[i][0],intervals[i][1]});  
        return vec;
    }
};
