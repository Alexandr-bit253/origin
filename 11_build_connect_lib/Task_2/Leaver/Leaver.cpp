#include <iostream>

#include "Leaver.h"


namespace Leaver {
	void Leaver::leave(std::string& const s) {
		std::cout << "До свидания, " << s << "!\n";
	}
}