#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int mk_xortree(int tree[],int si, int arr[], int l,int r){
	if(l==r){ tree[si]= arr[l]; return arr[l]; }
	int mid = (l+r)/2;
	tree[si] = mk_xortree(tree,2*si+1, arr, l,mid)
		       ^ mk_xortree(tree, 2*si+2, arr, mid+1,r);
}

int rangeXor(int tree[], int si, int sl, int sr, int rl, int rr){
	if(sl>rr || sr<rl) return 0; // no overlap // 0 is identity element for ^ operation
	if(sl>=rl && sr<=rr) return tree[si];  // complete segment overlap
	// partial overlap
	int mid = (sl+sr)/2;
	return rangeXor(tree, 2*si+1, sl, mid, rl, rr)
		   ^ rangeXor(tree, 2*si+2, mid+1, sr, rl, rr);
}

main(){
	int tree_size, arr_size=2;
	int arr[arr_size] = {1,2} ;
	tree_size = (int)pow(2,ceil(log2(arr_size))+1) - 1;
	int tree[tree_size] = {0};
	
	mk_xortree(tree,0,arr,0,arr_size-1);
	
	for(int i=0;i<tree_size&&printf("%d ",tree[i]);i++);
	cout<<'\n'<<rangeXor(tree,0, 0,arr_size-1,0,1);
}
