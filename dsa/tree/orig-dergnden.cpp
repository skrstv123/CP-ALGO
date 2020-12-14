#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lookup[200001][25];
ll Timer=0;


//BIT From GFG
ll getSum(ll BITree[], ll index) 
{ 
    ll sum = 0; 
    index = index + 1; 
  
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 

void updateBIT(ll BITree[], ll n, ll index, ll val) 
{ 
 
    index = index + 1; 
 
    while (index <= n) 
    { 
    
    BITree[index] += val; 
  
    
    index += index & (-index); 
    } 
} 
  

ll *constructBITree(ll arr[], ll n) 
{ 
    // Create and initialize BITree[] as 0 
    ll *BITree = new ll[n+1]; 
    for (ll i=1; i<=n; i++) 
        BITree[i] = 0; 
  

    for (ll i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
  
    return BITree; 
} 



//sparsetable From GFG
void buildSparseTable(ll arr[], ll n) 
{ 

    for (ll i = 0; i < n; i++) 
        lookup[i][0] = arr[i]; 
  

    for (ll j = 1; (1 << j) <= n; j++) { 
  

        for (ll i = 0; (i + (1 << j) - 1) < n; i++) { 
  

            if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1]) 
                lookup[i][j] = lookup[i][j - 1]; 
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1]; 
        } 
    } 
} 
  
// Returns maximum of arr[L..R] 
ll query(ll L, ll R) 
{ 

    ll j = (ll)log2(R - L + 1); 
  

    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j]) 
        return lookup[L][j]; 
  
    else
        return lookup[R - (1 << j) + 1][j]; 
} 
  
  
  
void dfs(ll cur, ll par, vector<ll> grap[], ll tin[], ll tout[],bool chk[])
{
    tin[cur]=Timer;
    chk[cur]=true;
    Timer++;
    for (ll i = 0; i < grap[cur].size(); i++)
    {
        if (grap[cur][i] != par)
        {
            dfs(grap[cur][i], cur, grap, tin, tout,chk);
        }
    }
    tout[cur]=Timer;
    Timer++;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, k, t, ip, n, q;

    cin >> n >> q;
    ll h[n], a[n];
    //Taking hight
    vector<ll> rgrp[n], lgrp[n];
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    //Taking weight
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    //Initialization
    ll z = sizeof(h) / sizeof(h[0]);
    buildSparseTable(h, z);
    
    stack<ll> st;

    ll ltin[n], ltout[n], rtin[n], rtout[n];
    bool lckh[n], rckh[n];
    memset(lckh, false, sizeof(lckh));
    memset(rckh, false, sizeof(rckh));
    ll LFTree[500001];
    ll RFTree[500001];
    
    //EveryThing for Left
    //Stack based graph
    st.push(0);
    for (i = 1; i < n; i++)
    {
        while (h[st.top()] < h[i])
        {
            lgrp[i].push_back(st.top());
            st.pop();
            if (st.empty())
            {
                break;
            }
        }
        st.push(i);
    }
    //DFS and Taking inTime and outTime
    while (st.empty() == false)
    {
        ll x = st.top();
        st.pop();
        dfs(x, -1, lgrp, ltin, ltout, lckh);
    }
    Timer=0;
    //Filling Flatting Tree
    i=0;
    for(auto each:ltin)
    {
       
        LFTree[each]=a[i];
        i++;
    }
    i=0;
    for(auto each:ltout)
    {
        //cout<<each<<" out ";
        LFTree[each]=a[i]*-1;
        i++;
    }

    //Do For right
    //stack based operation
    
    st.push(n - 1);
    for (i = n - 2; i >= 0; i--)
    {
        while (h[st.top()] < h[i])
        {
            rgrp[i].push_back(st.top());
            st.pop();
            if (st.empty())
            {
                break;
            }
        }
        st.push(i);
    }
    //taking timein and timeout
    while (st.empty() == false)
    {
        ll x = st.top();
        st.pop();
        dfs(x, -1, rgrp, rtin, rtout, rckh);
    }
    Timer=0;
    i=0;
    for(auto each:rtin)
    {
        RFTree[each]=a[i];
        i++;
    }
    i=0;
    for(auto each:rtout)
    {
        RFTree[each]=a[i]*-1;
        i++;
    }

    
    //creating binary Index Tree on LeftFlatteningTree
    ll siz = (n*2)-1; 
    ll *LBITree = constructBITree(LFTree, siz);
    
    //creating binary Index Tree on RightFlatteningTree
    ll siz1 = (n*2)-1; 
    ll *RBITree = constructBITree(RFTree, siz1);

    //action Foreach Query
    while (q--)
    {
        ll ty, b, c;
        cin >> ty >> b >> c;
        if (ty == 1)
        {
            b--;
            //For update just update the difference in all the place
            ll diff=a[b]-c;
            ll ind=ltout[b];
            updateBIT(LBITree, siz, ind, diff);
            ind=rtout[b];
            updateBIT(RBITree, siz, ind, diff);
            diff*=-1;
            ind=ltin[b];
            updateBIT(LBITree, siz, ind, diff);
            ind=rtin[b];
            updateBIT(RBITree, siz, ind, diff);
            
            a[b]=c;
            
        }
        else
        {
            b--;
            c--;
            if (c == b)
            {
                cout << a[b] << "\n";
            }
            else if (h[c] >= h[b])
            {
                cout << "-1\n";
            }
            else
            {
                     ll sum = 0;
                     ll mxx=0;
                    // so it is in Ltree
                    if (b > c)
                    {
                        sum =getSum(LBITree,ltin[c]) - getSum(LBITree,ltin[b]-1);
                        mxx = query(c, b - 1);
                    }
                    //it is in RTree
                    else
                    {
                        sum =getSum(RBITree, rtin[c]) - getSum(RBITree, rtin[b]-1);
                        mxx = query(b + 1, c);
                    }
                    if (mxx >= max(h[b], h[c]))
                    {
                        sum = -1;
                    }
                    cout << sum << "\n";
            }
        }
        
    }

    return 0;
}