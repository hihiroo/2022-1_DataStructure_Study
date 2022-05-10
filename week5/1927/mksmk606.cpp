// 최소 힙
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a == 0){
            if(!pq.empty()){
                cout << -pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
        else{
            pq.push(-a);
        }
    }
}
