// Youtube link =  https://www.youtube.com/watch?v=8dnLLxjpF80
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string s1 = "ae";
    string s2 = "bg";
    string s3 = "bega";

    unordered_set<char> st1;
    for (int i = 0; i < s1.length(); i++) {
        st1.insert(s1[i]);
    }

    unordered_set<char> st2;
    for (int i = 0; i < s2.length(); i++) {
        st2.insert(s2[i]);
    }

    int cs1 = 0;
    int cs2 = 0;
    bool ans = true;

    for (int i = 0; i < s3.length(); i++) {
        if (st1.find(s3[i]) != st1.end()) {
            if (s3[i] == s1[cs1]) {
                cs1++;
            } else {
                ans = false;
                break;
            }
        }
    }

    for (int i = 0; i < s3.length(); i++) {
        if (st2.find(s3[i]) != st2.end()) {
            if (s3[i] == s2[cs2]) {
                cs2++;
            } else {
                ans = false;
                break;
            }
        }
    }

    if (ans && cs1 == s1.size() && cs2 == s2.size()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
