/* Nick Mudge 24 February 2008 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 50000

#define BYTE_TO_BINARY_PATTERN "%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x8000000 ? '1' : '0'), \
  (byte & 0x4000000 ? '1' : '0'), \
  (byte & 0x2000000 ? '1' : '0'), \
  (byte & 0x1000000 ? '1' : '0'), \
  (byte & 0x0800000 ? '1' : '0'), \
  (byte & 0x0400000 ? '1' : '0'), \
  (byte & 0x0200000 ? '1' : '0'), \
  (byte & 0x0100000 ? '1' : '0'), \
  (byte & 0x80000 ? '1' : '0'), \
  (byte & 0x40000 ? '1' : '0'), \
  (byte & 0x20000 ? '1' : '0'), \
  (byte & 0x10000 ? '1' : '0'), \
  (byte & 0x08000 ? '1' : '0'), \
  (byte & 0x04000 ? '1' : '0'), \
  (byte & 0x02000 ? '1' : '0'), \
  (byte & 0x01000 ? '1' : '0'), \
  (byte & 0x8000 ? '1' : '0'), \
  (byte & 0x4000 ? '1' : '0'), \
  (byte & 0x2000 ? '1' : '0'), \
  (byte & 0x1000 ? '1' : '0'), \
  (byte & 0x0800 ? '1' : '0'), \
  (byte & 0x0400 ? '1' : '0'), \
  (byte & 0x0200 ? '1' : '0'), \
  (byte & 0x0100 ? '1' : '0'), \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')


union {
  long l;
  u_int32_t i;
}b;


void printb (byte){
  printf(BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(byte));
}


void make_random_strings(unsigned char *strings[]);
char get_random_character(void);
unsigned long hash1(unsigned char *str);
unsigned long hash2(unsigned char *str);
unsigned long hash3(unsigned char *str);
unsigned long hash4(unsigned char *str);
unsigned long hash5(unsigned char *str);
unsigned long hash6(unsigned char *str);
unsigned long hash7(unsigned char *str);
int check_key_duplicates(unsigned long *keys);
int linear_array_search(int *array, int search, int size);

int main(void) {
	/*
	unsigned char *strings[SIZE];
	unsigned long keys[SIZE];
	int i;
	srand(time(0));

	make_random_strings(strings);
	for(i=0; i < SIZE; i++) {
		keys[i] = hash2(strings[i]);
	}
	printf("%d\n", check_key_duplicates(keys));
	return 0;
	*/
	char str[] = "0\0";
	printf("%lu\n",hash2(str));

	char *str1 = "0\0" ;
	printf("%lu\n",hash2(str1));

	char *str2 = "1\0" ;
	printf("%lu\n",hash2(str2));
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
	while ((c = *str++)){

	    hash += c;
	}
	return hash;
}

/* From: http://www.cse.yorku.ca/~oz/hash.html
   Function: djb2 */
unsigned long hash2(unsigned char *str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++)){
		printf("%i\n",c);
		printb(hash);
		hash = ((hash << 5) + hash) + c; /* Same things as: hash * 33 + c */
	}
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
   Function: UNIX ELF hash */
unsigned long hash6(unsigned char *str) {
	unsigned long h = 0, g;
	while ((*str)) {
		h = ( h << 4 ) + *str++;
		if ((g = h & 0xF0000000))
		h ^= g >> 24;
		h &= ~g;
	}
	return h;
}

/* From: http://www.sparknotes.com/cs/searching/hashtables/section2.rhtml
   Function: char XORhash( char *key, int len) */
unsigned long hash7(unsigned char *str) {
	unsigned long hash;
	int  i;
	while ((i = *str++))
		hash=hash^i;
	return hash;
}


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
