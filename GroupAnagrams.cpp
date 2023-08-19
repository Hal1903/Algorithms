#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long long ll;
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
for (auto &i : v) {
    is >> i;
}
return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
for (auto &i : v) {
    os << i << " ";
}
return os;
}
#define rep(i, s, e) for (int i = (s); i < (e); i++)
#define repd(i, s, e) for (int i = s - 1; i >= (e); i--)
#define fore(i, c) for (auto &i : (c))
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    for (string word: strs){
        string temp = word;
        sort(temp.begin(), temp.end());
        if (mp.find(temp) == mp.end()){ // not found
            mp[temp] = {word};
        } else {
            mp[temp].push_back(word);
        }
    }
    for (auto elem: mp){
        res.push_back(elem.second);
    }
    return res;
}

int main(){
    vector<string> vs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> vss = groupAnagrams(vs);
    for (vector<string> v: vss){
        for (string s: v){
            cout << s << ", ";
        }
        cout << endl;
    }
    return 0;
}