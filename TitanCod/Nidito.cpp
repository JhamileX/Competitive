//puntaje 0
#include <bits/stdc++.h>
using namespace std;
int main(){
    int casos,n,m;
    cin>>casos;
    int x[]={1,1,1,-1,-1,-1,0,0};
    int y[]={0,1,-1,0,1,-1,1,-1};
    
    while(casos--){
        cin>>n>>m;
        char mat[n+2][m+2];
        vector <pair<int ,int> > v;
        memset(mat,0,sizeof mat);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='*')v.push_back(make_pair(i,j));
            }
        }
        int mx=0,ansx=1000,ansy=1000,aux=1000000;
        for(int i=0;i<v.size();i++){
            int c=0,f=v[i].first,s=v[i].second;
            for(int j=0;j<8;j++){
                int xx=f+x[j],yy=s+y[j];
                if(mat[xx][yy]=='A')c++;
            }
            if(c==mx && s*s+f*f<aux&&c!=0){
                aux=s*s+f*f;
                ansx=f;
                ansy=s;
            }
            if(c>mx){
                mx=c;
                aux=s*s+f*f;
                ansx=f;
                ansy=s;
            }
        }
        if(mx==0)cout<<0<<" "<<0<<endl;
        else
            cout<<ansx<<" "<<ansy<<"\n";
    }
    //contraseña de gordito que se parece al diego angulo :v=Al3xj0he
    return 0;
}