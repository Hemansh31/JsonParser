#include "token_generator.h"

/// @brief Takes input from the stream and checks if it either
/// a valid JSON string, null, true, false, number or a separator
/// and in case of failure of any validation prints error. In case of
/// validation errors any subsequent calls to this function will return
/// the same error i.e the stream will not move ahead.
/// @param input_stream 
/// @return
///     kNone - If EOF is reached,
///     kInvalid - If validation of stream fails,
///     other valid token types based on the input stream
Token
TokenGenerator::GetNextToken(std::wistream& input_stream)
{
    return Token::kInvalid;
}

/// @brief Does the same thing as GetNextToken function expect of 
/// not printing any validation errors and not moving ahead the input stream
/// @param input_stream 
/// @return
///     kNone - If EOF is reached,
///     kInvalid - If validation of stream fails,
///     other valid token types based on the input stream
Token
TokenGenerator::PeekNextToken(std::wistream& input_stream)
{
    return Token::kInvalid;
}