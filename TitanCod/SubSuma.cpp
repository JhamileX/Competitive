#include <iostream>

using namespace std;

int main(){
    int n,total;
    while(cin>>n>>total){
        int arr[n];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int sum=0,beg=1,i;
        for( i=1;i<=n;i++){
            sum+=arr[i];
            while(sum>total && beg<=i){
                sum-=arr[beg];
                beg++;
            }
            if(sum==total){
                cout<<beg<<" "<<i<<"\n";
                break;
            }
        }
        if(i==n+1)cout<<"-1\n";
    }
    return 0;
}