# include <stdio.h>

int main(){
	int matrix[4][3] ={{1,2,3},{4,0,6},{7,8,9},{10,11,12}};
	int copyMatrix[4][3]; 

	for(int i=0; i<=3; i++){
		for(int j=0; j<=2; j++){	
			copyMatrix[i][j] = '.';
		}
	}


	for(int i=0; i<=3; i++){
		for(int j=0; j<=2; j++){
			//printf("%d ", matrix[i][j]);

			if(matrix[i][j] == 0){
				for(int z=0; z<=3; z++) copyMatrix[z][j] = 0;
				for(int z=0; z<=2; z++) copyMatrix[i][z] = 0;
			}
		}
	}

	for(int i=0; i<=3; i++){
		for(int j=0; j<=2; j++){
			if(copyMatrix[i][j]!=0){
				copyMatrix[i][j] = matrix[i][j];
			}
		}
	}

	for(int i=0; i<=3; i++){
		for(int j=0; j<=2; j++){
			printf("   %d   ", copyMatrix[i][j]);
		}
		printf("\n");
	}



}