#include <iostream>
using namespace std;

int productoPunto(int x1,int y1,int x2,int y2){
    return x1*x2+y1*y2;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int x[4],y[4],b=0;
        for(int i=0;i<3;i++)
            cin>>x[i]>>y[i];

        for(int i=0;i<3;i++)
            if(productoPunto(x[(i+1)%3]-x[i],y[(i+1)%3]-y[i], x[(i+2)%3]-x[i],y[(i+2)%3]-y[i])==0 )
                b=1;
        if(b)cout<<"SI\n";
        else
            cout<<"NO\n";
                
    }
}