#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;

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
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(a == "size"){
            cout << s.size() << '\n';
        }
        else if(a == "empty"){
            cout << s.empty() << '\n';
        }
        else if(a == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
}
