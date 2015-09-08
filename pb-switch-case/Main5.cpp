#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	char number;
	system("cls");
	printf("Enter one character => ");
	scanf("%c", &number);
	switch (number)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': printf("This character is consonant.");break;
	default: printf("This character is alphabet.");break;
	}
	_getch();
	system("cls");
}

