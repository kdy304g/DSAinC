#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>


unsigned long hash1(unsigned char *str);
unsigned long hash2(unsigned char *str);
unsigned long hash3(unsigned char *str);
unsigned long hash4(unsigned char *str);
unsigned long hash5(unsigned char *str);
unsigned long hash6(unsigned char *str);
// unsigned long hash7(unsigned char *str);
// unsigned long hash8(unsigned char *str);


void make_random_strings(unsigned char *strings[], int size);
char get_random_character(void);
int check_key_duplicates(unsigned long *keys, int size);
int linear_array_search(int *array, int search, int size);
