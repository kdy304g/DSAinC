#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10000

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

int comparator(const void *p, const void *q)  
{ 
	int first = *(const int *)p;
	int second = *(const int *)q;
    if (first > second) {
		return 1;
	} else if (first == second) {
		return 0;
	} else {
		return -1;
	}
} 

int main(void) {
	int result[6];
	unsigned char *strings[SIZE];
	unsigned long keys1[SIZE];
	unsigned long keys2[SIZE];
	unsigned long keys3[SIZE];
	unsigned long keys4[SIZE];
	unsigned long keys5[SIZE];
	unsigned long keys6[SIZE];
	// unsigned long keys7[SIZE];
	// unsigned long keys8[SIZE];
	unsigned long *arrayOfKeys[10];
	arrayOfKeys[0] = keys1;
	arrayOfKeys[1] = keys2;
	arrayOfKeys[2] = keys3;
	arrayOfKeys[3] = keys4;
	arrayOfKeys[4] = keys5;
	arrayOfKeys[5] = keys6;

	unsigned long (*hashes[10]) (unsigned char data_string[]);
	hashes[0] = hash1;
	hashes[1] = hash2;
	hashes[2] = hash3;
	hashes[3] = hash4;
	hashes[4] = hash5;
	hashes[5] = hash6;

	srand(time(0));
	make_random_strings(strings);

	for(int i=0; i < 6; i++) {
		for(int j=0; j < SIZE; j++ ) {
			(arrayOfKeys[i])[j] = (*hashes[i])(strings[j]);
		}
		printf("hash%d result: %d\n", (i+1), check_key_duplicates(arrayOfKeys[i]));
	}

	// for(i=0; i < SIZE; i++) {
	// 	keys1[i] = hash1(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys2[i] = hash2(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys3[i] = hash3(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys4[i] = hash4(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys5[i] = hash5(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys6[i] = hash6(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys7[i] = hash7(strings[i]);
	// }
	// for(i=0; i < SIZE; i++) {
	// 	keys8[i] = hash8(strings[i]);
	// }

	// printf("7th hash result: %d\n", check_key_duplicates(keys7));
	// printf("8th hash result: %d\n", check_key_duplicates(keys8));
	// int key1[] = {1, check_key_duplicates(keys1)};
	// int key2[] = {2, check_key_duplicates(keys2)};
	// int key3[] = {3, check_key_duplicates(keys3)};
	// int key4[] = {4, check_key_duplicates(keys4)};
	// int key5[] = {5, check_key_duplicates(keys5)};
	// int key6[] = {6, check_key_duplicates(keys6)};

	// int duplicates[6];
	// duplicates[0] = check_key_duplicates(keys1);
	// duplicates[0] = check_key_duplicates(keys2);
	// duplicates[0] = check_key_duplicates(keys3);
	// duplicates[0] = check_key_duplicates(keys4);
	// duplicates[0] = check_key_duplicates(keys5);
	// duplicates[0] = check_key_duplicates(keys6);

	result[0] = check_key_duplicates(keys1);
	result[1] = check_key_duplicates(keys2);
	result[2] = check_key_duplicates(keys3);
	result[3] = check_key_duplicates(keys4);
	result[4] = check_key_duplicates(keys5);
	result[5] = check_key_duplicates(keys6);

	qsort(result, 6, sizeof(int), comparator);
	printf("efficiency ranked...\n");
	for(int j=0; j<6; j++){
		printf("%d\n",result[j]);
	}
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









