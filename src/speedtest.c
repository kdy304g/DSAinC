#include "hash.h"
#define SIZE 10000
#define NUMHashes 7

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
	unsigned long arrayOfKeys[NUMHashes][SIZE];
	// hashes[10] = {hash1, hash2,	hash3, hash4, hash5, hash6};
	unsigned long (*hashes[10]) (unsigned char data_string[]);
  hashes[0] = hash1;
	hashes[1] = hash2;
	hashes[2] = hash3;
	hashes[3] = hash4;
	hashes[4] = hash5;
	hashes[5] = hash6;

  FILE *colptr = fopen("colData", "w");
  FILE *speedptr = fopen("speedData", "w");

  FILE *words = fopen("words.txt","r'");
  FILE *colLenptr = fopen("colLenData", "w");

	make_random_strings(strings, SIZE);

  //Testing for collisions
  for(int i=0; i < 6; i++) {
		for(int j=0; j < SIZE; j++ ) {
			(arrayOfKeys[i])[j] = (*hashes[i])(strings[j]);
		}

		result[i] = check_key_duplicates(arrayOfKeys[i], SIZE);
		fprintf(colptr,"hash%d result: %d\n", (i+1), result[i]);
	}

	qsort(result, 6, sizeof(int), comparator);
	fprintf(colptr,"effectiveness ranked...\n");
	for(int j=0; j<6; j++){
		fprintf(colptr,"%d\n",result[j]);
	}
  printf("%s\n","Collisions Complete" );
  fclose(colptr);

  // Testing for Frequency of collisions and Length

    char *line = malloc(30);

      while(!feof(words)){
        fgets(line, 30, words);
        for(int i=0; i < 6; i++) {
        fprintf(colLenptr, "Hash: %d Len: %li Val %li\n",(i+1), strlen(line), (*hashes[i])(line));

      }
    }
printf("%s\n","Length and Frequency Complete" );
  fclose(colLenptr);
  fclose(words);

  //Testing for speed
	for(int i=0; i < 6; i++) {
        sec = 0;
		for (int k = 1000; k<SIZE; k++){
			// sec0 = get_seconds(); /* start timer */
			for(int j=0; j < k; j++) {
				sec0 = get_seconds();
				(arrayOfKeys[i])[j] = (*hashes[i])(strings[j]);
				sec = sec +  (get_seconds() - sec0);/* end timer */
			}
			fprintf(speedptr, "Size: %7d  hash: %d %f\n",k,(i+1), sec/k);
		}
	}
  printf("%s\n","Speed Test Complete" );
  fclose(speedptr);

	return 0;
}
