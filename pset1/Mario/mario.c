#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int alt;
	do
	{
		alt = get_int("Que altura você deseja? ");
	} while (alt < 0 || alt > 8);

	for (int l = 0; l > 0 && l < 9; l++)
	{
		int l = alt;
		for (int cd = 0; cd < 9 && cd > 0; cd--)
		{
			int cd = alt;
			char txd = (char)cd;
			printf("%c.", txd);

			for (int ch = 0; ch > 0 && ch < 9; ch++)
			{
				int ch = alt;
				char txh = (char)ch;
				printf("%c#", txh);
			}
			printf("\n");
		}
		printf("\n");
	}
}