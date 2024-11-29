#pragma once


class Counter {
private:
	int value{};

public:
	Counter(int initial_value = 1);

	void increment();
	void decrement();
	int  get_value() const;
};