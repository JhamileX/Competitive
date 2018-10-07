#include <bits/stdc++.h>

using namespace std;
vector<int> grafo[10001];
int distancia[10001],ultimoNodo;

void BFS(int nodo){
    queue<int> Q;
    memset(distancia,-1,sizeof(distancia) ); //llenar de '-1' a cada posicion del vector 'distancia', esto servirá para verificar si un nodo no fue visitado
    Q.push(nodo);
    distancia[nodo]=0;
    while(!Q.empty()){  //si la cola no esta vacia
    
        int nodoActual=Q.front();
        Q.pop();
        for(int i=0;i<grafo[nodoActual].size();i++){ //todos los nodos Hijo que tiene 'nodoActual'
            int nodoHijo=grafo[nodoActual][i];
            if(distancia[nodoHijo]==-1){  //si el nodo hijo no esta visitado
                distancia[nodoHijo]=distancia[nodoActual]+1;//aumentar la distancia en uno para el nodo Hijo
                if(distancia[ultimoNodo]!=-1)return;    //distancia ya encontrada 
                Q.push(nodoHijo);
            }
        }
    }
    return;
}

int main(){
    int casos,aristas,vertices,u,v;
    
    //cin>>casos;
    scanf("%d",&casos);
    while(casos--){
        //cin>>vertices>>aristas; 
        scanf("%d%d",&vertices,&aristas);//cantidad de nodos, cantidad de coneciones
        ultimoNodo=vertices;
        for(int i=0;i<aristas;i++){
            scanf("%d%d",&u,&v); ////existe una arista entre el nodo 'u' a 'v'
            grafo[u].push_back(v);
            grafo[v].push_back(u);  //cuando el grafo es no dirigido
        }
        BFS(1);

        //cout<<distancia[ultimoNodo]<<"\n";
        printf("%d\n", distancia[ultimoNodo]);
        for(int i=1;i<=vertices;i++)grafo[i].clear();
    }
    return 0;
    
}