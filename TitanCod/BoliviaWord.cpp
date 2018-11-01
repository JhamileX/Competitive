#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string x="BOLIVIA";
    cin>>n;
    set<char> s;
    for(int i=0;i<7;i++)s.insert(x[i]);
    while(n--){
        cin>>x;
        int c=0;
        set<char> s2;
        for(int i=0;i<x.size();i++){
            s2.insert(x[i]);if(x[i]=='I')c++;
        }
        if(s==s2 && c>1)cout<<"ES POSIBLE\n";
        else cout<<"NO ES POSIBLE\n";

    }
}