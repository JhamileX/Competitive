#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef vector <int> vi;
typedef pair <int,int > ii;
typedef vector <ii> vii;
const int MAX=1000,inf=(1<<26);
vi dis(MAX,inf);
vii G[MAX];
set <string> S;
void Dijkstra(int ini){
    priority_queue <ii> Q;
    Q.push(make_pair(0,ini));
    dis[ini]=0;
    while(!Q.empty()){
        
        ii s=Q.top(),u;
        Q.pop();
        int d= -s.first,v=s.second,costo,hijo;
        cout<<v<<endl;
        for(int i=0;i<G[v].size();i++){
            u=G[v][i];
            costo= -u.first+d;
            hijo=u.second;
            if(costo<dis[hijo]){
                dis[hijo]=costo;
                Q.push(make_pair(-costo,hijo));
            }
        }
    }
}
int main()
{
   
    int vertices,Aristas,a,b,w,ini,fin;
    cin>>vertices>>Aristas;
    for(int i=0;i<Aristas;i++){
        cin>>a>>b>>w;//existe una arista entre el nodo 'a' a 'b' coun un peso 'w'
        G[a].push_back(make_pair(-w,b));
        G[b].push_back(make_pair(-w,a));//cundo es un grafo no dirigido
    }
    cin>>ini;
    Dijkstra(ini);
    for(int i=1;i<=vertices;i++)cout<<i<<" "<<dis[i]<<endl;
    return 0;
}