#include <bits/stdc++.h>
using namespace std;
int p[1001];
int eratostenes(int n,int nTachBuscado){
    memset(p,0,sizeof p);
    int c=0;
    for(int i=2;i<=n;i++){
        if(p[i]==0){
            for(int j=i;j<=n;j+=i){
                if(p[j]==0){
                    
                    p[j]=1;
                    c++;
                    //cout<<j<<" "<<c<<endl;
                    if(c==nTachBuscado){
                        //cout<<"->"<<c<<endl;
                        return j;}
                }
                
            }
        }
    }
}
int main(){
    int casos,n,nTachBuscado;
    cin>>casos;
    while(casos--){
        cin>>n>>nTachBuscado;
        cout<<eratostenes(n,nTachBuscado)<<"\n";
    }

                
}