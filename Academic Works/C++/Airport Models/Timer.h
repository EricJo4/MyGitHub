/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 22 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>

namespace sdds {
	class Timer {
		std::chrono::time_point<std::chrono::steady_clock> start_time;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H