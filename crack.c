#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

int trim(char str[]);

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    char (*hashes)[HASH_LEN] = loadFile2D(argv[1], &size);
    //char **hashes = loadFile2D(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *in = fopen(argv[2], "r");
    if(!in)
    {
        
        printf("Unable to open %s\n", argv[2]);
        exit(1);
    }

    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    char line[1000];
    while(fgets(line, 1000, in) != NULL)
    {
        int length = trim(line);
        char *target = md5(line, length);
        char *found = stringSearch2D(target, hashes, size);
		if (found)
			printf("Password: %s\nHash: %s\n", line, found);
		else
			printf("Not found!\n");
        free(target);
    }
    printf("Success!\n");

    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.

    // TODO
    // When done with the file:
    //   Close the file
    fclose(in);
    //   Display the number of hashes found.
    printf("Number of Hashes: %d\n", size);
    //   Free up memory.
    free2D(hashes);
}

int trim(char str[])
{
    char *nl = strchr(str, '\n');
    if (nl != NULL) *nl = '\0';

    return strlen(str);
}
