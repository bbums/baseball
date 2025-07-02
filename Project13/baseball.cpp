#include <string>
#include <stdexcept>

struct GuessResult {
	bool solved = false;
	int strikes = 0;
	int balls = 0;
};

class Baseball {
public:
	bool itHasDup(const std::string& str) {
		for (int c1 = 0; c1 < str.length(); c1++) {
			for (int c2 = c1 + 1; c2 < str.length(); c2++) {
				if (str[c1] == str[c2])
					return true;
			}
		}
		return false;
	}

	GuessResult guess(const std::string& str) {
		GuessResult res = { false, 0, 0 };
		if(str.length() != 3)
			throw std::length_error("Must be three letters.");
		for (char ch : str) {
			if (ch < '0' || ch > '9')
				throw std::invalid_argument("똑바로 던져");
		}
		if(itHasDup(str))
			throw std::invalid_argument("똑바로 던지라고");

		for (int s = 0; s < 3; ++s) {
			for (int a = 0; a < 3; ++a) {
				if (str[s] == answer[a]) {
					if (a == s) res.strikes++;
					else res.balls++;
				}
			}
		}

		if (res.strikes == 3)
			res.solved = true;

		return res;
	}
private:
	std::string answer = "123";
};