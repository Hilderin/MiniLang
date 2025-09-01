#pragma once

#include <string>
#include <vector>

using namespace std;

// Enum class to define different types of tokens
enum class TokenType
{
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    OPERATOR,
    PUNCTUATOR,
    UNKNOWN
};

// Struct to represent a token with its type and value
struct Token
{
    TokenType type;
    string value;
    size_t lineNumber;
    size_t location;

    Token(TokenType t, const string& v, size_t ln, size_t loc)
        : type(t)
        , value(v)
        , lineNumber(ln)
        , location(loc)
    {
    }

    // Function to convert TokenType to string for printing
    static string getTokenTypeName(TokenType type);
};