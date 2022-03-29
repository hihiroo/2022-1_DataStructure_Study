#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string a;
        cin >> a;
        
        stack<char> s;

        bool vps = true; // 올바른 괄호쌍이 아니면 false
        for(int i=0; i<a.size(); i++){
            if(a[i] == '(') s.push('(');
            else{ //닫는 괄호
                if(s.empty()){ // pop해야되는데 스택이 비어있다면
                    vps = false; // 닫는 괄호가 더 많이 등장 -> 올바르지 않은 괄호쌍임
                    break;
                }
                else s.pop();
            }
        }

        if(!s.empty()) vps = false; // 스택에 여는 괄호가 남아있다면 여는 괄호가 더 많이 등장했다는 것
        
        if(vps) cout << "YES\n";
        else cout << "NO\n"; 
    }
}