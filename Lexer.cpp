#include "Lexer.h"

void Lexer::initKeywords()
{
    keywords["int"] = TokenType::KEYWORD;
    keywords["float"] = TokenType::KEYWORD;
    keywords["if"] = TokenType::KEYWORD;
    keywords["else"] = TokenType::KEYWORD;
    keywords["while"] = TokenType::KEYWORD;
    keywords["return"] = TokenType::KEYWORD;
}

// Function to check if a character is whitespace
inline bool Lexer::isWhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Function to check if a character is a new line
inline bool Lexer::isNewLine(char c)
{
    return c == '\n';
}

// Function to check if a character is alphabetic
inline bool Lexer::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z');
}

// Function to get the next word (identifier or keyword)
// from the input
string Lexer::getNextWord()
{
    size_t start = position;
    while (position < input.length() && isAlphaNumeric(input[position]))
    {
        position++;
    }
    return input.substr(start, position - start);
}

// Function to get the next number (integer or float)
// from the input
string Lexer::getNextNumber()
{
    size_t start = position;
    bool hasDecimal = false;
    while (position < input.length()
        && (isDigit(input[position])
            || input[position] == '.'))
    {
        if (input[position] == '.')
        {
            if (hasDecimal)
                break;
            hasDecimal = true;
        }
        position++;
    }
    return input.substr(start, position - start);
}

// Function to tokenize the input string
vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;

    while (position < input.length())
    {
        char currentChar = input[position];

        // Skip whitespace
        if (isNewLine(currentChar))
        {
            position++;
            lineNumber++;
            startPosition = position;
            continue;
        }
        else if (isWhitespace(currentChar))
        {
            position++;            
            continue;
        }

        

        // Identify keywords or identifiers
        if (isAlpha(currentChar))
        {
            string word = getNextWord();
            if (keywords.find(word) != keywords.end())
            {
                tokens.emplace_back(TokenType::KEYWORD, word, lineNumber, position - startPosition + 1);
            }
            else
            {
                tokens.emplace_back(TokenType::IDENTIFIER, word, lineNumber, position - startPosition + 1);
            }
        }
        // Identify integer or float literals
        else if (isDigit(currentChar))
        {
            string number = getNextNumber();
            if (number.find('.') != string::npos)
            {
                tokens.emplace_back(TokenType::FLOAT_LITERAL, number, lineNumber, position - startPosition + 1);
            }
            else
            {
                tokens.emplace_back(TokenType::INTEGER_LITERAL, number, lineNumber, position - startPosition + 1);
            }
        }
        // Identify operators
        else if (currentChar == '+'
            || currentChar == '-'
            || currentChar == '*'
            || currentChar == '/')
        {
            tokens.emplace_back(TokenType::OPERATOR, string(1, currentChar), lineNumber, position - startPosition + 1);
            position++;
        }
        // Identify punctuators
        else if (currentChar == '('
            || currentChar == ')'
            || currentChar == '{'
            || currentChar == '}'
            || currentChar == ';')
        {
            tokens.emplace_back(TokenType::PUNCTUATOR, string(1, currentChar), lineNumber, position - startPosition + 1);
            position++;
        }
        // Handle unknown characters
        else
        {
            tokens.emplace_back(TokenType::UNKNOWN, string(1, currentChar), lineNumber, position - startPosition + 1);
            position++;
        }
    }

    return tokens;
}
