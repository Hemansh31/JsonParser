#include <gtest/gtest.h>
#include <string>
#include "token_generator.h"
#include "cstdlib"

class TokenGeneratorTest : public testing::TestWithParam<std::pair<std::wstring, std::vector<Token> > >
{
    protected:
        void SetUp() override
        {
            std::pair<std::wstring, std::vector<Token>> input_param = GetParam();
            retrieved_token_list_ = input_param.second;
            string_stream_.str(input_param.first);
        }

        TokenGenerator token_generator_;
        std::wistringstream string_stream_;
        std::vector<Token> retrieved_token_list_;
};

TEST_P(TokenGeneratorTest, GetNextToken)
{
    for(auto& token : retrieved_token_list_)
    {
        EXPECT_EQ(token_generator_.GetNextToken(string_stream_), token);
    }
}

TEST_P(TokenGeneratorTest, PeekNextToken)
{
    for(auto& token : retrieved_token_list_)
    {
        int random_integer = 1 + (rand() % 10);
        for (int i = 0; i < random_integer; i++)
        {
            EXPECT_EQ(token_generator_.PeekNextToken(string_stream_), token);
        }
        token_generator_.GetNextToken(string_stream_);
    }
}

INSTANTIATE_TEST_SUITE_P(TestTokenGeneratorMethods,
                        TokenGeneratorTest,
                        testing::Values(
                            std::make_pair(L"{}", std::vector<Token> {Token::kLeftBrace, Token::kRightBrace}),
                            std::make_pair(L"", std::vector<Token> {Token::kNone, Token::kNone}),
                            std::make_pair(L"{\"}", std::vector<Token> {Token::kLeftBrace, Token::kInvalid, Token::kInvalid})
                        ));