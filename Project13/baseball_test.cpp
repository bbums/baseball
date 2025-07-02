#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

class BaseballGameFixture : public Test {
public:
	Baseball game;
	void assertIllegalArgument(std::string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception e) {
		}
	}
};

TEST_F(BaseballGameFixture, ThrowExceptionWhenInputLengthIsUnmatched) {
	assertIllegalArgument(std::string("12"));
}

TEST_F(BaseballGameFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument(std::string("12s"));
	assertIllegalArgument(std::string("121"));
}

TEST_F(BaseballGameFixture, SuccessCase) {
	GuessResult result = game.guess(std::string("123"));

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}