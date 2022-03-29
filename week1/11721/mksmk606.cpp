#include <iostream>
using namespace std;

int main(){
    string a;
    cin>>a;

    for(int i=0;i<a.length();i++){
        printf("%c",a.at(i));
        if((i+1)%10==0) printf("\n");
    }
}