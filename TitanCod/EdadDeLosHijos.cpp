#include <bits/stdc++.h>
using namespace std;
struct numero{
    int a,b,c;
    numero(int A,int B,int C){
        this->a=A;
        this->b=B;
        this->c=C;
    }
};
void Find(int num){
    int sumAns=-1;
    priority_queue<pair<int,pair <int ,int> > > m[1000];    
    for(int i=1;i*i<=num;i++){
        for(int j=i;j*j<=num;j++){
            
            if(num%(i*j)==0 && j<=(num/(i*j))){
                //numero aux(i,j,num/(i*j));
                int z=num/(i*j);
                //cout<<"-> "<<i<<" "<<j<<" "<<z<<" = "<<i+j+z<<endl;
                m[i+j+z].push(make_pair(i,make_pair(j,z)) );
                if(m[i+j+z].size()>=2){
                    if(sumAns==-1){sumAns=i+j+z;}//cout<<sumAns<<endl;}
                    else
                        if(sumAns!=(i+j+z)){cout<<"+\n";return;}

                    
                }
            }
        }
    }
    if(sumAns!=-1){
        pair<int ,pair <int,int> > au=m[sumAns].top();
        cout<<au.first<<" "<<au.second.first<<" "<<au.second.second<<"\n";
        return;
    }
    cout<<"*\n";
}
int main(){
    int casos,num;
    cin>>casos;
    while(casos--){
        cin>>num;
        Find(num);
    }
}