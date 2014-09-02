#include <stdio.h>


void compute_done(int start, int end, int n){
    int mid = (start + end)/2;
    int newSquare = mid * mid;
    
    printf("%d\n", newSquare);

    if(newSquare > n){
        end = mid;
        compute_done(start, end, n);
    }
    
    if(newSquare < n){
        start = mid+1;
        compute_done(start, end, n);
    }
    
    if(newSquare == n){
        printf("%d", mid);
    }
}

void compute_sqrt(int n) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    compute_done(1,n,n);
}

int main(){
	compute_sqrt(900);
}