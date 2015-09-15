#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "TextColor.h"
#include "ConsoleSystem.h"

using namespace std;

// General function implementation
void moveTo(int x, int y){
	COORD cord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}

void resetConsole(){
	moveTo(0, 0);
	setTextColor(7);
}

void clearScreen(){
	system("cls");
}

void moveToWritingPos(int line){
	moveTo(PARAGRAPH_SPACE, line);
}

void moveToWritingPos(int line, int offset){
	moveTo(PARAGRAPH_SPACE + offset, line);
}

void displayWelcome(){
	moveTo(25, 5);
	setTextColor(TextColor::BLUE);
	cout << "Welcome to C Programming Quiz";
	moveTo(25, 6);
	setTextColor(TextColor::YELLOW);
	cout << "Press <Enter> to continue...";
	cin.get();
}

void drawBorder(){
	ConsoleLine line;
	line.setColor(6);
	line.setText("\x04");
	// X Axis
	line.setLength(70);
	line.setDirection(ConsoleLine::DIRECTION_X);
	// upper-x
	line.setStartPos(5, 1);
	line.render();
	// lower-x
	line.setStartPos(5, 23);
	line.render();
	// Y Axis
	line.setLength(23);
	line.setDirection(ConsoleLine::DIRECTION_Y);
	// left-y
	line.setStartPos(5, 1);
	line.render();
	// right-y
	line.setStartPos(75, 1);
	line.render();
}

// ConsoleLine implementation
ConsoleLine::ConsoleLine(int length, int direction, int filling, std::string text, int color, COORD startPos){
	this->length = length;
	this->direction = direction;
	this->filling = filling;
	this->text = text;
	this->color = color;
	this->startPos = startPos;
}

ConsoleLine::ConsoleLine(){
	this->direction = ConsoleLine::DIRECTION_X;
}

void ConsoleLine::setColor(int color){
	this->color = color;
}

void ConsoleLine::setLength(int length){
	this->length = length;
}

void ConsoleLine::setDirection(int direction){
	this->direction = direction;
}

void ConsoleLine::setStartPos(int x, int y){
	this->startPos.X = x;
	this->startPos.Y = y;
}

void ConsoleLine::setStartPos(COORD coord){
	this->startPos = coord;
}

void ConsoleLine::setText(std::string text){
	this->text = text;
}

void ConsoleLine::render(){
	// change location
	moveTo(this->startPos.X, this->startPos.Y);
	setTextColor(this->color);
	int counter = 0;
	for (counter = 0; counter < this->length; counter++){
		if (this->direction == ConsoleLine::DIRECTION_X){
			moveTo(this->startPos.X + counter, this->startPos.Y);
		}
		else{
			moveTo(this->startPos.X, this->startPos.Y + counter);
		}
		std::cout << this->text;
	}
}