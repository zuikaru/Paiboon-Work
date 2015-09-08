#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int score = 0;
	system("cls");
	printf("Enter score > ");
	scanf("%d", &score);
	if (score <= 49){
		printf("Grade : F");
	}
	else if (score <= 59){
		printf("Grade : D");
	}
	else if (score <= 69){
		printf("Grade : C");
	}
	else if (score <= 79){
		printf("Grade : B");
	}
	else{
		printf("Grade : A");
	}
	_getch();
	return main();
}