// Problema : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include <iostream>
#include<vector>
#include<climits> //para usar INT_MAX
using namespace std;

vector<int> Grafo[1001];
int visitado[1001]={0},minDistancia=INT_MAX,ans=INT_MAX;


void dfs(int nodo,int distancia)
{
    if(visitado[nodo]==-1){//si es un pais(nodo) donde vive alguna chica
        minDistancia=min(minDistancia,distancia);
        ans=min(nodo,ans);//Si dos o más chicas están a la misma distancia mínima, entonces él aceptará la propuesta de la chica que vive en un país con identificación mínima.
    }
    visitado[nodo]=distancia;

    for(int i=0;i<Grafo[nodo].size();i++)
    {
        int aux=visitado[Grafo[nodo][i]];
        if(aux==0||aux==-1) //si el pais vecino(nodo hijo) no está visitado 
        {
            dfs(Grafo[nodo][i],distancia+1);
        }
    }
}
int main()
{
    int nodos;
    
    scanf("%d",&nodos);//cin>>n;
    for(int i=0;i<nodos-1;i++)
    {
        int x,y;
        //cin>>x>>y;
        scanf("%d%d",&x,&y);//existe una arista entre el nodo 'x' y 'y'
        Grafo[x].push_back(y);
        Grafo[y].push_back(x);//cuando el grafo es no dirigido tambien hay una arista entre 'y' y 'x'
    }


    int q,num;
    
    scanf("%d",&q);//cin>>q;

    while(q--){   
        scanf("%d",&num);//cin>>num;
        visitado[num]= -1;// marcamos con '-1' para representar el país donde viven las chicas 
    }

    int distancia=1;

    dfs(1,distancia);//el primer parametro es el nodo del que se quiere empezar,el segundo es la distancia que existe hasta dicho nodo(seria '0´ pero para este problema no afecta)
    printf("%d\n",ans);//cout<<ans<<"\n";
    

    return 0;
}