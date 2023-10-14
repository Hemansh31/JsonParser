#pragma once

#include <vector>
#include<deque>
#include "token_generator.h"

/// @brief This class is responsible for validating that the tokens provided
/// generate a valid JSON according to the JSON grammar.
class TokenParser
{
    public:
        TokenParser(): all_tokens_stack_{}, brace_tokens_stack_{}, is_parsed_json_valid{true} {}

        uint32_t AddToken(Token token);

        std::vector<Token> GetExpectedTokens();

    private:
        bool is_parsed_json_valid;
        std::deque<Token> all_tokens_stack_;
        std::deque<Token> brace_tokens_stack_;
};