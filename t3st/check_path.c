#include "main.h"
/**
* check_path - Checks file status
* @s: Pointer to file name.
* Return: 0 if success, else non-zero
*/

int check_path(char *s)
{
struct stat st;

return (stat(s, &st));
}
