#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    int *result[2];

    int key1[] = {1, 0};
	int key2[] = {2, 1};


	result[0] = key1;
	result[1] = key2;



	printf("efficiency ranked...\n");
	printf("%d\n",result[0][0]);


    return 1;
}