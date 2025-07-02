#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), std::length_error);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}