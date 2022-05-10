// 중앙값 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int m;
        cin >> m;

        priority_queue<ll> left, right;
        ll mid;
        cin >> mid;
        cout << (m+1)/2 << '\n' << mid << " ";

        for(int i=2; i<=m; i++){
            ll a;
            cin >> a;

            if(a > mid) right.push(-a);
            else left.push(a);

            if(left.size() > right.size()){
                right.push(-mid);
                mid = left.top();
                left.pop();
            }
            else if(left.size() < right.size()){
                left.push(mid);
                mid = -right.top();
                right.pop();
            }
            if(i % 2) cout << mid << " ";
            if(i % 20 == 0 && i+1 < m) cout << '\n';
        }
        cout << '\n';
    }
}
