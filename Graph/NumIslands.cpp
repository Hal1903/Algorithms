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

int numIslands(vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    const vector<int> dx = {-1, 1, 0, 0};
    const vector<int> dy = {0, 0, -1, 1};
    int n = 0;
    rep(a, 0, grid.size()){
        rep(b, 0, grid[0].size()){
            if (grid[a][b] == '1'){
                q.push(make_pair(a,b));
                while (!q.empty()){
                    int i=q.front().first;
                    int j=q.front().second;
                    grid[i][j] = 0;
                    q.pop();
                    rep(k, 0, 4){
                        int newX = i + dx[k];
                        int newY = j + dy[k];
                        
                        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1') {
                            q.push({newX, newY});
                            grid[newX][newY] = '0'; 
                        }
                    }
                    // if (i+1 < grid.size() && grid[i+1][j]=='1')
                    //     q.push(make_pair(i+1, j));
                    // if (j+1 < grid[0].size() && grid[i][j+1]=='1')
                    //     q.push(make_pair(i, j+1));
                    // if (j-1 >= 0 && grid[i][j-1]=='1')
                    //     q.push(make_pair(i, j-1));
                    // if (i-1 >= 0 && grid[i-1][j]=='1')
                    //     q.push(make_pair(i-1, j));
                }
                n++;
            }
        }
    }
    return n;
}

int main(){
    vector<vector<char>> grid = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };
    // {
    //     {'1','1','0','0','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','1','0','0'},
    //     {'0','0','0','1','1'}
    // };
    cout << numIslands(grid);
    return 0;
}