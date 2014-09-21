#include <stdio.h>
void merger(int *a, int *b, int aL, int bL);
void merge_arrays(int *a, int a_length, int *b, int b_length) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");

    if(a_length > b_length){
        printf("I have reached here!! :)\n");
        merger(a, b, a_length, b_length);    
    
    }
    else{
        merger(b, a, b_length, a_length);
    }
}

void merger(int *a, int *b, int aL, int bL){
    int c[20], i, j, k;
    for(i=0, j=0, k=0; ; k++){

        printf("i = %d j = %d k = %d a[i] = %d b[j] = %d\n",i,j,k,a[i],b[j]);


        if(j<bL){
            if(a[i] < b[j]){
                c[k]=a[i];
                i++; 
            }
            else if(a[i] > b[j]){
                c[k]=b[j];
                j++;
            }
            else{
                c[k]=b[j];
                c[++k]=a[i];
                i++;
                j++;
            }
        }
        else{

            if((i >= aL-1) && (j >= bL-1))
                break;

            c[k] = a[i];
            i++;


        }
    }
    for(i=0; i<k; i++)
        printf("%d ", c[i]);
}

int main(){
    int a[] = {2,3,7,8,8};
    int b[]={7,8,13};
    merge_arrays(a, 5, b, 3);
}