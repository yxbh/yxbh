//================================================
//
//	InputProcessor Class v1.0
//		for getting console string input from user
//		and processing it into individual words
//
//================================================
#ifndef _INPUTPROCESSOR_H_
#define _INPUTPROCESSOR_H_
#include <string>
using std::string;
using std::wstring;
#include <vector>
using std::vector;
#include <iostream>
using std::istream;
using std::cin;

class InputProcessor
{
private:
	string input;				// the string user input
	vector<string> wordList;	// input broken input its individual words
	int wordListSize;			// size of the wordList
public:
	InputProcessor()
		: input(""), wordListSize(0) {}
	~InputProcessor()
	{}
	// obtain input string from user
	InputProcessor & getInput(istream & is = cin);
	// break input down into individual words using a single char token
	InputProcessor & processInputC(char ch_token = ' ');
	// break input down into individual words using a string of tokens
	InputProcessor & processInputS(string tokens = " \t");
	// get input and then immediately process the input string and return the wordList
	const vector<string> opC(char ch_token = ' ')
	{
		getInput();
		processInputC(ch_token);
		return getWordList();
	}
	// get input and then immediately process the input string and return the wordList
	const vector<string> opS(string tokens = " \t")
	{
		getInput();
		processInputS(tokens);
		return getWordList();
	}
	// returns a copy word list in vector<string> format
	const vector<string> getWordList(void);
	// number of words in wordList
	const int wordCount(void)
	{
		return wordListSize;
	}
};


#endif

