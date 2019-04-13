#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#define SIZE 100000

void make_random_strings(unsigned char *strings[]);
char get_random_character(void);
unsigned long hash1(unsigned char *str);
unsigned long hash2(unsigned char *str);
unsigned long hash3(unsigned char *str);
unsigned long hash4(unsigned char *str);
unsigned long hash5(unsigned char *str);
unsigned long hash6(unsigned char *str);
// unsigned long hash7(unsigned char *str);
// unsigned long hash8(unsigned char *str);
int check_key_duplicates(unsigned long *keys);
int linear_array_search(int *array, int search, int size);
double sec0, sec; /* timing variables */
long clk_tck;

double get_seconds() { /* routine to read time */
    struct tms rusage;
    times(&rusage); /* UNIX utility: time in clock ticks */
    return (double) (rusage.tms_utime)/clk_tck;
}

int comparator(const void *p, const void *q)
{
	int first = *(const int *)p;
	int second = *(const int *)q;
	return first - second;
}

int main(void) {
	int result[6];
	clk_tck = sysconf(_SC_CLK_TCK);
	unsigned char *strings[SIZE];
	unsigned long arrayOfKeys[10][SIZE];

	unsigned long (*hashes[10]) (unsigned char data_string[]);
	hashes[0] = hash1;
	hashes[1] = hash2;
	hashes[2] = hash3;
	hashes[3] = hash4;
	hashes[4] = hash5;
	hashes[5] = hash6;

	srand(time(0));
	make_random_strings(strings);
	int time[6];
	for(int i=0; i < 6; i++) {
    sec = 0;
		for (int k = 1000; k<SIZE; k++){
			// sec0 = get_seconds(); /* start timer */
			for(int j=0; j < k; j++) {
				sec0 = get_seconds();
				(arrayOfKeys[i])[j] = (*hashes[i])(strings[j]);
				sec = sec +  (get_seconds() - sec0);/* end timer */
			}
			printf("Size: %7d  hash: %d %f\n",k,(i+1), sec);
			// result[i] = check_key_duplicates(arrayOfKeys[i]);
			// printf("hash%d result: %d\n", (i+1), result[i]);
		}
	}



	// qsort(result, 6, sizeof(int), comparator);
	// printf("efficiency ranked...\n");
	// for(int j=0; j<6; j++){
	// 	printf("%d\n",result[j]);
	// }
	return 0;
}

void make_random_strings(unsigned char *strings[]) {
	int strlength;
	int i;
	int j;
	int k;
	for(i = 0; i < SIZE; i++) {
		strlength = (rand() % 25) + 1;
		strings[i] = (unsigned char *) malloc((strlength+1) * sizeof(char));
		for(j = 0; j < strlength; j++) {
			strings[i][j] = get_random_character();
		}
		for(k=0; k<(i-1); k++) {
			if(strcmp((char *) strings[i], (char *) strings[k]) == 0) {
				i--;
				break;
			}
		}
	}
}

char get_random_character(void) {
	int random_char_int;
	random_char_int = (rand() % 75) + 48;
	if((random_char_int > 57 && random_char_int < 65) ||
		(random_char_int > 90 && random_char_int < 97 && random_char_int != 95) ||
		(random_char_int > 122)) {
		return (char) get_random_character();
	}
	else
		return (char) random_char_int;
}

/* From: http://www.cse.yorku.ca/~oz/hash.html
   Function: lose lose */
unsigned long hash1(unsigned char *str) {
	unsigned int hash = 0;
	int c;
	while ((c = *str++))
	    hash += c;
	return hash;
}

/* From: http://www.cse.yorku.ca/~oz/hash.html
   Function: djb2 */
unsigned long hash2(unsigned char *str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* Same things as: hash * 33 + c */
	return hash;
}

/* From: http://www.cse.yorku.ca/~oz/hash.html
   Function: djb2 with xor */
unsigned long hash3(unsigned char *str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++))
		hash = hash * 33 ^ c;
	return hash;
}

/* From: http://www.cse.yorku.ca/~oz/hash.html
   Function: sdbm */
unsigned long hash4(unsigned char *str) {
	unsigned long hash = 0;
	int c;
	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
		return hash;
}

/* From: http://www.sparknotes.com/cs/searching/hashtables/section2.rhtml
   Function: int hashpjw(char *s) */
unsigned long hash5(unsigned char *str) {
	unsigned char *p;
	unsigned int h, g;
	h = 0;
	for(p=str; *p!='\0'; p++){
		h = (h<<4) + *p;
		if ((g = h&0xF0000000)) {
			h ^= g>>24;
			h ^= g;
		}
	}
	return h;
}


/* From: http://www.sparknotes.com/cs/searching/hashtables/section2.rhtml
   Function: char XORhash( char *key, int len) */
unsigned long hash6(unsigned char *str) {
	unsigned long hash;
	int  i;
	while ((i = *str++))
		hash=hash^i;
	return hash;
}

// unsigned long hash8(unsigned char *str)
// {
//     unsigned long hash = 5381;
//     int c;

//     while ((c = *str++))
//         hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

//     return hash;
// }


int check_key_duplicates(unsigned long *keys) {
	int i;
	int j;
	int duplicate_count = 0;
	unsigned long keysearch = 0;
	int duplicate_track[SIZE];
	for(i=0; i < SIZE; i++) {
		if(linear_array_search(duplicate_track, i, duplicate_count-1) != -1)
			continue;
		keysearch = keys[i];
		for(j=0; j < SIZE; j++) {
			if(keysearch == keys[j] && i != j) {
				duplicate_track[duplicate_count] = j;
				duplicate_count++;
			}
		}
	}
	return duplicate_count;
}

int linear_array_search(int *array, int search, int size) {
	int i;
	for(i=0; i<size; i++) {
		if (array[i] == search)
			return i;
	}
	return -1;
}
