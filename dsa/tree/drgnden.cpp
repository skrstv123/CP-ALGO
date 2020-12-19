/*
** ETT
** tree flattening
** sparse table - repeat safe queries on static arrays
** fenwick tree
40441964
*/
#include <bits/stdc++.h>
using ll = long long int; 
using namespace std;

ll lookup[200001][25];
ll Timer=0;

//sparsetable From GFG
void buildSparseTable(ll arr[], ll n) { 
    for (ll i = 0; i < n; i++)  lookup[i][0] = arr[i]; 
    for (ll j = 1; (1 << j) <= n; j++) { 
        for (ll i = 0; (i + (1 << j) - 1) < n; i++) {  
            lookup[i][j] = max(lookup[i][j - 1],lookup[i + (1 << (j - 1))][j - 1]);
        } 
    } 
} 
 
// Returns maximum of arr[L..R] 
ll query(ll L, ll R) {
   ll j = (ll)log2(R - L + 1); 
   return max(lookup[L][j],lookup[R - (1 << j) + 1][j]);
} 
 
// fenwick tree
void updatedatree(ll tree[], ll n, ll i, ll val){
	i++;
	while(i<=n){
		// cout<<tree[i]<<" ";
		tree[i]+=val;
		// cout<<tree[i]<<" \n";
		i+=(i&(-i));
	}
}

ll getsum_tree(ll tree[], ll i){
	ll sum=0;
	i++;
	while(i>0){
		sum+=tree[i];
		i-=(i&(-i));
	}
	return sum;
}

ll *implementationwiseweak_tree(ll arr[], ll n){
	ll *tree = new ll[n+1];
	for (ll i = 0; i <= n; ++i) tree[i] = 0;
	for (ll i = 0; i < n; ++i) updatedatree(tree, n, i, arr[i]);
	return tree;
}

void dfs(ll cur, ll par, vector<ll> grap[], ll tin[], ll tout[],bool chk[])
{
    tin[cur]=Timer;
    chk[cur]=true;
    Timer++;
    for (auto x: grap[cur]){
        if (x != par){dfs(x, cur, grap, tin, tout,chk);}
    }
    tout[cur]=Timer;
    Timer++;
}
 


main(){
	ll n,q;
	cin>>n>>q;
	ll h[n], a[n];
	for (ll i = 0; i < n; ++i)cin>>h[i];
	for (ll i = 0; i < n; ++i)cin>>a[i];
	ll z = sizeof(h) / sizeof(h[0]);
    buildSparseTable(h, z);
    
    // cout<<"spt done\n";
    ll ltin[n], ltout[n], rtin[n], rtout[n];
    bool lckh[n], rckh[n];

    ll LFTree[500001]; // try 4*(1e5+1)
    ll RFTree[500001];

    // graphs 
	vector<ll> going_left[n], going_right[n];
	stack<ll> stak;

	// for left // loopin gin increasing direction
	stak.push(0);
	for (ll i =1;i<n;i++){
		while(h[stak.top()]<h[i]){
			ll ch=stak.top();
			going_left[i].push_back(ch);
			stak.pop();
			if(stak.empty()) break;
		}
		stak.push(i);
	}
	// cout<<"st done\n";
	// dfs to find ltin and ltout
	while(!stak.empty()){
		dfs(stak.top(), -1, going_left, ltin, ltout, lckh);
		stak.pop();
	}
	// lets fill LFTree
	for(ll i=0;i<n;i++){
		LFTree[ltin[i]] = a[i];
		LFTree[ltout[i]] = -a[i];
	}
	// cout<<"tf done\n";
	// for right // looping in increasing direction
	stak.push(n-1);
	for (ll i =n-2;i>=0;i--){
		while(h[stak.top()]<h[i]){
			ll ch=stak.top();
			going_right[i].push_back(ch);
			stak.pop();
			if(stak.empty()) break;
		}
		stak.push(i);
	}

	Timer=0;
	// dfs to find rtin and rtout
	while(!stak.empty()){
		dfs(stak.top(), -1, going_right, rtin, rtout, rckh);
		stak.pop();
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<ltout[i]<<' ';
	// }

	// lets fill RFTree
	for(ll i=0;i<n;i++){
		RFTree[rtin[i]] = a[i];
		RFTree[rtout[i]] = -1*a[i];
		// cout<<"all tf done\n";
	}

	//creating binary Index Tree on LeftFlatteningTree
    ll siz = (n*2)-1; 
    ll *LBITree = implementationwiseweak_tree(LFTree, siz);
    	
    //creating binary Index Tree on RightFlatteningTree
    ll *RBITree = implementationwiseweak_tree(RFTree, siz);


	while(q--){
	// for (int i = 0; i < 2*n; ++i)
	// {
	// 	cout<< LFTree[i]<< ' ';
	// }cout<<'\n';
	// for (int i = 0; i < 2*n; ++i)
	// {
	// 	cout<< RFTree[i]<< ' ';
	// }cout<<'\n';

		// cout<<"query\n";
		ll t, b, c;
		cin>> t>> b>> c;
		if(t==1){
			b--;
			ll diff = c-a[b];
            ll ind=ltin[b];
            updatedatree(LBITree, siz, ind, diff);
        	ind = rtin[b];
        	updatedatree(RBITree, siz, ind, diff);
        	ind = ltout[b];
        	updatedatree(LBITree, siz, ind, -diff);
        	ind = rtout[b];
        	updatedatree(RBITree, siz, ind, -diff);
			a[b]=c;
			// cout<< ltin[b] <<" "<< rtin[b]<<" "<< ltout[b]<<" "<<rtout[b]<<" \n";
		}
		else{
			b--,c--;

			if(c==b) cout<< a[b]<< '\n';
			else if(h[c]>=h[b]) cout<<"-1\n";
			else{
				ll sum=0, mmax;
				ll p,q;
				
				// cout<<p<<' '<<q<<'\n';
				
				if(b>c){
					p=ltin[b];
					q=ltin[c];
					// cout<<p<<' '<<q<<'\n';
					mmax=query(c, b - 1);
					// sum = sumOfRange(ltree, 0, 2*n-1, min(p,q), max(p,q), 0);
					sum = getsum_tree(LBITree, q) - getsum_tree(LBITree, p-1);
				}
				else{
					p=rtin[b];
					q=rtin[c];
					// cout<<p<<' '<<q<<'\n';
					mmax=query(b+1, c);
					// sum = sumOfRange(rtree, 0, 2*n-1, min(p,q), max(p,q), 0);
					sum = getsum_tree(RBITree, q) - getsum_tree(RBITree, p-1);
				}
				// cout<<"mmax "<<mmax<<'\n';
				if (mmax >= max(h[b], h[c]))
                {
                    sum = -1;
                }
                cout<<sum<<'\n';
			}
		}
		

	}
	
}

/*
5 4
3 1 4 1 5
1 2 4 8 16
2 5 2
1 3 5
2 3 4
2 1 4

22 13 -1
*/