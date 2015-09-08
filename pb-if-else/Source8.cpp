#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int score = 0;
	system("cls");
	printf("Enter score > ");
	scanf("%d", &score);
	if (!!(score < 50)){
		printf("Grade : F");
	}
	else if (score < 60){
		printf("Grade : D");
	}
	else if (score < 70){
		printf("Grade : C");
	}
	else if (score < 80){
		printf("Grade : B");
	}
	else{
		printf("Grade : A");
	}
	_getch();
	return main();
}