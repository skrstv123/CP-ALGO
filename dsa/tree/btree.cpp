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

int search(int cur, int ino[], int start, int end){
	rep(i, start, end){
		if(ino[i] == cur) return i;
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////////////
Node *buildfromInPr(int pre[], int ino[], int start, int end){
	static int idx = 0;
	if(start>end) return NULL;

	int curr = pre[idx];
	idx++;

	Node *head = new Node(curr);

	if(start==end) return head;

	int curr_pos_in_ino = search(curr, ino, start, end);
	head -> left = buildfromInPr(pre, ino, start, curr_pos_in_ino-1);
	head -> right = buildfromInPr(pre, ino, curr_pos_in_ino+1, end);

	return head;
}

Node *buildfromInPo(int post[], int ino[], int start, int end){
	static int idx = end;
	if(start>end) return NULL;

	int curr = post[idx];
	idx--;

	Node *head = new Node(curr);

	if(start==end) return head;

	int curr_pos_in_ino = search(curr, ino, start, end);
	head -> right = buildfromInPo(post, ino, curr_pos_in_ino+1, end);
	head -> left = buildfromInPo(post, ino, start, curr_pos_in_ino-1);

	return head;
}
//////////////////////////////////////////////////////////////////////////////////

void printIno(Node *root){

	if(root== NULL) return;

	printIno(root -> left);
	cout<< root-> data<<" ";
	printIno(root -> right);
}

void levelOrder(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *curr=q.front();
		q.pop();
		if(curr!=NULL){
			cout<<curr->data<<" ";
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		} else if(!q.empty()) q.push(NULL);
	}
}

void levelKSum(Node *root, int k){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	int c=0, s=0;
	while(!q.empty()){
		Node *curr=q.front();
		q.pop();
		if(curr!=NULL){
			if(c==k) s+=curr->data;
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		} else if(!q.empty()){ 
			q.push(NULL);
		}
		if(curr==NULL) c++;
	}
	cout<<s;
	
}

int numNodes(Node *root){
	if(root==NULL) return 0;
	return numNodes(root->left) + numNodes(root->right) + 1;
}

int sumNodes(Node *root){
	if(root==NULL) return 0;
	return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int heightBT(Node *root){
	if(root==NULL) return 0;
	int lh = heightBT(root->left);
	int rh = heightBT(root->right);
	return max(lh,rh) + 1;
}

//////////////////////////////////////////////////////////////////////////////////
int diameterNN(Node *root){
		if(root==NULL) return 0;
		int lh = heightBT(root->left);
		int rh = heightBT(root->right);
		int diameterFromRoot = lh + rh + 1;
		int diameterFromRootLeft = diameterNN(root->left);
		int diameterFromRootRight = diameterNN(root->right);
		return max(diameterFromRoot, max(diameterFromRootLeft, diameterFromRootRight));
}

int diameter = - MAX_N;
int diameterN(Node *root){
	if(root==NULL){
		return 0;
	}

	int ld = diameterN(root->left);
	int rd = diameterN(root->right);

	diameter = max(diameter, ld+rd+1);

	return max(ld, rd) + 1;
}
//////////////////////////////////////////////////////////////////////////////////

bool balanced = true;
int checkBalanced(Node *root){
	if(root==NULL) return 0;

	int lh = checkBalanced(root->left);
	int rh = checkBalanced(root->right);

	balanced &= abs(lh-rh)<=1;

	return max(lh, rh) + 1;
}

int sumReplace(Node *root){
	if(root==NULL) return 0;
	root->data = root->data + sumReplace(root->left) + sumReplace(root->right);
	return root->data;
}

void rightView(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int levelSize = q.size();
		rep(i, 1, levelSize){
			Node *temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			if(i==levelSize) cout<<temp->data<<" ";
		}
	}
}

void lefttView(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int levelSize = q.size();
		rep(i, 1, levelSize){
			Node *temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			if(i==1) cout<<temp->data<<" ";
		}
	}
}

void topView(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		int levelSize = q.size();
		rep(i, 1, levelSize){
			Node *temp = q.front();
			q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			if(i==levelSize || i==1) cout<<temp->data<<" ";
		}
	}
}

void nodesAtDistKinSubTreeOfGivenNode(Node *root, int k){
	if(root==NULL || k<0) return;
	else if(k==0) cout<<root->data<<" ";
	else{
		nodesAtDistKinSubTreeOfGivenNode(root->left, k-1);
		nodesAtDistKinSubTreeOfGivenNode(root->right, k-1);
	}
}

Node *LCA(Node *root, int a, int b){
	if(!root) return NULL;

	if(root->data == a || root->data == b) return root;

	Node *l = LCA(root->left, a,b);
	Node *r = LCA(root->right, a, b);

	if(l && r) return root;
	if(l) return l;
	return r;
}

//////////////////////////////////////////////////////////////////////////////////
void flatten(Node *root, Node* &head, Node* &prev, bool &first_flag){
	if(root==NULL) return;
	flatten(root->left, head, prev, first_flag);
	if(first_flag){
		first_flag = false;
		head = root;
		prev = root;
	}else{
		prev->right = root;
		prev->right->left = prev;
		prev = prev->right;
	}
	flatten(root->right, head, prev, first_flag);
}

Node* btToLL(Node *root){
	Node *head = NULL;
	Node *prev = NULL;
	bool first_flag = true;
	flatten(root, head, prev, first_flag);
	return head;
}
void printBTLL(Node *root){
	while(root){
		cout<<root->data<<" ";
		root=root->right;
	}
}
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
int dist(Node *root, int k, int d){
	if(root==NULL) return -1;
	if(root->data==k) return d;
	int l = dist(root->left, k, d+1);
	int r = dist(root->right, k, d+1);
	if(l!=-1) return l;
	return r;
}

int minDistAB(Node *root, int a, int b){
	Node *lca = LCA(root, a, b);
	cout<<"lca of "<<a<<" "<<b<<": "<<lca->data<<endl;
	return dist(lca, a, 0) + dist(lca, b, 0) + 1;
}
//////////////////////////////////////////////////////////////////////////////////

void solve() {
	// int pre[]=  {1,2,4,3,5};
	// int ino[]=  {4,2,1,5,3};
	// int post[]=  {4,2,5,3,1};
	// Node *root = buildfromInPr(pre, ino, 0, 4);
	// Node *root = buildfromInPo(post, ino, 0, 4);
	// printIno(root);
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	// levelOrder(root);
	// levelKSum(root,2);
	// cout<<numNodes(root)<<" "<<sumNodes(root)<<endl;
	// cout<<heightBT(root)<<endl;
	// cout<<diameterNN(root)<<endl;
	// int height=0;
	// diameterN(root);
	// cout<<diameter<<endl;
	// checkBalanced(root);
	// cout<<balanced<<endl;
	// levelOrder(root);
	// sumReplace(root);
	// cout<<endl;
	// levelOrder(root);
	// rightView(root);
	// lefttView(root);
	// topView(root);
	// nodesAtDistKinSubTreeOfGivenNode(root, 2);
	// cout<<minDistAB(root, 2, 7)<<endl;
	// cout<<minDistAB(root, 4, 7)<<endl;
	// cout<<minDistAB(root, 4, 5)<<endl;
	// printIno(root);
	// cout<<endl;
	// printBTLL(btToLL(root));
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
