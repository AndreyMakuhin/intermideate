#include <conio.h>
#include <fstream>


namespace andrey
{

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

	void strrev(char* str)
	{
		char* left = str;
		char* right = left;
		while (*right != 0)
			right++;
		right--;

		while (left < right)
		{
			char temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;
		}
	}

	int str2int(char* str)
	{
		int res = 0;
		int posMultiplayer = 1;

		char* right = str;
		while (*right > '0' && *right < '9')
			right++;
		right--;

		while (right >= str)
		{
			res += (*right - '0') * posMultiplayer;
			right--;
			posMultiplayer *= 10;
		}

		return res;
	}

	void int2str(int num, char* buf)
	{
		int divider = 10;
		char* start = buf;
	
		do
		{
			int digit = num % divider;
			*buf = '0' + digit;
			buf++;			
			num /= 10;

		} while (num > 0);

		*buf = 0;
		strrev(start);		
	}
}

int main()
{
	const int myInt = 8573949;
	std::ofstream out("output.dat", std::ios::binary);

	out.write(reinterpret_cast<const char*>(&myInt), sizeof(myInt));

	out.close();

	int data;
	std::ifstream in("output.dat", std::ios::binary);
	in.read(reinterpret_cast<char*>(&data), sizeof(data));

	char buffer[256];

	andrey::int2str(data, buffer);
	andrey::print(buffer);

	andrey::print("\nPress space");
	while (!_kbhit());

	return 0;
}