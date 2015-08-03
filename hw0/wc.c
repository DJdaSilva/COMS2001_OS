#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int totalChars = 0;
int totalWords = 0;
int totalLines = 0;

void wc( FILE *infile, char *inname) {
	int chars = 0;
	int words = 0;
	int lines = 0;
	bool wordflag = false;
	char curr;

	if ( (infile = fopen(inname, "r")) == NULL) {
		printf("File not found!");
	}
	
	while (!feof(infile)) {
		curr = fgetc(infile);

		if ( (curr != '\n') && (curr != '\t') ) {
			chars++;
			if (wordflag == true) {
				words++;
				wordflag = false;
			}
		}

		if ((curr == ' ') || (curr == '\n') || (curr == '\t')) {
			wordflag = true;
			if (curr == '\n') {
				lines++;
			}
		}
	
	}
	chars--; //Not 100% sure, likely a whitespace/blankspace char I've forgotten about
	
	totalChars += chars;
	totalWords += words;
	totalLines += lines; 
	printf("%s:\t%d\t\t%d\t%d\n", inname, chars, words, lines);
	
}

int main(int argc, char *argv[]) {

	FILE *File;
	int k;

	printf("\nFile name\tCharacters\tWords\tLines\n");
	
	for (k = 1; k < argc; k++) {
		wc(File, argv[k]);
	}

	printf("Totals:\t\t%d\t\t%d\t%d\n", totalChars, totalWords, totalLines);
	
	
}


