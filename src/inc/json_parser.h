#pragma once
#include "token_generator.h"
#include "token_parser.h"

class JsonParser
{
    public:
        JsonParser(): token_analyzer_{}, token_parser_{} {}
        
        uint32_t ParseInputStream(std::wistream& input_stream);
    
    private:
        TokenGenerator token_analyzer_;
        TokenParser token_parser_;
};