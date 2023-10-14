#pragma once
#include <iostream>
#include <string>

enum class Token
{
    kNone = 0,
    kLeftBrace,
    kRightBrace,
    kComma,
    kLeftBracket,
    kRightBracket,
    kColon,
    kString,
    kNumber,
    kTrue,
    kFalse,
    kNull,
    kInvalid
};

struct StreamPosition
{
    uint32_t position_;
    uint32_t line_;
    uint32_t column_;
};

/// @brief This class is responsible for parsing the input stream
/// and generating tokens according to the JSON grammar
class TokenGenerator
{
    public:
        TokenGenerator(): 
            current_token_{Token::kNone}, stream_position_{0, 0, 0} 
        {}

        Token GetNextToken(std::wistream& input_stream);

        Token PeekNextToken(std::wistream& input_stream);

        StreamPosition GetStreamPosition() { return stream_position_; }

    private:
        // bool IsWhiteSpace(wchar_t input_char);
        // bool IsSyntaxSeparator(wchar_t input_char);
        // bool IsStringDelimiter(wchar_t input_char);
        // bool IsStringCharacter(wchar_t input_char);
        // bool IsNumberCharacter(wchar_t input_char);
        std::wstring token_buffer_;
        Token current_token_;
        StreamPosition stream_position_;
};