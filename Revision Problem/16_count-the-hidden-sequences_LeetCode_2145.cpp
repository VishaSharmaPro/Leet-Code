// tag = Senior software engineer
// google amazon bloomberg tiktok meta zomato
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;
        int minval = 0;
        int maxval = 0;   // isley taaki total count ko maximise kara jaske ki taaki koi bhi hidden sequences consideration ho sabhi ke sabhi
        for(int & d : differences){
            curr = curr + d;
            minval = min(minval,curr);
            maxval = max(maxval,curr);

            if((upper-maxval) - (lower-minval) + 1 <= 0){
                return 0;
            }
        }
        return (upper-maxval) - (lower-minval) + 1;
    }
};
