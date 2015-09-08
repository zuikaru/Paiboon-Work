#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int number = 0;
	printf("Enter your score => ");
	scanf("%d", &number);
	switch (number/10)
	{
	case 10:
	case 9:
	case 8: printf("grade = 4\n"); break;
	case 7: printf("grade = 3\n"); break;
	case 6: printf("grade = 2\n"); break;
	case 5: printf("grade = 1\n"); break;
	case 4:
	case 3:
	case 2:
	case 1:
	case 0: printf("grade = 0\n"); break;
	default: printf("Score is out of 0-100"); break;
	}
	_getch();
	system("cls");
	main();
}

