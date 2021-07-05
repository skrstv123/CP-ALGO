// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar                              array
#define ll                              long long
#define range(i, start, end ,step)      for(ll i=start ;i<end; i += step)
#define rep(i,s,e)                      for(ll i=s;i<=e;++i)
#define reparr(arr)                     for(auto x: arr) cout<<x<<" ";
#define repr(i,e,s)                     for(ll i=e; i>=s; i--)
#define vit                             vector<ll>
#define mid(l,r)                        (l+(r-l)/2)
#define endl                            '\n'
#define vr                              vector
#define pr                              pair
#define pll                             pair<ll, ll> 
#define pb                              push_back
#define fp                              first
#define sp                              second
#define djpq                            priority_queue< pll , vr<pll>, greater<pll> >

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d){
			data= d;
			left = NULL;
			right = NULL;
		}
};

Node *insertBST(Node *root, int x){
	if(!root){
		return new Node(x);
	}
	if(x< root->data){
		root->left = insertBST(root->left, x);
	}
	else{
		root->right = insertBST(root->right, x);
	}
	return root;
}

Node *searchBST(Node *root, int x){
	if(!root){return NULL;}
	if(root->data == x) return root;
	if(root->data > x) return searchBST(root->left, x);
	return searchBST(root->right, x);
}


// for ino succ of root, first goto right, then leftmost (below func is incorrect) 
Node *inorderSucc(Node *root){
	Node *curr = root;
	while(curr && curr->left!=NULL){
		curr = curr->left;
	}
	return curr;
}

Node *deleteBST(Node *root, int x){
	if(x< root->data){
		root->left = deleteBST(root->left, x);

	}else if(x> root->data){
		root->right = deleteBST(root->right, x);
	}
	else{
		if(root->left == NULL){
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			Node *temp = root->left;
			free(root);
			return temp;
		} 
		// replace with ino succ, delete ino succ (that is in right sub tree)
		Node *temp = inorderSucc(root->right);
		root->data = temp->data;
		root->right = deleteBST(root->right, temp->data);

	}
	return root;

}


bool isBST(Node *root, Node *mini, Node *maxi){
	if(!root) return true;

	if(mini!=NULL && root->data<= mini->data) return false;
	if(maxi!=NULL && root->data>= maxi->data) return false;

	bool leftVal = isBST(root->left, mini, root);
	bool rightVal = isBST(root->right, root, maxi);

	return leftVal && rightVal;
}

Node *sortedArrayToBST(int arr[], int start, int end){
	if(start>end) return NULL;
	int m = (start + end)/2;
	Node *root = new Node(arr[m]);
	root->left = sortedArrayToBST(arr, start, m-1);
	root->right = sortedArrayToBST(arr, m+1, end);
	return root;
}

bool isIdentical(Node *A, Node *B){
	if(A==B && A==NULL)return true;
	else if(A==NULL || B==NULL) return false;
	else{
		bool c1 = A->data == B->data;
		bool c2 = isIdentical(A->left, B->left);
		bool c3 = isIdentical(A->right, B->right);
		return (c1 && c2) && c3;
	}
}

void solve() {
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
