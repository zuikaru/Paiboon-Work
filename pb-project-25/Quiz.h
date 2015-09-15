#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

class Question{
private: map<int,string> question;
		 map<int,string> answer;
		 int correctAnswer;
		 int number;
public: Question(int number,string question,map<int,string> answer,int correct);
		Question();
		void setQuestion(int line,string question);
		void setNumber(int number);
		void clearQuestions();
		void setAnswer(int choice,string answer);
		void setCorrectAnswer(int choice);
		void clearAnswers();
		int renderAndGetAnswer();
		int waitForAnswer(int intputLine);
		string getAnswer(int choice);
		map<int,string> getAnswers();
		string getQuestion(int line);
		map<int,string> getQuestions();
		int getCorrectAnswer();
		int getNumber();
		int resultPosition();
		bool isCorrect(int choice);
		void render();
};

class Quiz{
private: map<int, Question> questions = map<int,Question>();
		 int score = 0;
		 int fullScore = 0;
public: Quiz();
		void addQuestion(Question &question);
		void run();
		string calculateGrade();
};