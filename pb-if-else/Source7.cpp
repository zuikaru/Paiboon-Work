#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int score = 0;
	system("cls");
	printf("Enter score > ");
	scanf("%d", &score);
	if (!(score <= 79)){
		printf("Grade : A");
	}
	else if (score > 69){
		printf("Grade : B");
	}
	else if (score > 59){
		printf("Grade : C");
	}
	else if (score > 49){
		printf("Grade : D");
	}
	else{
		printf("Grade : F");
	}
	_getch();
	return main();
}