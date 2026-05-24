// google amazon microsoft razorpay grammarly jpmorgan chase
class Solution {
public:
    int t[100001][3];
    int solve(vector<vector<int>>& events,int i,int count){
        if(count>2) return 0;
        if(i>=events.size()) return 0;
        if(t[i][count] != -1) return t[i][count];
        int take;
        int skip;
        int s = i+1;
        int e = events.size()-1;
        int next = events.size();
        while(s<=e){
            int mid = s +(e-s)/2;
            if(events[mid][0] > events[i][1]){
                next = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        take = events[i][2]+solve(events,next,count+1);
        skip = solve(events,i+1,count);
        
        return t[i][count] = max(take,skip);;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        memset(t,-1,sizeof(t));
        return solve(events,0,1);
    }
};
