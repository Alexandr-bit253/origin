#include "Counter.h"


Counter::Counter(int initial_value) : value(initial_value) {}


void Counter::increment() {
	++value;
}


void Counter::decrement() {
	--value;
}


int Counter::get_value() const {
	return value;
}