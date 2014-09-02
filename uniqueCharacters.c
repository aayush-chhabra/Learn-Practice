# include <stdio.h> 
# include <stdlib.h>


    int calculateAnswer(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += i;
        }
        return count;
    }


int main() {
    int n;
    int result;
    int cacheCount = 0;

    int cache[11];

    //make em all 0
    for (int i = 0; i < 11; i++) {
        cache[i] = 0;
    }

    while (1) {

        printf("Enter a number\n");
        scanf("%d", & n);

        for (int i = 0; i < 11; i++) {

            if (cache[i] == n) {

                printf("Number : %d", cache[i]);
                printf("Cache Hit!!");

            }
        }

        result = calculateAnswer(n);
        printf("Cache : %d\n", result);

        if (cacheCount == 11) {
            cacheCount = 0;
            printf("Cachecount reset to 0");
        }

        cache[cacheCount] = n;
        cacheCount++;

        for (int i = 0; i < 11; i++) {
            printf("%d", cache[i]);
        }
        printf("\nCache Count : %d\n", cacheCount);

    }

    //printf("%d\n", result);
    return 0;
}