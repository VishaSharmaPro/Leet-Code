// google amazon microsoft meta bloomberg linkedin lyft uber apple citadel okta yelp
class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string b;
    int sz;
private:
    void dfs(string word,vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mp[word];
        for(int i = 0;i<sz;i++){
            char org = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(mp.find(word) != mp.end()
                && mp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<string> q;
        q.push({beginWord});
        set.erase(beginWord);
        mp[beginWord] = 1;
        sz = beginWord.size();
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word == endWord) continue;
            int steps = mp[word];
            for(int i = 0;i<sz;i++){
                char org = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(set.count(word)){
                        q.push(word);
                        set.erase(word);
                        mp[word] = steps+1;
                    }
                }
                word[i] = org;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};

// method 2 yeh wala method run nhi karega memorary limit exceed dega
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            // erase all words that have been used in level
            if(vec.size() > level){
                level++;
                for(auto & it: used){
                    set.erase(it);
                }
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0;i<word.size();i++){
                char org = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(set.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = org;
            }
        }
        return ans;
    }
};

// method 3 = yeh vala bhi memoray limit exceed dega run nhi hoga
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            // erase all words that have been used in level
            if(vec.size() > level){
                level++;
                for(auto & it: used){
                    set.erase(it);
                }
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0;i<word.size();i++){
                char org = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(set.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = org;
            }
        }
        return ans;
    }
};
