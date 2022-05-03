// 유기농 배추 bfs 버전
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[51][51], chk[51][51], n, m;

bool safe(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs(int y, int x){
    queue<pair<int,int> > q;
    q.push({y,x});
    chk[y][x] = 1;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(safe(i+1,j) && arr[i+1][j] && !chk[i+1][j]){
            q.push({i+1,j});
            chk[i+1][j] = 1;
        }
        if(safe(i,j+1) && arr[i][j+1] && !chk[i][j+1]){
            q.push({i,j+1});
            chk[i][j+1] = 1;
        }
        if(safe(i-1,j) && arr[i-1][j] && !chk[i-1][j]){
            q.push({i-1,j});
            chk[i-1][j] = 1;
        }
        if(safe(i,j-1) && arr[i][j-1] && !chk[i][j-1]){
            q.push({i,j-1});
            chk[i][j-1] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        //for(int i=0; i<50; i++)
        //for(int j=0; j<50; j++) chk[i][j] = 0, arr[i][j] = 0;

        memset(arr,0,sizeof(arr));
        memset(chk,0,sizeof(chk));

        int k;
        cin >> m >> n >> k;

        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1 && !chk[i][j]){
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }
}