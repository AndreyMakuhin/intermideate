#include <conio.h>
#include <iostream>

void print(const char* c)
{
	for (; *c != 0; c++)
	{
		_putch(*c);
	}
}

void read(char* buf, int buf_size)
{
	char* end = buf + buf_size - 1;
	for (char c = _getch(); c != 13 && buf < end; c = _getch(), buf++)
	{
		_putch(c);
		*buf = c;
	}
	*buf = 0;
}

int main()
{
	char msg[] = "Hello, world!";
	char buffer[69];

	read(buffer, 69);

	print("\n");
	print(buffer);

	while (!_kbhit());

	return 0;
}