# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node{
	int number;
	struct node* left;
	struct node* right;
}*root;



// int ListCreate(struct node* root, int array[100], int level ){
// 	if(root == NULL)
// 		return 0;	

// 	if(array[level] == -1){
// 		//printf("a\n");
// 		array[level] = root->number;
// 	}
// 	else{
// 		array[level] = array[level]*1000 + root->number;
// 	}

// 	ListCreate(root->left, array, level+1);
// 	ListCreate(root->right, array, level+1);
// }

void addNode(struct node ** root, int number){
	if(*root == NULL){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->number = number;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}
	else{
		if((*root)->number < number){
			addNode(&(*root)->right, number);
		}
		else{
			addNode(&(*root)->left, number);
		}
	}
}

void print(struct node* root){
	if(root!=NULL){
		print(root->left);
		printf("%d\n",root->number);
		print(root->right);
	}
}

struct node* FindMin(struct node *node)
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

struct node * findMax(struct node* root){
	struct node * temp;
	temp = root;
	if((temp->right == NULL)&&(temp->left == NULL)){
		return temp;
	}
	return findMax(temp->right);
}

void deleteNode(struct node** root, int number){
	//printf("%d\n", (*root)->number);
	if(*root == NULL){
		printf("Not found");
	}
	if((*root)->number < number){
		deleteNode(&((*root)->right), number);
	}
	else if((*root)->number > number){
		deleteNode(&((*root)->left), number);
	}
	else{
		if(((*root)->left)&&((*root)->right)){
			struct node* temp = FindMin((*root)->right);

			printf("Hello : %d", temp->number);
			(*root)->number = temp->number;



			deleteNode(&((*root)->right), temp->number);
		}
		else{
			printf("Hello\n");
			if((*root)->right == NULL){
				(*root) = (*root)->left;
			}
			else{
				(*root) = (*root)->right;	
			}
		}
	}
}


int main(){
	// int array[100];
	// memset(array, -1, 400);
	// for(int i=0; i<100; i++)
	// 	printf("%d\n",array[i]);
	root = NULL;
	addNode(&root, 10);
	addNode(&root, 3);
	addNode(&root, 9);
	addNode(&root, 2);
	addNode(&root, 14);
	addNode(&root, 23);
	addNode(&root, 17);
	addNode(&root, 32);

	print(root);

	// ListCreate(root, array, 0);
	// for(int i=0; i<10; i++)
	// 	printf("%d\n",array[i]);

}