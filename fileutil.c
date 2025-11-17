#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

#define CAPACITY_START 20

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.

	int capacity = CAPACITY_START;	
	char (*arr)[COLS] = malloc(capacity * sizeof(char[COLS]));

	char line[1000];
	int entries = 0;
	

    while(fgets(line, 1000, in) != NULL)
    {
		char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

		if(entries == capacity)
		{
			capacity += 10;
			arr = realloc(arr, capacity * sizeof(char[COLS]));
		}

        strcpy(arr[entries], line);
        entries++;
    }

	fclose(in);
	// The size should be the number of entries in the array.
	*size = entries;
	// Return pointer to the array.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{

	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    for (int i = 0; i < size; i++)
	{
		if(strstr(lines[i], target) != NULL)
		{
			return lines[i];
		}
	}
    return NULL;
}

char * stringSearch2D(char *target, char (*lines)[COLS], int size)
{
    for (int i = 0; i < size; i++)
	{
		if (strcmp(lines[i], target) == 0)
		{
			return lines[i];
		}
	}
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{

}

void free2D(char (*arr)[COLS])
{
	free(arr);
}
