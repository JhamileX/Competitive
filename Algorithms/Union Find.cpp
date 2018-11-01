#include <bits/stdc++.h>

using namespace std;
int padre[100002];
void init(int n){
    for(int i=0;i<=n;i++)padre[i]=i;
}
int Find(int x){
    if(x==padre[x])return x;
    //return Find(padre[x]); //sin DP :(
    return padre[x]=Find(padre[x]);//DP :)
}
bool mismo_conjunto(int y,int x){
    return Find(x)==Find(y);
}
void unir(int x,int y){
    padre[Find(x)]=Find(y);
}

int main()
{
    int n,p,u,v;
    cin>>n>>p;
    init(n);
    while(p--){
        cin>>u>>v;
        unir(u,v);
    }
    map <int,int> mapa;
    for(int i=0;i<n;i++)mapa[Find(i)]++;
    map <int,int>::iterator it2,it=mapa.begin();
    long long ans=0;
    for(;it!=mapa.end();it++){
        it2=it;
        for(it2++;it2!=mapa.end();it2++){
            ans+= it->second*it2->second;
            //cout<<it->second<<" "<< it2->second<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}