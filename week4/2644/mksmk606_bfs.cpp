// 촌수계산
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v(101);

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

    vector<int> dist(n+1);
    queue<int> q;
    q.push(x);
    dist[x] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(!dist[next]){
                q.push(next);
                dist[next] = dist[vtx] + 1;
            }
        }
    }
    cout << dist[y]-1 << '\n';
}
