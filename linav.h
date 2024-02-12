#ifndef LINAV_H
#define LINAV_H

#include <vector>
#include <string>

namespace anum {
	// Linav stand for Linear algebra vector
	// All method of Linav instance is in linav.cpp file.
	class Linav {
		std::vector<double> x;
		unsigned int D; // dimension
		public:
			Linav(); // default constructor, return a null vector in 2-dimension
			Linav(unsigned int dimension); // return a null vector in d-dimension
			Linav(std::vector<double>);
			double accs(unsigned int ith_position); // get the ith-value of x
			void updt(unsigned int ith_position, double); // change the ith_componenth of vector
			unsigned int get_dim();
			Linav operator +(Linav rhs); // pointwise addition
			Linav operator -(Linav rhs); // pointwise substraction
			Linav operator*(Linav rhs);
	};

	// All of these void functions are in printprog.cpp
	void print(Linav);
	void println(Linav);
	void print(Linav, std::string sentence);
	void println(Linav, std::string sentence);
	void print(std::string sentence, Linav);
	void println(std::string sentence, Linav);
	void print(double);
	void println(double);
	void print(double, std::string sentence);
	void println(double, std::string sentence);
	void print(std::string sentence, double);
	void println(std::string sentence, double);
	void print(std::string sentence);
	void println(std::string sentence);

	// All of these linear operators are in linop.cpp file
	Linav operator*(double, Linav);
	Linav operator*(Linav, double);
	Linav abs(Linav);
	double sum(Linav); // the Kahan's sum
	Linav power(Linav, double); // the pointwise power
	double lpnorm(Linav, double p); // the lpnorm
	double eunorm(Linav); // the Euclidean norm
	double inpro(Linav, Linav); // the inner product
	double distance(Linav, Linav); // the Euclidean distance of two vector
	Linav normalize(Linav); // compute the normalize vector, i.e. vector which has eunorm is one.
}

#endif
