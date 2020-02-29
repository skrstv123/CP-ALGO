// range updates
#include <cstdio>
#include <iostream>
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
			 // left child : 2*i+1; right child ; 2*i + 2
	return tree[si];
}

int sumOfRange(int tree[],int sl,int sr,int ll, int rr, int si){
	// segment to be used must be of equal size or smaller than than required range size and must fall within or fit in the given range
	if(ll<=sl && rr>=sr) return tree[si]; // complete segment overlap; segment falls inside the required range 
	if(sr<ll || sl>rr) return 0; // no overlap; segemnt falls out of required range
	// partial overlap case
	int mid = (sl+sr)/2;
	return sumOfRange(tree,sl,mid,ll, rr, 2*si+1)
		  + sumOfRange(tree,mid+1,sr,ll, rr, 2*si+2);
		  // si is the actual segtree node locater;
		  // sl & sr are being used to keep track of actual array segments
}

void rangeUpdate(int tree[], int treeptr, int nval, int sl, int sr, int ul, int ur){
	// updates only the tree
	if(sl>sr || sl>ur || sr<ul) return ; // no overlap
	if(sl==sr){ tree[treeptr] += nval; return; } // if it a leaf, update it
	
	// non  leaf : recursively update childrens 
	int mid = (sl+sr)/2;
	rangeUpdate(tree,2*treeptr + 1, nval, sl, mid, ul, ur);
	rangeUpdate(tree,2*treeptr + 2, nval, mid+1, sr, ul, ur);
	// update non leaf nodes 
	tree[treeptr] = tree[2*treeptr +1] + tree[2*treeptr +2];
}

main(){
	int arrSize = 6;
	int arr[arrSize] = {1,5,7,3,6,2};
	int sizeOfTree = (int)pow(2,ceil(log2(arrSize))+1)-1;
	int tree[sizeOfTree] = {0};
	mktree(tree,0,arr,0, arrSize-1);
	cout<<sizeOfTree<<'\n';
	for(int a=0;a<sizeOfTree&&printf("%d ",tree[a]);a++);
	cout<<endl;
	rangeUpdate(tree,0,2,0,arrSize-1,1,3);
//	for(int a=0;a<sizeOfTree&&printf("%d ",tree[a]);a++);
	cout<<'\n'<<sumOfRange(tree, 0, arrSize-1, 0, 1, 0)<<endl;
	return 0;
}
