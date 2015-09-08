#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int score = 0;
	system("cls");
	printf("Enter score > ");
	scanf("%d", &score);
	if (score >= 80){
		printf("Grade : A");
	}
	else if (score >= 80){
		printf("Grade : B");
	}
	else if (score >= 60){
		printf("Grade : C");
	}
	else if (score >= 50){
		printf("Grade : D");
	}
	else{
		printf("Grade : F");
	}
	_getch();
	return main();
}