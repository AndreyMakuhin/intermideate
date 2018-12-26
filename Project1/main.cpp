#include <conio.h>
#include <iostream>

void print(const char* c)
{
	for (; *c != 0; c++)
	{
		_putch(*c);
	}
}

int main()
{
	char msg[] = "Hello? world!";

	print(msg);

	while (!_kbhit());

	return 0;
}