# include <stdio.h>
# include <stdlib.h>

struct treeNode{

	int data;
	struct treeNode * left;
	struct treeNode * right; 

};

struct treeNode * Insert(struct treeNode *node, int data){

	if(node==NULL)
    {
                struct treeNode *temp;
                temp = (struct treeNode *)malloc(sizeof(struct treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
		return node;

}


void printInorder(struct treeNode* root){
	if(root == NULL){
		return;
	}
	printInorder(root->left);
	printf(" %d ", root->data);
	printInorder(root->right);
}


void printPreorder(struct treeNode* root){
	if(root == NULL){
		return;
	}
	printf(" %d ", root->data);
	printPreorder(root->left);
	printPreorder(root->right);
}

void printPostorder(struct treeNode* root){
	if(root == NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	printf(" %d ", root->data);
}

// int findMax(struct treeNode * root){
	
// 	int maxTree = 0;
// 	maxTree = root->data;
// 	while(root->right != NULL){
// 		root=root->right;
// 		if(root->data>maxTree){
// 			maxTree = root->data;
// 		}
// 	}
// 	return maxTree;
// }


struct treeNode* FindMin(struct treeNode *node)
{
    if(node==NULL)
    {
            return NULL;
    }
    if(node->left)
	    return FindMin(node->left);
	else 
		return node;
}

struct treeNode* FindMax(struct treeNode* node){
	if(node == NULL)
		return NULL;

	if(node->right)
		return FindMax(node->right);
	else
		return node;
}


struct treeNode* deleteNode(struct treeNode * root, int number){
	if(root==NULL){
		printf("Element not found\n");
	}
	if(number > root->data){
		root->right = deleteNode(root->right, number);
	}
	else if(number < root->data){
		root->left = deleteNode(root->left, number);
	}
	else{
		if((root->left != NULL)&&(root->right != NULL)){
			struct treeNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		
		else{
			struct treeNode* temp = root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right == NULL)
				root = root->left;
		}
	}
	return root;
}


int searchNode(struct treeNode* root, int number){
	
	if(root==NULL){
		return 0;
	}
	if(number > root->data){
		return searchNode(root->right, number);
	}
	else if(number < root->data){
		return searchNode(root->left, number);
	}
	else{
		return 1;
	}
}	

int main(){

	struct treeNode * root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 2);
	root = Insert(root, -4);
	root = Insert(root, 19);
	root = Insert(root, 21);
	root = Insert(root, 9);
	root = Insert(root, 25);
	root = Insert(root, 6);	

	printInorder(root);

	deleteNode(root, 2);
	printf("\n\n\n\n");
	printInorder(root);
}