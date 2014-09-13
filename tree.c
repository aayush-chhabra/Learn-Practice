# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node{
	int number;
	struct node* left;
	struct node* right;
}*root;


struct treeNode{
	int number;
	struct treeNode* next;
}*front, *rear;

int isEmpty(){
	if(front == NULL){
		return 1;
	}
	return 0;
}

void push(int num){
	struct treeNode* temp = (struct treeNode*)malloc(sizeof(struct treeNode));
	temp->number = num;
	temp->next = NULL;


	if((front == NULL)&&(rear == NULL)){
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = rear->next;
}

struct treeNode* pop(){
	struct treeNode * temp;
	if(front==NULL){
		printf("Nuthing to pop..\n");
		return NULL;
	}

	if(front == rear)
	{
		temp = front;
		front = rear = NULL;
		return temp;
	}

	temp = front;
	front = front -> next;
	return temp;

}


void print(){
	struct treeNode* temp = front;
	while(temp != rear){
		printf("%d\n", temp->number);
		temp = temp->next;
	}
	printf("%d\n", temp->number);
}


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

void print1(struct node* root){
	if(root!=NULL){
		print1(root->left);
		printf("%d\n",root->number);
		print1(root->right);
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


struct node* searchNode(struct node* root, int number){
	
	if(root == NULL)
		return NULL;

	if(root->number == number){
		return root;
	}

	if(root->number < number){
		return searchNode(root->right, number);
	}

	if(root->number > number){
		return searchNode(root->left, number);
	}
}

int searchInVisited(int un[10], int number){
	for(int i=0; un[i]!=-1; i++){
		if(un[i] == number){
			return 1;
		}
	}
	return 0;
}

void addToUn(struct node* root, int un[10], int level){
	
	if(root == NULL)
		return;
	
	while(un[level] != -1){
		level ++;
	}

	un[level] = root->number;

	addToUn(root->left, un, level);
	addToUn(root->right, un, level);
}


int bfs(struct node* root, struct treeNode* front, struct treeNode* rear,int visited[10],int un[10]){
	int i;
	if(!isEmpty()){
		//printf("Iteration: ");print();
		struct treeNode* temp = pop();
		
		if(!searchInVisited(visited, temp->number)){
			for(i=0; visited[i]!=-1; i++);
			visited[i] = temp->number;	
		}

		struct node * temp1 = searchNode(root, temp->number);

		if(temp1->left)
			push((temp1->left)->number);
		if(temp1->right)
		push((temp1->right)->number);

		bfs(root, front, rear, visited, un);
		bfs(root, front, rear, visited, un);

	}
	else
		return 0;
}


int heightMax(struct node* root){
	
	if(root==NULL)
		return 0;

	int lheight = 0, rheight = 0;
	lheight = heightMax(root->left);
	rheight = heightMax(root->right);


	if(lheight>rheight)
		return(lheight+1);

	else
		return(rheight+1);



}

// void heightMax(struct node * root, int *max, int count){
	
// 	if(root == NULL)
// 		return;

// 	count++;

// 	if((root->left == NULL) && (root->right == NULL)){
// 		if(*max < count)
// 			*max = count;
// 		return;
// 	}

// 	//printf("%d : %d\n", root->number, count);

// 	heightMax(root->left, max, count);
// 	heightMax(root->right, max, count);
// }


// void heightMin(struct node * root, int *max, int count){
	


// 	if(root == NULL)
// 		return;


// 	count ++;
	
// 	if((root->left == NULL) && (root->right == NULL)){
// 		if(*max > count)
// 			*max = count;
// 		return;
// 	}


// 	heightMin(root->left, max, count);
// 	heightMin(root->right, max, count);

// }





int main(){
	// // int array[100];
	// // memset(array, -1, 400);
	// // for(int i=0; i<100; i++)
	// // 	printf("%d\n",array[i]);
	

	// front = rear = NULL;
	// int visited[10], un[10], length = 0;
	// memset(visited, -1, 40);
	// memset(un, -1, 40);
	root = NULL;
	addNode(&root, 10);
	addNode(&root, 3);
	addNode(&root, 9);
	addNode(&root, 2);
	addNode(&root, 14);
	addNode(&root, 23);
	addNode(&root, 17);
	addNode(&root, 32);

	//print1(root);


	// int max = 0, min=100;
	int z = heightMax(root);
	printf("%d\n", z);
	// heightMin(root, &min, -1);

	// printf("%d\n",max - min);


	//addToUn(root, un, 0);

	// // for(int i =0; un[i]!=-1; i++){
	// // 	printf("here I am: %d\n", un[i]);
	// // }

	// push(root->number);
	// bfs(root, front, rear, visited, un);

	// for(int i=0; visited[i]!=-1; i++){
	// 	printf("%d\n", visited[i]);
	// }
	// // ListCreate(root, array, 0);
	// // for(int i=0; i<10; i++)
	// // 	printf("%d\n",array[i]);

}