#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> set;
    int n2 = n;
    int i = 1;
    while(i<=n2){
        if(n2%i == 0){
            set.insert(i);
            set.insert(n2);
            n2 = n2/i;
            
        }
        i++;
    }
    if (set.size() >= 2) {
        auto it1 = set.begin();
        it1++;  
        for (; it1 != set.end(); it1++) {
            auto it2 = it1;  
            for (; it2 != set.end(); it2++) {
                int prod = (*it1) * (*it2);  
                if (prod >= n) break;
                if (n % prod == 0) set.insert(prod);
            }
        }
    }
    for(auto num : set){
        cout<<num<<" ";
        
    }
    return 0;
}

// second approach
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> set;
    int n2 = n;
    int i = 1;
    vector<int> vec;
    while(i<=sqrt(n)){
        if(n%i == 0){
            vec.push_back(i);
        }
        i++;
    }
    int vs = vec.size();
    int maxel = vec[vs-1];
    for(int i = 2; i< vs;i++){
        int curr = vec[i];
        vec.push_back(n/curr);
    }
    for(int num : vec){
        cout<<num<<" ";
    }
    return 0;
}
