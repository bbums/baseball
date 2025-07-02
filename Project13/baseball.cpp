#include <string>
#include <stdexcept>

class Baseball {
	bool itHasDup(const std::string& str) {
		for (int c1 = 0; c1 < str.length(); c1++) {
			for (int c2 = c1 + 1; c2 < str.length(); c2++) {
				if (str[c1] == str[c2])
					throw std::invalid_argument("�ȹٷ� �������");
			}
		}
	}
public:
	void guess(const std::string& str) {
		if(str.length() != 3)
			throw std::length_error("Must be three letters.");
		for (char ch1 : str) {
			if (ch1 < '0' || ch1 > '9')
				throw std::invalid_argument("�ȹٷ� ����");
		}
		if(itHasDup(str))
			throw std::invalid_argument("�ȹٷ� �������");
	}
};