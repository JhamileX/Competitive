#include <bits/stdc++.h>
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0);cout.tie(0); } } _;

#define ict int t;cin>>t;while(t--)
#define lct long long int t;cin>>t;while(t--)
#define in(a) int a; cin>>a;
#define llin(a) ll a; cin>>a;

#define srep(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)

#define pb push_back

typedef long long int ll; // [9,223,372,036,854,775,807 to -9.....808]
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sl;
typedef map<string, ll> mapsl;
typedef map<string, int> mapsi;
typedef map<int,int> mapii;
typedef map<ll, ll> mapll;

set<int> node[100009];
bool visit[100009];
ll bfs(int start,int ver,int dest)
{
    for(int i=0;i<=ver;i++)
        visit[i]=false;
    queue<pii> st;
    st.push(make_pair(0,start));
    visit[start]=true;
    while(!st.empty())
    {
        int ind=st.front().second;
        for(set <int>::iterator it = node[ind].begin();it != node[ind].end();++it)
        {
            int y=(*it);
            if(y==dest)
            return st.front().first+1;
            if(visit[y]==false)
            {
                st.push(make_pair(st.front().first+1,y));
                visit[y]=true;
            }
        }
        st.pop();
    }
return -1;
}


int main()
{
    bool chk[100005]={0};
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int dest;
        //cin>>dest;
        scanf("%d",&dest);
        int q;
        //cin>>q;
        scanf("%d",&q);
        int n=1;
        int x,y,d;
        memset(chk,0,100005);
        for(int i=0;i<q;i++)
        {
            //cin>>x>>y;
            scanf("%d%d",&x,&y);
            if(chk[x]==false)
            {
                node[x].clear();
                chk[x]=true;
            }
            if(chk[y]==false)
            {
                node[y].clear();
                chk[y]=true;
            }

            node[x].insert(y);
            node[y].insert(x);
            n=max(n,max(x,y));
            visit[i]=false;
        }

        //cout<<bfs(1,n,dest)<<endl;
        printf("%d\n",bfs(1,n,dest));
    }
}