#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int number;
	printf("Enter building number => ");
	scanf("%d", &number);
	switch (number)
	{
	case 1: printf("Long building\n"); break;
	case 2: printf("Samakayajan\n"); break;
	case 3: printf("Piyamaharachanusorn\n"); break;
	case 4: printf("Sala Phrasadet\n"); break;
	case 5: printf("Damrongrachanuphap\n"); break;
	case 6: printf("Suankularbramruk"); break;
	default: printf("No building with that number."); break;
	}
	_getch();
	system("cls");
	main();
}

