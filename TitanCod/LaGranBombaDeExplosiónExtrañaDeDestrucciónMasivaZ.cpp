//75 puntos
#include <bits/stdc++.h>
using namespace std;
int main(){
    int casos,nBombas,x1,x2,y1,y2,m=0;
    scanf("%i",&casos);//cin>>casos;
    for(int k=1;k<=casos;k++){
        scanf("%i",&nBombas);//cin>>nBombas;
        priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > ejeX[100000]; 
        while(nBombas--){
            scanf("%i%i%i%i",&y1,&x1,&y2,&x2);//cin>>y1>>x1>>y2>>x2;
            m=max(m,x2);
            for(int i=x1;i<x2;i++){
                ejeX[i].push(make_pair(y1,y2));
            }
        }
        //cout<<"hello miss\n";
        long long area=0;
        int maxiAnterior=0;
        for(int i=0;i<m;i++){
            maxiAnterior=0;
            while(!ejeX[i].empty()){
                pair<int,int> tope=ejeX[i].top();
                ejeX[i].pop();

                int maxi=max(maxiAnterior,tope.second);
                int mini=max(maxiAnterior,tope.first);
                //cout<<mini<<" "<<maxi<<" = "<<maxi-mini<<"     "<<tope.first<<" " <<tope.second<<endl;
                area+=maxi-mini;
                maxiAnterior=max(maxi,mini);
            }
        }
        printf("Caso #%i: %lld\n",k,area);//cout<<"Caso #"<<k<<": "<<area<<"\n";
    }
}