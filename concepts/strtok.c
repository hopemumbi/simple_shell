#include <string.h> /*header to include strtok*/
#include <stdio.h>/*header for printf*/

/**
 *char *strtok(char *restrict str, const char *restrict delim);
 * strtok - Split a string into tokens based on a delimiter
 *
 * This function breaks a string into a sequence of tokens, using the
 * characters in `delim` as delimiters. On the first call, the function
 * expects a C string as argument for `str`, which is the string to be
 * parsed. In subsequent calls, the function expects a NULL pointer and
 * uses the saved position in `str` to continue parsing the same string.
 *
 * Arguments:
 *  - str: A pointer to the null-terminated byte string to be parsed.
 *         On the first call, this should point to the string to be parsed.
 *         On subsequent calls, this should be NULL to continue parsing
 *         the same string.
 *  - delim: A pointer to a null-terminated byte string specifying a set
 *           of delimiters that determine where the tokens are extracted.
 *
 * Returns:
 *  - On the first call, the function returns a pointer to the first token
 *    found in the string. On subsequent calls, it returns a pointer to the
 *    next token, or NULL if there are no more tokens.
 *
 * Note: This function modifies the input string `str` by replacing
 *       the delimiter characters with null bytes ('\0').
 */
int main()
{
    // Input string to be tokenized
    char str[] = "hello poh have a good day";

    // Delimiter used to separate tokens
    char delim[] = " ";

    // Pointer to hold each token
    char *words;

    // Get the first token using strtok
    words = strtok(str, delim);

    // Loop to print all tokens
    while (words != NULL)
    {
        // Print the current token
        printf("%s\n", words);

        // Get the next token
        words = strtok(NULL, delim);
    }

    // Return 0 to indicate successful completion
    return (0);
}

