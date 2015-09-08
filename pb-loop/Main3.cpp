#include <stdio.h>
#include <conio.h>

// 1+2+3+...
int main(){
	int i = 1;
	int collector = 0;
	for (i = 1; i < 11;i++){
		printf("%d%s",i,i<10? "+" : " = ");
		collector += i;
	}
	printf("%d",collector);
	_getch();
	return 0;
}