// google amazon microsoft meta tesla adobe uber snap yandex tiktok zoho expedia bloomberg motive rivian ixl doordash oracle bytedance rokt
class Solution {
public:
    int calculate(string s) {
        vector<string> vec;
        string token = "";
        for(char c : s){
            if(isspace(c)){
                if(!token.empty()){
                    vec.push_back(token);
                    token = "";
                }
            }else if(c=='+' || c=='-' || c=='*' || c=='/'){
                    if(!token.empty()){
                        vec.push_back(token);
                        token = "";
                    }
                    vec.push_back(string(1,c));
            }else{
                token += c;
            }
        }    
        if(!token.empty()) vec.push_back(token);
        int n = vec.size();
        
        for(int i = 1;i<n;i+=2){
            if(vec[i] == "/" || vec[i] == "*"){
                int res = 0;
                if(vec[i] == "/" ){
                    res += stoi(vec[i-1])/stoi(vec[i+1]);
                }
                else if(vec[i] == "*" ){
                    res += stoi(vec[i-1])*stoi(vec[i+1]);
                }
                vec[i-1] = to_string(res);
                vec.erase(vec.begin() + i,vec.begin()+ i+ 2);
                n = vec.size();
                i -= 2;
            }    
        }
        int ans = stoi(vec[0]);
        for(int i = 1;i<n;i+=2){
            if(vec[i] == "+" ){
                ans += stoi(vec[i+1]);
            }
            else if(vec[i] == "-" ){
                ans -= stoi(vec[i+1]);
            }
        }
        return ans;
    }
};

/*
char c = '+';
to_string(c)  → "43"  // ASCII value of '+'
string(1, c)  → "+"   // 1 copy of character '+'

string(count, character)
string(1, '+') → "+" — 1 baar '+' repeat karo
string(3, '+') → "+++" — 3 baar repeat karo
*/
