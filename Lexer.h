#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Token.h"

using namespace std;

// Class that implements the lexical analyzer
class Lexer
{
private:
    string input;
    size_t position;
    size_t lineNumber;
    size_t startPosition;
    unordered_map<string, TokenType> keywords;

    // Function to initialize the keywords map
    void initKeywords();

    // Function to check if a character is whitespace
    bool isWhitespace(char c);

    // Function to check if a character is a new line
    bool isNewLine(char c);

    // Function to check if a character is alphabetic
    bool isAlpha(char c);

    // Function to check if a character is a digit
    bool isDigit(char c) { return c >= '0' && c <= '9'; }

    // Function to check if a character is alphanumeric
    bool isAlphaNumeric(char c)
    {
        return isAlpha(c) || isDigit(c);
    }

    // Function to get the next word (identifier or keyword)
    // from the input
    string getNextWord();

    // Function to get the next number (integer or float)
    // from the input
    string getNextNumber();

public:
    // Constructor for LexicalAnalyzer
    Lexer(const string& source)
        : input(source)
        , position(0)
        , lineNumber(1)
        , startPosition(0)
    {
        initKeywords();
    }

    // Function to tokenize the input string
    vector<Token> tokenize();
};