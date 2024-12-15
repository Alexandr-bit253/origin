#include <iostream>

#include "Greeter.h"


namespace Greeter {
	void Greeter::hello(std::string& const s) {
		std::cout << "Здравствуйте, " << s << "!\n";
	}
}