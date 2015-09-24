#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>

using namespace std;

void setTextColor(int color);

enum TextColor{
	BLACK = 0,
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_AQUA = 3,
	DARK_RED = 4,
	DARK_PURPLE = 5,
	GOLD = 6,
	GRAY = 7,
	DARK_GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	AQUA = 11,
	RED = 12,
	LIGHT_PURPLE = 13,
	YELLOW = 14,
	WHITE = 15
};

#define PARAGRAPH_SPACE 13

void moveTo(int x, int y);

void resetConsole();

void clearScreen();

void drawBorder();

void moveToWritingPos(int line);

void moveToWritingPos(int line, int offset);

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
		void setStartPos(int x, int y);
		void setStartPos(COORD coord);
		void setText(std::string text);
		void setColor(int color);
		void render();
};

class Question{
private: map<int, string> question;
		 map<int, string> answer;
		 int correctAnswer;
		 int number;
public: Question(int number, string question, map<int, string> answer, int correct);
		Question(int number, vector<string> question, map<int, string> answer, int correct);
		Question();
		void setQuestion(int line, string question);
		void setNumber(int number);
		void clearQuestions();
		void setAnswer(int choice, string answer);
		void setCorrectAnswer(int choice);
		void clearAnswers();
		int renderAndGetAnswer();
		int waitForAnswer(int intputLine);
		string getAnswer(int choice);
		map<int, string> getAnswers();
		string getQuestion(int line);
		map<int, string> getQuestions();
		int getCorrectAnswer();
		int getNumber();
		int resultPosition();
		bool isCorrect(int choice);
		void render();
};

class Quiz{
private: map<int, Question> questions;
		 int score = 0;
		 int fullScore = 0;
public: Quiz();
		void addQuestion(Question question);
		void run();
		string calculateGrade();
};

