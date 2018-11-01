#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int vec[10000][10000];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vec[u][v]=1;
        vec[v][u]=1;
    }
	int vis[n+1];
    memset(vis,0,sizeof(vis));
	queue <int> q;
 	q.push(1);
 	vis[1]=0;
 	while(!q.empty()){
 		int x=q.front();
 		q.pop();
 		for(int i=1;i<=n;i++){
  			if(vec[x][i]!=0&&vis[i]==0){
   				vis[i]=vis[x]+1;
   				q.push(i);
  			}
 		}
 	}
    cout<<vis[n]<<endl;
    return 0;
}