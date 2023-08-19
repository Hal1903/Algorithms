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

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> umap;
    fore(c, magazine){
        if (umap.find(c) == umap.end())
            umap.insert(make_pair(c, 1));
        else // found
            umap[c]++;
    }
    for(const auto& elem : umap){
        std::cout << elem.first << ": " << elem.second << " " << "\n";
    }
    fore(c, ransomNote){
        if (umap.find(c) == umap.end())
            return 0;
        else if (umap[c] == 0)
            return 0;
        else //umap[c] > 0
            umap[c]--;
    }
    return 1;
}

int main(){
    string r = "aa";
    string m = "aba";
    cout << canConstruct(r, m);
    return 0;
}