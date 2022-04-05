#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > g(1001);
int chk[1001], chk2[1001];

void dfs(int vtx){
    chk[vtx] = 1;
    cout << vtx << ' ';

    for(int i=0; i<g[vtx].size(); i++){ // 인접한 정점들만 확인
        int next = g[vtx][i];
        if(!chk[next]) dfs(next);
    }
}

void bfs(int vtx){
    queue<int> q;
    q.push(vtx);
    chk2[vtx] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        cout << vtx << ' ';

        for(int i=0; i<g[vtx].size(); i++){
            int next = g[vtx][i];
            if(!chk2[next]){
                q.push(next);
                chk2[next] = chk2[vtx] + 1; // 출발점으로부터의 거리 저장
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // 양방향 간선이기 때문에 a->b, b->a 둘 다 저장
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){ // 정점번호가 작은 순으로 방문위해 인접리스트 정렬
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
}
