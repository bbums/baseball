#include <string>
#include <stdexcept>

class Baseball {
public:
	void guess(const std::string& str) {
		if(str.length() != 3)
			throw std::length_error("Must be three letters.");
		for (int c = 0; c < 3; c++)
			if (str[c] < '0' || str[c] > '9') 
				throw std::invalid_argument("똑바로 던져");
	}
};