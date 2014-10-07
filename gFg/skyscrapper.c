# include <stdio.h>

int main(){
	int heights[] = {9,8,7,8,9,5,6};
	int length = sizeof(heights)/sizeof(int);
	int waterCount = 0;

	for(int i=0; i<length; i++){
		if((i!=0)&&(i!=length-1)){
			if((heights[i]<heights[i-1])&&(heights[i]<heights[i+1])){
				printf("%d %d\n", waterCount, heights[i]);
				waterCount += (heights[i-1]<heights[i+1]?(heights[i+1] - heights[i]):(heights[i-1] - heights[i]));

			}	
		}
		
	}
	printf("%d\n", waterCount);
}