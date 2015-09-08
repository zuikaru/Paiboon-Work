#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int number = 0;
	printf("Enter number => ");
	scanf("%d",&number);
	switch (number)
	{
	case 1: printf("One\n"); break;
	case 2: printf("Two\n"); break;
	case 3: printf("Three\n"); break;
	case 4: printf("Four\n"); break;
	default: printf("Number is out of 1-4"); break;
	}
	_getch();
	system("cls");
	main();
}

