#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

// segment tree for range sum query and point update query 
// can be modified easily for product of range 
int mktree(int tree[],int si, int arr[],int l, int r){
	if(l==r){ tree[si]=arr[l]; return arr[l]; }
	int mid = (l+r)/2;
	tree[si] = mktree(tree,2*si + 1,arr, l, mid)  
	         + mktree(tree,2*si + 2,arr, mid+1, r); 
	return tree[si];
}

int sumOfRange(int tree[],int sl,int sr,int ll, int rr, int si){
	if(ll<=sl && rr>=sr) return tree[si]; // complete segment overlap
	if(sr<ll || sl>rr) return 0; // no overlap
	int mid = (sl+sr)/2;
	return sumOfRange(tree,sl,mid,ll, rr, 2*si+1)
		  + sumOfRange(tree,mid+1,sr,ll, rr, 2*si+2);
}

void treeUpdater(int tree[],int sl,int sr,int i,int diff,int si){
	if(i<sl||i>sr) return;
	tree[si]+=diff;
	if(sl!=sr){
		int mid = (sl+sr)/2;
		treeUpdater(tree,sl,mid,i,diff,2*si + 1);
		treeUpdater(tree,mid+1,sr,i,diff,2*si + 2);
	}
}

void pointUpdate(int arr[],int tree[],int size, int i, int new_val){
	int diff = new_val - arr[i];
	arr[i] = new_val;
	treeUpdater(tree,0,size-1,i,diff,0);
}



int main(){
	int arrSize = 6;
	int arr[arrSize] = {1,5,7,3,6,2};
	int sizeOfTree = (int)pow(2,ceil(log2(arrSize))+1)-1;
	int tree[sizeOfTree] = {0};
	mktree(tree,0,arr,0, arrSize-1);
	cout<<sizeOfTree<<'\n';
	for(int a=0;a<sizeOfTree&&printf("%d ",tree[a]);a++);
	pointUpdate(arr,tree,arrSize,2,10); cout<<'\n';
	for(int a=0;a<sizeOfTree&&printf("%d ",tree[a]);a++);
//	cout<<'\n'<<sumOfRange(tree, 0, arrSize-1, 1, 2, 0)<<endl;
	return 0;
}
