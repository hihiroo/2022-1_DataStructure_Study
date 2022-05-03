//촌수계산 dfs 버전
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v(101);
int dist[101];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!dist[next]){
            dist[next] = dist[vtx] + 1;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dist[x] = 1;
    dfs(x);
    cout << dist[y]-1;
}
