#include <iostream>
#include <string>
#include <vector>
#include "Quiz.h"
#include "ConsoleSystem.h"
#include "TextColor.h"

using namespace std;

Question::Question(int number,string question, map<int,string> answer, int correct){
	this->number = number;
	this->setQuestion(0, question);
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

map<int,string> Question::getAnswers(){
	return map<int,string>(this->answer);
}

string Question::getQuestion(int line){
	return this->question[line];
}

map<int,string> Question::getQuestions(){
	return map<int,string>(this->question);
}

int Question::getCorrectAnswer(){
	return this->correctAnswer;
}

bool Question::isCorrect(int choice){
	return this->correctAnswer == choice;
}

void Question::render(){
	int counter = 0,ansCounter = 0;
	for (counter = 0; counter < this->question.size(); counter++){
		moveToWritingPos(5 + counter);
		setTextColor(TextColor::GREEN); cout << (counter == 0 ? to_string(this->number) + ") " : "");
		setTextColor(TextColor::AQUA); cout << this->question[counter];
	}
	setTextColor(TextColor::GOLD);
	for (ansCounter = 0; ansCounter < this->answer.size(); ansCounter++){
		moveToWritingPos(5 + counter + ansCounter,2);
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

void Quiz::addQuestion(Question &q){
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
		return "E";
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
		moveToWritingPos(q.resultPosition() +  2);
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