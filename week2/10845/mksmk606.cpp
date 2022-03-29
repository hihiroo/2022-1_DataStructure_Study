#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    queue<int> s;

    while(n--){
        string a;
        cin >> a;

        if(a == "push"){
            int x;
            cin >> x;
            s.push(x);
        }
        else if(a == "pop"){
            if(s.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << s.front() << '\n';
                s.pop();
            }
        }
        else if(a == "size"){
            cout << s.size() << '\n';
        }
        else if(a == "empty"){
            cout << s.empty() << '\n';
        }
        else if(a == "front"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.front() << '\n';
        }
        else if(a == "back"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.back() << '\n';
        }
    }
}
