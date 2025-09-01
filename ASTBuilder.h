#pragma once
#include "Token.h"
#include <vector>

using namespace std;

class ASTBuilder
{
	const vector<Token> tokens;

public:

	ASTBuilder(const vector<Token>& t)
		: tokens(t)
	{
	}
};