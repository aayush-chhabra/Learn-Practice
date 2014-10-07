# include <iostream>

using namespace std;

class List{
	struct Node
	{	
		int number;
		struct Node * next;
	}*root;
	public:	
		List(){
			root = NULL;
		}
		void addNode(int element){
			if(root == NULL){
				struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
				temp->number = element;
				temp->next = NULL;
				root = temp;
				return;
			}
			struct node * temp = root;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			struct Node * temp1 = (struct Node *)malloc(sizeof(struct Node));
			temp1->number = element;
			temp1->next = NULL;
			temp = temp1;
		}
};

int main(){

}