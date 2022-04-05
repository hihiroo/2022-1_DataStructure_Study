#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, arr[25][25], chk[25][25], cnt;

bool safe(int y, int x){ // 배열 크기를 벗어나는지 확인 용도
    return y>=0 && y<n && x>=0 && x<n;
}

void dfs(int y, int x){
    chk[y][x] = 1;
    cnt++; // 단지 크기 증가
    if(safe(y+1,x) && arr[y+1][x] == 1 && !chk[y+1][x]) dfs(y+1,x);
    if(safe(y,x+1) && arr[y][x+1] == 1 && !chk[y][x+1]) dfs(y,x+1);
    if(safe(y,x-1) && arr[y][x-1] == 1 && !chk[y][x-1]) dfs(y,x-1);
    if(safe(y-1,x) && arr[y-1][x] == 1 && !chk[y-1][x]) dfs(y-1,x);
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !chk[i][j]){
                cnt = 0; // 단지 크기 초기화
                dfs(i,j); // 탐색 시작
                ans.push_back(cnt); // 탐색 종료까지 방문한 집 개수 저장
            }
        }
    }

    cout << ans.size() << '\n';

    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << '\n';
    }
}
