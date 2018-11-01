#include <iostream>
using namespace std;
int tree[40000],v[10000];
void init(int nodo,int l,int r){
    if(l==r)return v[l];
    int mitad=(l+r)/2;
    init(nodo*2,l,mitad);
    init(nodo*2+1,mitad+1,r);
    tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
}
int query(int nodo,int l,int r,int a,int b){
    if(r<a||l>b)return 0;
    if(a>=l && b<=r)return tree[nodo];
    int mitad=(l+r)/2;
    return query(nodo*2,l,mitad,a,b)+query(nodo*2+1,mitad+1,r,a,b);
}

void update(int nodo,int l,int r,int position,int date){
    if(r<position||l>position)return;
    if(r==l)  date;

}

int main(){
    
    return 0;
}