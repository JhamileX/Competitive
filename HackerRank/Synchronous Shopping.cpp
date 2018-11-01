#include <bits/stdc++.h>
using namespace std;
struct par{
    int w,y;
    par(int a,int b){
        w=a;
        y=b;
    }
    bool operator<(const par &comp)const{
        return w<comp.w;
    }
};
vector<int> tipos[1111];
vector<par> grafo[1111]; 
set <int > st;
int nd,k, distancia[1111];
void marc(int n){
    for(int i=0;i<tipos[n].size();i++)st.insert(tipos[n][i]);
}

void Dijkstra(int ini){
    //memset(distancia,1<<22,sizeof distancia);
    fill(distancia,distancia+1111,1<<22);
    priority_queue <par > Q;
    Q.push(par(0,ini));
    distancia[ini]=0;
    bool b=1;
    while(!Q.empty()){
        par p=Q.top();
        Q.pop();
        
        int peso= -p.w,nodo=p.y;
        marc(nodo);
        if(st.size()>=k and b==1){
            b=0;
            nd=nodo;
        }
        for(int i=0;i<grafo[nodo].size();i++){
            p=grafo[nodo][i];
            int costo=peso-p.w;
            if(costo<distancia[p.y]){
                       
                distancia[p.y]=costo;
                Q.push(par(-costo,p.y));
                
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m>>k;
    
    for(int i=1;i<=n;i++){
        int cantidad,auxi;
        cin>>cantidad;
        while(cantidad--){
            cin>>auxi;
            tipos[i].push_back(auxi);
        }
    }
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        grafo[u].push_back(par(-w,v));
        grafo[v].push_back(par(-w,u));
    }
    cout<<"entrada terminada";
    Dijkstra(1);
    int ans=distancia[nd];
    // for(int i=1;i<=n;i++){
    //     cout<<i <<"="<<distancia[i]<<endl;
    // }
    cout<<ans<<" "<<nd<<endl;
    Dijkstra(nd);
    // for(int i=1;i<=n;i++){
    //     cout<<i <<"="<<distancia[i]<<endl;
    // }
    ans+=distancia[n];
    cout<<ans<<" "<<nd;
    return 0;
}