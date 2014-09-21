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

struct node* returnParent(struct node * root, struct node* child){
	struct node * fromleft, * fromRight;

	//printf("%d %d\n", root->number, child->number);
	if(root == NULL)
		return NULL;


	if(root->right){
		if((root->right)->number == child->number){
			//printf("Hellooo\n");
			return root;
		}
	}
	
	if(root->left){
		if((root->left)->number == child->number){
			return root;
		}
	}

	if(root->left)
		fromleft = returnParent(root->left, child);
	if(root->right)
		fromRight = returnParent(root->right, child);
	




	


	if(fromleft == NULL)
		return fromRight;
	else if(fromRight == NULL)
		return fromleft;
	else if((fromleft!=NULL)&&(fromRight!=NULL))
		return fromRight;
	else
		return NULL;

}

// struct node * succ(struct node* root, int number){
// 	struct node* child = searchNode(root, number);
// 	struct node* parent = returnParent(root, child);

// 	if((child->left == NULL) && (child->right == NULL)){
// 		if((parent->left)->number == child->number){
// 			return parent;
// 		}
// 		else if((parent->right)->number == child->number){
// 			struct node * parentParent = returnParent(root, parent);
// 			return parentParent;
// 		}
// 	}
// 	return child->right;
// 	//if(temp->right == NULL)
// }


int checkBst(struct node* root){
	
	// if(root == NULL)
	// 	return 1;

	// if(((root->left)->number < root->number)&&((root->right)->number > root->number)){
	// 	return 1;
	// }

	// else{
	// 	return 0;
	// }

	// int l = checkBst(root->left);
	// int r = checkBst(root->right);

	// if((l)&&(r)){
	// 	return 1;
	// }
	// else{
	// 	return 0;
	// }
	int l, r;
	if(root == NULL){
		return 1;
	}
	if((root->left)&&(root->right)){
		struct node* left = findMax(root->left);
		struct node* right = FindMin(root->right);

		//printf("%d %d\n", left->number, right->number );

		if((left->number < root->number)&&(right->number > root->number)){
			l = checkBst(root->left);
			r = checkBst(root->right);
			//printf("%d %d\n", l , r );
			if((l)&&(r)){
				return 1;
			}
			return 0;

		}
		else
		{
			return 0;
		}


			
	}
}


// void LCA(struct node* root, struct node* child1, struct node* parentOfChild2, int* num){
	
// 	//printf("32, 23 %d\n", child1->number);

// 	struct node* parent1 = returnParent(root, child1);	
// 	printf("%d\n", parent1->number);


// 	if(parent1 -> number == root->number){
// 		*num = root-> number;
// 		return;
// 	}

// 	if(parent1 -> number == parentOfChild2->number){
// 		*num = parent1->number;
// 		return;
// 	}
// 	//printf("%d\n", parent1->number);
// 	LCA(root, parent1, parentOfChild2, num);
// 	struct node* parent2 = returnParent(root, parentOfChild2);
// 	LCA(root, parent1, parent2, num);
// }


struct node* LCA(struct node* root, struct node* child1, struct node* child2){

	if( root == NULL )
		return NULL;

	if((root-> number == child1->number)||(root-> number == child2->number)){
		return root;
	}

	struct node * L = LCA(root->left, child1, child2);
	struct node * R = LCA(root->right, child1, child2);



	// if(L&&R) return root;
	// else L ? L : R;



}


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
	int a;
	addNode(&root, 10);
	addNode(&root, 3);
	addNode(&root, 9);
	addNode(&root, 2);
	addNode(&root, 14);
	addNode(&root, 23);
	addNode(&root, 17);
	addNode(&root, 32);
	// addNode(&root, 1);
	// addNode(&root, 12);
	// addNode(&root, 13);
	// addNode(&root, 11);

	//print1(root);

	struct node * temp1 = searchNode(root, 32);
	struct node * temp2 = searchNode(root, 17);
	//struct node * temp3 = searchNode(root, 32);
	
	struct node * t = LCA(root, temp1, temp2);
	//struct node* parent1 = returnParent(root, temp3);
	//printf("%d", parent1->number);

	printf("I am here: %d\n", t->number);















	// struct node* temp = (struct node*) malloc(sizeof(struct node));
	// temp -> number = 10;
	// temp -> left = NULL;
	// temp -> right = NULL;

	// struct node* temp1 = (struct node*) malloc(sizeof(struct node));
	// temp1 -> number = 3;
	// temp1 -> left = NULL;
	// temp1 -> right = NULL;

	// struct node* temp3 = (struct node*) malloc(sizeof(struct node));
	// temp3 -> number = 19;
	// temp3 -> left = NULL;
	// temp3 -> right = NULL;

	// struct node* temp4 = (struct node*) malloc(sizeof(struct node));
	// temp4 -> number = 2;
	// temp4 -> left = NULL;
	// temp4 -> right = NULL;

	// struct node* temp5 = (struct node*) malloc(sizeof(struct node));
	// temp5 -> number = 12;
	// temp5 -> left = NULL;
	// temp5 -> right = NULL;

	// root = temp;
	// root->left = temp1;
	// root->right = temp3;
	// (root->left)->left = temp4;
	// (root->left)->right = temp5;


	// int z = checkBst(root);
	// printf("I am here: %d\n", z);



	


	






	//struct node * ptr = succ(root, 9);

	//printf("\nThis is the fucking final Answer: %d\n", ptr -> number);


	// int max = 0, min=100;
	// int z = heightMax(root);
	// printf("%d\n", z);
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