int main(){
	drawBorder();
	displayWelcome();
	// Quiz
	clearScreen();
	drawBorder();
	Quiz quiz;
	// Example (Dummy) question
	quiz.addQuestion(Question(
		1, // No.
		"What is the size of char data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		1 // Correct choice
		));
	quiz.addQuestion(Question(
		2, // No.
		"What is the purpose of \"&\"(address of) operator?", // Question
		{ { 1, "To establish pointer values." }, { 2, "To conduct parameter passing by reference." }, { 3, "Both 1 and 2 correct" }, { 4, "No correct answer" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		3, // No.
		"int y = 6; printf(\"%d\",(y+=2)++);", // Question
		{ { 1, "8" }, { 2, "9" }, { 3, "0" }, { 4, "Compilation error" } }, // Choices
		2// Correct choice
		));
	quiz.addQuestion(Question(
		4, // No.
		"Which header contains system(); function?", // Question
		{ { 1, "stdlib.h" }, { 2, "stdio.h" }, { 3, "conio.h" }, { 4, "math.h" } }, // Choices
		1 // Correct choice
		));
	quiz.addQuestion(Question(
		5, // No.
		"Which of the following is not a C reserved keyword?", // Question
		{ { 1, "volatile" }, { 2, "extern" }, { 3, "double" }, { 4, "native" }, { 5, "struct" }, { 6, "unsigned" } }, // Choices
		4 // Correct choice
		));
	quiz.addQuestion(Question(
		6, // No.
		"Evaluate !(1 && !(0 || 1)).", // Question
		{ { 1, "true" }, { 2, "false" }, { 3, "Compilation error" } }, // Choices
		1 // Correct choice
		));
	quiz.addQuestion(Question(
		7, // No.
		vector < string > {"What is the different between #include ", "<header> and #include \"header\" ?"}, // Question
		{ { 1, "No different" }, { 2, "User created header and standard header" }, { 3, "Compilation order" }, { 4, "No correct choice" } }, // Choices
		2 // Correct choice
		));
	quiz.addQuestion(Question(
		8, // No.
		vector<string> { "int numbers[3] = {12,23,34}; ", "Which statement return 23 as the result?"}, // Question
		{ { 1, "numbers[2]" }, { 2, "numbers[-1]" }, { 3, "numbers[1]" }, { 4, "numbers[0]" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		9, // No.
		vector<string> { "int size = 10; float scores[size] = {13.37,4.2,6.666,8.8}; ", "printf(\"%.1f\",scores[1]);" }, // Question
		{ { 1, "4.2" }, { 2, "13.37" }, { 3, "13.3" }, { 4, "0" }, { 5, "Compilation error" } }, // Choices
		5 // Correct choice
		));
	quiz.addQuestion(Question(
		10, // No.
		"Which is a valid typecast", // Question
		{ { 1, "a(char)" }, { 2, "char:a" }, { 3, "(char)a" }, { 4, "to(char,a)" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		11, // No.
		"Which statement can be used on if statement?", // Question
		{ { 1, "!(0 == 1)" }, { 2, "('a' && true) || !(false > 3)" }, { 3, "a++" }, { 4, "'i' == false" }, { 5, "All of them" } }, // Choices
		5 // Correct choice
		));
	quiz.addQuestion(Question(
		12, // No.
		vector < string > {"int i = 0;", "    for(i = 0;i<10;i++);", "      i*=2;", "What is the value of i?"}, // Question
		{ { 1, "0" }, { 2, "20" }, { 3, "18" }, { 4, "2" }, { 5, "1" } }, // Choices
		2 // Correct choice
		));
	quiz.addQuestion(Question(
		13, // No.
		vector < string > {"What is the most important function that", "must be declared in order to make C program?"}, // Question
		{ { 1, "run" }, { 2, "start" }, { 3, "main" }, { 4, "printf" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		14, // No.
		"Which statement will make an infinite loop?", // Question
		{ { 1, "for(;;);" }, { 2, "while(0);" }, { 3, "Sleep(0);" }, { 4, "No correct answer" } }, // Choices
		1 // Correct choice
		));
	quiz.addQuestion(Question(
		15, // No.
		"If x is an integer variable, which statement is correct?", // Question
		{ { 1, "x = 3/4;" }, { 2, "x = new int[2];" }, { 3, "x = {1,3,3,7};" }, { 4, "x = \"555\"" }, { 5, "All of them" }, { 6, "No correct answer" } }, // Choices
		1 // Correct choice
		));
	quiz.addQuestion(Question(
		16, // No.
		vector < string > {
		"1. char a = 0x1A;",
			"    2. int b = false",
			"    3. float c = (int)'5' + acos(-1.0);",
			"    4. short int d = 1337*420*666;",
			"    How many choices are correct?"}, // Question
			{ { 1, "1" }, { 2, "2" }, { 3, "3" }, { 4, "4" }, { 5, "No one correct" } }, // Choices
			3 // Correct choice
			));
	quiz.addQuestion(Question(
		17, // No.
		vector < string > {"Which data type can store product of 20!/5!", "(! = factorial) without loss of significance?"}, // Question
		{ { 1, "int" }, { 2, "double" }, { 3, "long long int" }, { 4, "unsigned short double" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		18, // No.
		"Sleep(int time); What is the unit of a time variable", // Question
		{ { 4, "milliseconds" }, { 2, "nanoseconds" }, { 3, "seconds" }, { 1, "minutes" } }, // Choices
		4 // Correct choice
		));
	quiz.addQuestion(Question(
		19, // No.
		vector < string > {"Given an integer variable i, how to declare", "integer array with size equals to i?"}, // Question
		{ { 1, "int number[i];" }, { 2, "int* number = new int[i];" }, { 3, "int* number = malloc(i*sizeof(int));" }, { 4, "Both 2 and 3" } }, // Choices
		4 // Correct choice
		));
	quiz.addQuestion(Question(
		20, // No.
		"What is the new-line character?", // Question
		{ { 1, "\\b" }, { 2, "\\t" }, { 3, "\\n" }, { 4, "\\\\" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		21, // No.
		"Which statement is true?", // Question
		{ { 1, "(false || true) == (true && false)" }, { 2, "1>2" }, { 3, "0xFF - 1 > 256" }, { 4, "8" } }, // Choices
		4 // Correct choice
		));
	quiz.addQuestion(Question(
		22, // No.
		"char name[10] = \"zeus136\"; switch(name); Is it correct?", // Question
		{ { 1, "Yes" }, { 2, "No" }, { 3, "Dependent on the compiler." } }, // Choices
		2 // Correct choice
		));
	quiz.addQuestion(Question(
		23, // No.
		"What is true about C Programming language", // Question
		{ { 1, "Interpreted" }, { 2, "Statically-typed" }, { 3, "Developed by Edwin Catmull" }, { 4, "Has class keyword" } }, // Choices
		2 // Correct choice
		));
	quiz.addQuestion(Question(
		24, // No.
		"Which header contains function for setting console text color?", // Question
		{ { 1, "conio.h" }, { 2, "Winuser.h" }, { 3, "Windows.h" }, { 4, "Wincon.h" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		25, // No.
		"Which operator is a bitwise operator?", // Question
		{ { 1, "||" }, { 2, "<=" }, { 3, "->" }, { 4, ">>" } }, // Choices
		4 // Correct choice
		));

	quiz.run();
	return 0;
}

void setTextColor(int color){
	int newColor;
	newColor |= color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// General function implementation
void moveTo(int x, int y){
	COORD cord = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
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
	line.setColor(TextColor::AQUA);
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

Question::Question(int number, string question, map<int, string> answer, int correct){
	this->number = number;
	this->setQuestion(0, question);
	this->answer = answer;
	this->correctAnswer = correct;
}

Question::Question(int number, vector<string> question, map<int, string> answer, int correct){
	this->number = number;
	int counter = 0;
	for (auto it = question.begin(); it != question.end(); it++){
		this->setQuestion(counter, *it);
		counter++;
	}
	this->answer = answer;
	this->correctAnswer = correct;
}

Question::Question(){

}

void Question::setNumber(int number){
	this->number = number;
}

int Question::getNumber(){
	return this->number;
}

void Question::setQuestion(int line, string question){
	this->question[line] = question;
}

void Question::clearQuestions(){
	this->question.clear();
}

void Question::setAnswer(int choice, string answer){
	this->answer[choice] = answer;
}

void Question::setCorrectAnswer(int choice){
	this->correctAnswer = choice;
}

void Question::clearAnswers(){
	this->answer.clear();
}

string Question::getAnswer(int choice){
	return this->answer[choice];
}

map<int, string> Question::getAnswers(){
	return map<int, string>(this->answer);
}

string Question::getQuestion(int line){
	return this->question[line];
}

map<int, string> Question::getQuestions(){
	return map<int, string>(this->question);
}

int Question::getCorrectAnswer(){
	return this->correctAnswer;
}

bool Question::isCorrect(int choice){
	return this->correctAnswer == choice;
}

void Question::render(){
	int counter = 0, ansCounter = 0;
	for (counter = 0; counter < this->question.size(); counter++){
		moveToWritingPos(5 + counter);
		setTextColor(TextColor::GREEN); cout << (counter == 0 ? to_string(this->number) + ") " : "");
		setTextColor(TextColor::AQUA); cout << this->question[counter];
	}
	setTextColor(TextColor::GOLD);
	for (ansCounter = 0; ansCounter < this->answer.size(); ansCounter++){
		moveToWritingPos(5 + counter + ansCounter, 2);
		cout << ansCounter + 1 << ") " << this->answer[ansCounter + 1];
	}
}

int Question::renderAndGetAnswer(){
	int score = 0;
	int counter = this->question.size(), ansCounter = this->answer.size();
	this->render();
	int answer = this->waitForAnswer(5 + counter + ansCounter + 1);
	moveToWritingPos(5 + counter + ansCounter + 2);
	if (this->isCorrect(answer)){
		score = 1;
		setTextColor(TextColor::GREEN); cout << "Correct!";
	}
	else{
		setTextColor(TextColor::RED); cout << "Incorrect!";
	}
	setTextColor(TextColor::AQUA);
	cout << " Press <Enter> for the next question!";
	cin.ignore();
	cin.get();
	return score;
}

int Question::waitForAnswer(int inputLine){
	moveToWritingPos(inputLine);
	int answer = 1;
	setTextColor(TextColor::GREEN); cout << "Enter your answer: ";
	setTextColor(TextColor::GRAY);
	cin >> answer;
	return answer;
}

int Question::resultPosition(){
	return 5 + this->question.size() + this->answer.size();
}
Quiz::Quiz(){

}

void Quiz::addQuestion(Question q){
	this->questions[q.getNumber()] = q;
}

string Quiz::calculateGrade(){
	double percentage = ((double)this->score / (double)this->fullScore) * 100.0;
	if (percentage >= 90){
		return percentage >= 96 ? "A+" : (percentage >= 93 ? "A" : "A-");
	}
	else if (percentage >= 80){
		return percentage >= 86 ? "B+" : (percentage >= 83 ? "B" : "B-");
	}
	else if (percentage >= 70){
		return percentage >= 76 ? "C+" : (percentage >= 73 ? "C" : "C-");
	}
	else if (percentage >= 60){
		return "D";
	}
	else if (percentage >= 50){
		return percentage > 30 ? "E" : "FF-";
	}
	else{
		return "F";
	}
}

void Quiz::run(){
	clearScreen();
	drawBorder();
	// full score
	this->fullScore = this->questions.size();
	// begin loop
	for (auto it = this->questions.begin(); it != this->questions.end(); it++){
		Question q = it->second;
		this->score += q.renderAndGetAnswer();
		moveToWritingPos(q.resultPosition() + 2);
		clearScreen();
		drawBorder();
	}
	// clear screen
	clearScreen();
	drawBorder();
	moveToWritingPos(5);
	// print result
	setTextColor(TextColor::BLUE);
	cout << "Quiz result";
	moveToWritingPos(6);
	setTextColor(TextColor::GRAY); cout << "Your score: ";
	setTextColor(TextColor::GREEN); cout << this->score << "/" << this->fullScore;
	moveToWritingPos(7);
	setTextColor(TextColor::GRAY); cout << "Your grade: ";
	setTextColor(TextColor::GREEN); cout << this->calculateGrade();
	cin.get();
}
