#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), std::length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12s")), std::invalid_argument);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidCase) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("121")), std::invalid_argument);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}