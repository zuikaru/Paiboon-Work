#include <iostream>
#include <string>
#include "TextColor.h"
#include "ConsoleSystem.h"
#include "Quiz.h"

using namespace std;

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
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		2, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		3, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		4, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		5, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		6, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		7, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		8, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		9, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		10, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		11, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		12, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		13, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		14, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		15, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		16, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		17, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		18, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		19, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		20, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		21, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		22, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		23, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		24, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));
	quiz.addQuestion(Question(
		25, // No.
		"What is the size of int data type", // Question
		{ { 1, "1 byte" }, { 2, "2 bytes" }, { 3, "4 bytes" }, { 4, "8 bytes" } }, // Choices
		3 // Correct choice
		));

	quiz.run();
	return 0;
}