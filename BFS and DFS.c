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



struct treeNode* push(struct treeNode* stack[20], struct treeNode * temp, int *stackLength){
	stack[*stackLength] = temp;
	*stackLength++;
	return stack[*stackLength];
}

void pop(struct treeNode* stack[20], int *stackLength){
	stack[*stackLength] = NULL;
	*stackLength--;
}

void BFS(struct treeNode * root, struct treeNode* stack[20], struct treeNode * temp, int *stackLength){
	if(root == NULL){
		return NULL;
	}
	stack[*stackLength] = push(stack, root, *stackLength);
	
}


int main(){
	struct treeNode * root = NULL;
	struct treeNode * stack[20];
	int stackLength = 0;	

	root = Insert(root, 5);
	root = Insert(root, 2);
	root = Insert(root, -4);
	root = Insert(root, 19);
	root = Insert(root, 21);
	root = Insert(root, 9);
	root = Insert(root, 25);
	root = Insert(root, 6);	

	printInorder(root);
}