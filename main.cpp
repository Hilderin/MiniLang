#include <iostream>
#include <vector>
#include <string>
#include "Lexer.h"
#include "ASTBuilder.h"

using namespace std;


// Function to print all tokens
void printTokens(const vector<Token>& tokens)
{
    for (const auto& token : tokens)
    {
        cout << "Type: " << Token::getTokenTypeName(token.type)
            << ", Value: " << token.value
            << ", Line: " << token.lineNumber
            << ", Loc: " << token.location
            << endl;
    }
}

int main()
{
    
    // Sample source code to be analyzed
    string sourceCode
        = "int main() { float x = 3.14; float y=3.15;\n "
        "float z=x+y; return 0; }";

    // Create a Lexer object
    Lexer lexer(sourceCode);

    // Tokenize the source code
    vector<Token> tokens = lexer.tokenize();

    // Abstract Synthax Tree Builder
    ASTBuilder builder(tokens);



    // Print the original source code
    cout << "Source code: " << sourceCode << endl << endl;

    // Print all identified tokens
    cout << "Tokens Generate by Lexical Analyzer:" << endl;
    printTokens(tokens);


    return EXIT_SUCCESS;
}
