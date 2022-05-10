// 트리의 부모 찾기
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

vector<vector<int> > v(100005);
int par[100005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int adj = v[vtx][i];
        if(par[adj] == 0){
            par[adj] = vtx;
            dfs(adj);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    par[1] = -1;
    dfs(1);

    for(int i=2; i<=n; i++) cout << par[i] << '\n';
}
