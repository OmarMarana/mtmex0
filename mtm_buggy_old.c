#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
//==============================================================================

/** swaps two strings */
void swap(char** a, char** b);

/** Retrieves the maximal string by lexicographical order */
char* getLongestString(char** strings, int size);

/** Sorts and array of strings */
void sortStrings(char** strings, int size);

/** Reads an integer from the standard input */
int readSize();

/** Reads a string from the standard input and allocates memory for it */
char* readWord();

/** Reads strings from the standard input and allocates an array for them */
char** readWords(int size);

/** Frees the memory of an allocated array of strings */
void freeWords(char** words, int size);

/** Prints the required statistics of the strings array passed as parameter */
void printResults(char** words, int size);

//==============================================================================

void swap(char** a, char** b) {
	char* temp = *a;
	*a = *b;
	*b = temp;
}

char* getLongestString(char** strings, int size) {
	// char* max = NULL;       // maybe becuase we arent allowed to look at the location max= NULL
	char* max = strings[0];
	int i; 
	for ( i = 0; i < size; i++) {
		if (strlen(max) < strlen(strings[i])) {
			max = strings[i];
		}
	}
	return max;
}

void sortStrings(char** strings, int size) {
	bool changed = true;
	while (changed) {
		changed = false;
		int i;
		for ( i = 0; i < size - 1; i++) {
			// if (strcmp(strings[i], strings[i + 1]) >= 0) {         
			if (strcmp(strings[i], strings[i + 1]) > 0) {
				swap(&strings[i], &strings[i + 1]);
				changed = true;
			}
		}
	}
}

int readSize() {
	int size = 0;
	printf("Enter number of strings:\n");
	scanf("%d", &size);
	return size;
}

void printResults(char** words, int size) {
	char* longest = getLongestString(words, size);    
	printf("The longest word is: %s\n", longest);
	sortStrings(words, size);
	// printf("The maximal word lexicographically is: %s\n", words[size]); // shouldnt access words[size] because 
	printf("The maximal word lexicographically is: %s\n", words[size-1]);     // why are they doing mac then min, it should be the other way arounds
	printf("The minimal word lexicographically is: %s\n", words[0]);
}

char* readWord() {
	char buffer[BUFFER_SIZE] = "";  // why starts with space? and not empty?
	scanf("%s", buffer);
	if (strlen(buffer) < 1) {
		return NULL;
	}
	char* str = malloc(strlen(buffer) + 1);
	if (!str) {
		return NULL;
	}
	return strcpy(str,buffer);
}

char** readWords(int size) {
	char** words = malloc(size * sizeof(*words));
	if (words == NULL) {
		return NULL;
	}
	int i;
	for ( i = 0; i < size; ++i) {
		words[i] = readWord();
		if (words[i] == NULL) {
			freeWords(words, size);
			return NULL;
		}
	}
	return words;
}

void freeWords(char** words, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free(words[i]);
	}
	free(words);
}

int main() {
	int size = readSize();
	if (size < 1) {
		printf("Invalid size\n");
	}
	char** words = readWords(size);
	if (words == NULL) {
		printf("Error reading words\n");
		return 0;
	}
	printResults(words, size);
	freeWords(words, size);
	return 0;
}
