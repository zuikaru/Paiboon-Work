#include <string>
#include <Windows.h>

#define PARAGRAPH_SPACE 18

void moveTo(int x, int y);

void resetConsole();

void clearScreen();

void drawBorder();

void moveToWritingPos(int line);

void moveToWritingPos(int line,int offset);

void displayWelcome();

class ConsoleLine{
private: int length = 60;
		 int direction = this->DIRECTION_X;
		 int filling = this->DIRECTION_Y;
		 std::string text = "*";
		 int color = 7;
		 COORD startPos = COORD{ 0, 0 };
public: static const int DIRECTION_X = 1;
		static const int DIRECTION_Y = 2;
		static const int FORWARD = 3;
		static const int BACKWARD = 4;
public: ConsoleLine(int length, int direction, int filling, std::string text, int color, COORD startPos);
		ConsoleLine();
		void setLength(int length);
		void setDirection(int direction);
		//void setFilling(int filling);
		void setStartPos(int x,int y);
		void setStartPos(COORD coord);
		void setText(std::string text);
		void setColor(int color);
		void render();
};