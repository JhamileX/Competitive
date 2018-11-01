//0 puntpos
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,total;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum,beg,q,b;
    cin>>q;
    for(int j=0;j<q;j++){
        cin>>total;
        sum=0,beg=1,b=1;
        vector<pair<int,int > > ans ;
        for(int i=1;i<=n;i++){
            sum+=arr[i];
            while(sum>total && beg<=i){
                sum-=arr[beg];
                beg++;
            }
            if(sum==total){
                //cout<<beg-1<<" "<<i-1<<"\n";
                ans.push_back(make_pair(beg-1,i-1));
                b=0;
            }
        }
        ans.push_back(make_pair(1,1));
        if(b)cout<<"-1\n";
        else{
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
    
    
    return 0;
}