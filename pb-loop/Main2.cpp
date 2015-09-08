#include <stdio.h>
#include <conio.h>

// Factorial
int main(){
	int counter = 0, result = 1;
	int total = 10;
	for (counter = 1; counter <= total; counter++){
		printf("%d%s",counter,counter < total ? " x " : " = ");
		result *= counter;
	}
	printf("%d",result);
	_getch();
	return 0;
}