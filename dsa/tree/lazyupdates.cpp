// lazy propagation for range updates
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// segment tree for range sum query and range update query 
// same can be modified easily for product of range (by multiplying instead of adding)
int mktree(int tree[],int si, int arr[],int l, int r){
	if(l==r){ tree[si]=arr[l]; return arr[l]; }
	int mid = (l+r)/2;
	tree[si] = mktree(tree,2*si + 1,arr, l, mid)  
	         + mktree(tree,2*si + 2,arr, mid+1, r); 
			 // si'th node's value is the sum of its left and right child nodes
			 // left child : 2*i+1; right child : 2*i + 2
	return tree[si];
}

// --------------------Lazy updates-------------------
int notLeaf(int l, int r){ return l!=r; }

void lru(int tree[], int ltree[], int nval, int treeptr, int sl, int sr, int ul, int ur){ // Lazy Range Updater
	// if current node has pending updates
	if(ltree[treeptr]!=0){
		// update the node
		tree[treeptr] += (sr-sl+1)*ltree[treeptr];
		if(notLeaf(sl,sr)){
			// mark childrens as unupdated in lazy Tree
			ltree[2*treeptr + 1] += ltree[treeptr];
			ltree[2*treeptr + 2] += ltree[treeptr];
		}
		// mark current node as updated
		ltree[treeptr] = 0;
	}
	
	// no overlap
	if(sl>sr || sl>ur || sr<ul) return;
	
	// complete overlap
	if(sl>=ul && sr<=ur){ 
		// update current node
		tree[treeptr] += (sr-sl+1)*nval;
		// if current node isn't leaf: mark children for lazy updates
		if(notLeaf(sl,sr)){
			ltree[2*treeptr + 1] += nval;
			ltree[2*treeptr + 2] += nval;
		}
		return ;
	}
	
	// partial overlap: check and update childrens
	int mid = (sl+sr)/2;
	lru(tree, ltree, nval, 2*treeptr + 1, sl, mid, ul, ur);
	lru(tree, ltree, nval, 2*treeptr + 2, mid+1, sr, ul, ur);
	
	// update parent having partial overlaps
	tree[treeptr]  = tree[2*treeptr + 1]  + tree[2*treeptr + 2];
} 
// --------------------Lazy updates-------------------

//---------------------range sum using lazy updates---------------
int getSum(int tree[], int lazy[], int trIn, int sl, int sr, int ul, int ur){
	// if node is unupdated
	if(lazy[trIn]!=0){
		tree[trIn] += (sr-sl+1)*lazy[trIn];
		if(sl!=sr){ 
			//if non leaf
			// mark childrens for update
			lazy[2*trIn + 1] += lazy[trIn];
			lazy[2*trIn + 2] += lazy[trIn];
		}
		// mark current as updated
		lazy[trIn] = 0;
	}
	
	// no overlap
	if(sl>sr || sl>ur || sr<ul) return 0;
	// complete overlap 
	if(sl>=ul && sr<=ur) return tree[trIn];
	// partial overlap : return values from childrens
	int mid = (sl+sr)/2;
	return getSum(tree, lazy, 2*trIn+1, sl, mid, ul, ur)
		   + getSum(tree, lazy, 2*trIn+2, mid+1, sr, ul, ur);
}
//---------------------range sum using lazy updates---------------

main(){
	int arrSize = 6;
	int arr[arrSize] = {1,5,7,3,6,2};
	int sizeOfTree = (int)pow(2,ceil(log2(arrSize))+1)-1;
	int tree[sizeOfTree] = {0};
	int ltree[sizeOfTree] = {0};
	mktree(tree,0,arr,0, arrSize-1);
	cout<<sizeOfTree<<'\n';
	for(int a=0;a<sizeOfTree&&printf("%d ",tree[a]);a++);
	lru(tree, ltree, 1, 0, 0, arrSize-1, 0,2);
	cout<<'\n'<<getSum(tree, ltree, 0, 0, arrSize-1, 3, 5)<<endl;
}
