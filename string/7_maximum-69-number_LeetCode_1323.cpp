// google amazon mircosoft meta bloomberg HSBC
class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        for(int i = 0;i<temp.length();i++){
            if(temp[i] !='9'){
                temp[i] = '9';
                break;
            }
        }
        return stoi(temp);
    }
};
