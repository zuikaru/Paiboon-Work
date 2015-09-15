#include <Windows.h>
#include "TextColor.h"

void setTextColor(int color){
	int newColor;
	newColor |= color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}