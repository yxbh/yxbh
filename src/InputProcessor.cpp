//================================================
// InputProcessor Class implementation v1.0
//================================================
#include "InputProcessor.h"
// debug
using std::cout;
using std::endl;
// /debug

//================================================
// getInput()
//================================================
InputProcessor & InputProcessor::getInput(istream & is)
{
	getline(is, input);
	return *this;
}

//================================================
// break input down into individual words
//================================================
InputProcessor & InputProcessor::processInputC(char ch_token)
{
	int inputSize = input.length();
	string str_buf = "";
	int n = 0;
	while (n < inputSize)
	{
		for (; n < inputSize && input[n] != ch_token; n++)
		{
			str_buf += input[n];
		}
		wordList.push_back(str_buf);
		str_buf = "";
		n++;
	}
	wordListSize = wordList.size();
	return *this;
}

//================================================
// returns a copy word list in vector<string> format
//================================================
const vector<string> InputProcessor::getWordList(void)
{
	return wordList;
}