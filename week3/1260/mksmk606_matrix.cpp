#include <iostream>
using namespace std;

int arr[1005][1005], n,m, chk[1005];

void dfs(int vtx){
    chk[vtx] = 1;
    cout << vtx << " ";

    for(int i=1; i<=n; i++){
        if(arr[vtx][i] == 1 && !visit[i]){
            dfs(i);
        }
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        printf("%d ",vtx);

        for(int i=1; i<=n; i++){
            if(arr[vtx][i] == 1 && !visit[i]){
                visit[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    int s;
    cin >> n >> m >> s;

    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a][b] = 1; arr[b][a] = 1;
    }

    dfs(s);
    cout << '\n';
    memset(visit,0,sizeof(visit));
    bfs(s);
}
