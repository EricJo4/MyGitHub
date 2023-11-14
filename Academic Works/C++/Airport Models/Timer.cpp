/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 22 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Timer.h"

namespace sdds {
	void Timer::start() {
		start_time = std::chrono::steady_clock::now();
	}
	long long Timer::stop() {
		auto end_time = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
	}
}