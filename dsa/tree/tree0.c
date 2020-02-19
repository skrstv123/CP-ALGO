#include <stdlib.h> //bst 
#include <stdio.h>
struct node{
	struct node *ltree;
	int data;
	struct node *rtree;
};

struct node *insert_bst(struct node *root, int data){
	if(root==NULL){
		root = (struct node *)malloc(sizeof(struct node));
		root -> data = data;
		root -> rtree = NULL;
		root -> ltree = NULL; }
	else if(data<root->data) root -> ltree = insert_bst(root->ltree,data);
	else if(data>root->data) root -> rtree = insert_bst(root->rtree,data);
	else printf("duplicate Key!\n");
	return root; // after executing if block
}

void inorder(struct node *root){
	if(root==NULL) return ;
	inorder(root->ltree);
	printf("%d ",root->data);
	inorder(root->rtree);
}

int min_bst(struct node *root){
	if(root!=NULL){ int min;
		while(root!=NULL){
			min = root->data;
			root = root->ltree;} return min;}
	printf("\nempty tree!"); return;
}

int max_bst(struct node *root){
	if(root!=NULL){
		int max;
		while(root!=NULL){
			max = root->data;
			root = root->rtree;
		} return max; }
	printf("empty tree\n"); return;
}

int search_bst(struct node *root, int data){
	while(root!=NULL){
		if(data>root->data) root = root->rtree;
		else if(data<root->data) root = root->ltree;
		else if(data == root->data){ printf("\ndata found!!\n"); return 200; } }
	printf("\ndata not found!\n"); return 404;
}

struct node *del_bst(struct node *root,int key){
	struct node *ptr=root,*prev = NULL;
	while(ptr!=NULL){
		if(key == ptr->data) break;
		prev = ptr;
		if(key<ptr->data) ptr = ptr->ltree;
		else ptr = ptr->rtree; 
	}
		
	if(ptr==NULL){ printf("key not found!"); return root; }
	
	//case 3 (2 child)
	// find inorder successor and delete it after exchanging data
	struct node *inosucc,*child,*prev_to_inosucc;
	if(ptr->ltree!=NULL && ptr->rtree!=NULL){
		prev_to_inosucc = ptr;
		inosucc = ptr->rtree;
		while(inosucc->ltree!=NULL){
			prev_to_inosucc = inosucc;
			inosucc = inosucc->ltree; }
		ptr->data = inosucc->data;
		// case 3 being reduced to case 1 (or 2)
		ptr = inosucc;
		prev = prev_to_inosucc; 
	}
	// case 1n'2
	if(ptr->ltree!=NULL) child = ptr->ltree; //1 child : store it in child
	else child = ptr->rtree; //not NULL if there's a rtree(not null) ; if not then child is set to NULL! which validates the next line
	if(prev==NULL) root = child; //root is being deleted 	
	else if(ptr==prev->ltree) prev->ltree = child; 
//	 	prev
//		/  \
// 	   /
//   ptr          the child is being moved up to ptr
//    \
//    child     (child is either ltree or rtree of ptr)
	else prev->rtree = child;
	free(ptr);
	return root;
}

main(){
	struct node *root = NULL;
	int c=5,el;
	scanf("%d",&c);
	while(c--){
		int data;
		scanf("%d",&data);
		root = insert_bst(root, data);
	}
	printf("numbers should be sorted\n");
	inorder(root);
//	printf("\nmin in tree is %d" , min_bst(root));
//	printf("\nmax in tree is %d\n" , max_bst(root));
//	scanf("%d",&el);
//	search_bst(root,el);
	printf("\nenter number to delete\n");
	scanf("%d",&el);
	root = del_bst(root,el);
	inorder(root);
}
