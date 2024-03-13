#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *ssize_t getline(char **restrict lineptr, size_t *restrict n,
 *                      FILE *restrict stream);
 *
 * getline - Read a line from a file stream, dynamically allocating memory as needed
 *
 * This function reads a line from the specified file stream `stream`, storing
 * the characters in a dynamically allocated buffer pointed to by `lineptr`.
 * The buffer is automatically resized as necessary to accommodate longer lines,
 * and its size is updated in `n` to reflect the new size.
 *
 * If `lineptr` is NULL, a new buffer is allocated. If `*lineptr` is not NULL,
 * it should be a pointer to a buffer previously allocated with malloc(), and
 * this buffer will be used as the initial buffer for the line.
 *
 * The function stops reading when a newline character is found, at the end of
 * the file (EOF), or when an error occurs. The newline character, if found, is
 * included in the buffer. If no characters are read before the end of the file,
 * `*lineptr` will be set to NULL and `*n` will be set to 0.
 *
 * After a successful call to `getline()`, the buffer returned in `*lineptr` should
 * be freed using free() to avoid memory leaks.
 *
 * Arguments:
 *  - lineptr: A pointer to a buffer where the line will be stored, or NULL
 *             to allocate a new buffer.
 *  - n: A pointer to a size_t variable containing the size of the buffer pointed
 *       to by `lineptr`. On return, this variable is updated to contain the size
 *       of the allocated buffer.
 *  - stream: A pointer to the FILE stream from which to read the line.
 *
 * Returns:
 *  - On success, the number of characters read, including the newline character
 *    (but excluding the null terminator), is returned. If the end of the file
 *    is reached, the return value is -1.
 *  - On error, the return value is -1, and the contents of `*lineptr` and `*n`
 *    are undefined.
 *
 * Note: This function is a POSIX extension and may not be available on all systems.`
 *
 *Write a program that prints "$ ",
 *wait for the user to enter a command
 *prints it on the next line.
 *continuously prompt the user with $ 
 *read commands until the user enters an end-of-file character (Ctrl+D 
 *return -1 on failure
 */
int main()
{
	/*Pointer to a buffer where the line will be stored*/
	char *lineptr = NULL;
	/*Size of the buffer (initially 0)*/
	size_t n = 0;

	/*Print a prompt for the user*/
	printf("$ ");

	/**
	 * Read a line of input from the user
	 * The getline function will allocate memory for the line
	 * and update lineptr and n accordingly
	 */
	while(getline(&lineptr, &n, stdin) != -1)
	{
		/*Print the command entered by the user*/
		printf("%s", lineptr);
		/*Print the prompt for the next command*/
		printf("$ ");
	}
	/*Free the memory allocated for the line*/
	free(lineptr);

	return(0);
}
