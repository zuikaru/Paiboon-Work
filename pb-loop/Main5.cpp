#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Multiplication table
int main(){
	int counter = 1, multiplier = 12;
	printf("Enter multiplier => ");
	scanf("%d",&multiplier);
	for (counter = 1; counter <= 12; counter++){
		printf("%d x %d = %d\n",multiplier,counter,multiplier*counter);
	}
	_getch();
	return 0;
}