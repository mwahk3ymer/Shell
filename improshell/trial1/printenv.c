/**
 * printenv - prints in current
 *
 * Return: void
 */
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}
