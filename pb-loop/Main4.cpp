#include <stdio.h>
#include <conio.h>

// Name looping
int main(){
	int i = 0;
	printf("\n\n\n\n%47s\n","Repeat my name");
	printf("%47s\n","==============");
	for (i = 1; i < 12; i++){
		printf("%30d.%s\n", i, "Pavat Lertpiromlak");
	}
	_getch();
	return 0;
}