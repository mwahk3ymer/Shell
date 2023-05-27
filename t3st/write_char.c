/**
 * _putchar - writes single character c to stdout.
 * @h: character to print.
 * Return: Returns 1 if successful.
 */
int _putchar(char h)
{
return (write(1, &h, 1));
}
