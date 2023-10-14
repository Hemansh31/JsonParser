#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <vector>
#include "token_generator.h"
#include "token_parser.h"
#include "cstdlib"

class TokenParserAddTokenTest : public testing::TestWithParam<std::pair<std::vector<Token>, std::vector<uint32_t>>>
{
    protected:
        void SetUp() override
        {
            std::pair<std::vector<Token>, std::vector<uint32_t>> input_param = GetParam();
            add_token_list_ = input_param.first;
            retrieved_exit_code_list_ = input_param.second;
        }

        TokenParser token_parser_;
        std::vector<Token> add_token_list_;
        std::vector<uint32_t> retrieved_exit_code_list_;
};

class TokenParserGetExpectedTokenTest : public testing::TestWithParam<std::pair<std::vector<Token>, std::vector<Token> > >
{
    protected:
        void SetUp() override
        {
            std::pair<std::vector<Token>, std::vector<Token>> input_param = GetParam();
            add_token_list_ = input_param.first;
            retrieved_expected_token_list_ = input_param.second;
        }

        TokenParser token_parser_;
        std::vector<Token> add_token_list_;
        std::vector<Token> retrieved_expected_token_list_;
};

TEST_P(TokenParserAddTokenTest, AddToken)
{
    EXPECT_EQ(add_token_list_.size(), retrieved_exit_code_list_.size());
    for(int i = 0; i < add_token_list_.size(); i++)
    {
        EXPECT_EQ(token_parser_.AddToken(add_token_list_[i]), retrieved_exit_code_list_[i]);
    }
}

TEST_P(TokenParserGetExpectedTokenTest, GetExpectedTokens)
{
    for(int i = 0; i < add_token_list_.size(); i++)
    {
        token_parser_.AddToken(add_token_list_[i]);
    }
    auto expected_token_list = token_parser_.GetExpectedTokens();
    EXPECT_EQ(expected_token_list.size(), retrieved_expected_token_list_.size());
    for (auto token : retrieved_expected_token_list_)
    {
        EXPECT_THAT(expected_token_list, testing::Contains(token));
    }
}

INSTANTIATE_TEST_SUITE_P(TestTokenParserAddToken,
                        TokenParserAddTokenTest,
                        testing::Values(
                            std::make_pair(std::vector<Token> {Token::kLeftBrace, Token::kRightBrace}, std::vector<uint32_t> {0, 0})
                        ));

INSTANTIATE_TEST_SUITE_P(TestTokenParserGetExpectedToken,
                        TokenParserGetExpectedTokenTest,
                        testing::Values(
                            std::make_pair(std::vector<Token> {Token::kLeftBrace, Token::kString, }, std::vector<Token> {Token::kColon}),
                            std::make_pair(std::vector<Token> {Token::kLeftBrace, Token::kString, Token::kColon, Token::kString}, std::vector<Token> {Token::kComma, Token::kRightBrace})
                        ));