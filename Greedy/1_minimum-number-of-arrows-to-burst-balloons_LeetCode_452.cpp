// google amazon microsoft bloomberg tiktok goldamn livspace
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int bound = points[0][1];
        int arrow = 1;
        for(int i = 1;i<n;i++){
            if(points[i][0] <= bound && points[i][1] > bound){
                continue;
            }
            else if(points[i][0] <= bound && points[i][1] <= bound){
                bound = min(bound,points[i][1]);
                continue;
            }
            else{
                bound = points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};
