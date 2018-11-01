#include <iostream>
using namespace std;
int main(){
    int casos,n,x;
    cin>>casos;
    while(casos--){
        cin>>n;
        int v[n+1],mini=100000,aux,ans=0;
        v[0]=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            mini=min(mini,v[i]);
        }
        for(int i=1;i<=n;i++){
            aux=(v[i]-mini)*6- (v[i]-mini>0?(( (v[i]-mini)-1)*2):0);
            if(aux>0){
                int au=min(v[i]-mini,v[i-1]-mini);
                ans+=aux-au*2;
            }
            
        }
        cout<<ans<<endl;


    }
    return 0;
}