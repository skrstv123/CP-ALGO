#include <iostream>
#include <cstdio>
#include <cmath>

#define PSEUDO_INFINITY 1000000

using namespace std;

int rangeMinTree(int tree[], int arr[], int l, int r, int stri){
	if(l==r){ tree[stri] = arr[l]; return arr[l]; }
	int mid = (l+r)/2;
	tree[stri] = min(rangeMinTree(tree ,arr ,l, mid, 2*stri +1),
			       rangeMinTree(tree, arr, mid+1, r, 2*stri +2));
			       // replacing min by max will give rangeMaxTree
}

int rangeMin(int tree[],int sl,int sr,int ll, int rr, int si){
	if(ll<=sl && rr>=sr) return tree[si]; // complete segment overlap; segment falls inside the required range 
	if(sr<ll || sl>rr) return PSEUDO_INFINITY; // no overlap; segemnt completely falls out of required range
	// partial overlap case
	// using SEGMENT's left n' right to find mid
	int mid = (sl+sr)/2; 
	return min(rangeMin(tree,sl,mid,ll, rr, 2*si+1)
		  ,rangeMin(tree,mid+1,sr,ll, rr, 2*si+2));
		   // replacin min by max will make it work for rangeMaxTree
}

main(){
	int arSize=7, trSize;
	int arr[arSize] = {5,8,7,2,1,4,6};
	
	trSize = (int)pow(2,ceil(log2(arSize))+1)-1; // size of heap formula
	
	int tree[trSize] = {0};
	rangeMinTree(tree,arr,0,arSize-1,0);
	
	for(int i=0;i<trSize&&printf("%d ",tree[i]);i++);
	cout<<'\n'<<rangeMin(tree, 0, arSize-1, 0, 2, 0); // min of [0:2]
}
