#include "linav.h"
#include <iostream>
#include <limits>

/*
 * If Linav v is constructed without
 * any parameter, then v is assumed to be
 * a zero vector in R^2.
 */
anum::Linav::Linav() {
	this->D = 2;
	this->x.push_back(0);
	this->x.push_back(0);
}

/*
 * Declare a null vector
 * in D-dimension
 */
anum::Linav::Linav(unsigned int dimension) {
	for (int i = 0; i < dimension; i++)
		this->x.push_back(0);
	this->D = dimension;
}

/*
 * Declare the vector x = (x1, x2, ..., xn);
 */
anum::Linav::Linav(std::vector<double> v) {
	this->D = v.size();
	std::vector<double>::const_iterator itr_v = v.begin();
	for (int i = 0; i < D; i++) {
		this->x.push_back(*itr_v);
		++itr_v;
	}
}

// get the ith-value of x
double anum::Linav::accs(unsigned int ith_position) {
	double ith_comp;
	try {
		ith_comp = this->x.at(ith_position);
	} catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range Error Occurs: " << oor.what() << ' ';
		std::cerr << "the avaiable indexes are 0-" << D - 1 << '\n';
	}
	return ith_comp;
}

// change the ith_component/element of vector
void anum::Linav::updt(unsigned int ith_position, double val) {
	try {
		this->x.at(ith_position) = val;
	} catch(const std::out_of_range& oor) {
		std::cerr << "Out of Range Error Occurs: " << oor.what() << ' ';
		std::cerr << "the avaiable indexes are 0-" << D - 1 << '\n';
	}
}

unsigned int anum::Linav::get_dim() { return this->D; } // get the dimension of x

// pointwsie addition
anum::Linav anum::Linav::operator+(Linav rhs) {
	std::vector<double> v;
	try {
		// check the criteria of adding two vectors, if two vectors
		// have different dimension each other, then domain error
		// will be catched.
		if (D != rhs.get_dim())
			throw std::domain_error("cannot add two vectors having different dimension\n");
		for (int ith = 0; ith < D; ith++) {
			double temp = x.at(ith) + rhs.accs(ith);
			v.push_back(temp);
		}
	} catch (const std::domain_error& doerr) {
		std::cerr << "Domain Error Occurs: " << doerr.what();
	}
	Linav C(v); // create a new instance of vector C
	return C;
}

// s-multiplication
/*
Linav Linav::operator*(double rhs) {
	std::vector<double> v;
	for (int ith = 0; ith < D; ith++) {
		double temp = rhs * x.at(ith);
		v.push_back(temp);
	}
	Linav V(v);
	return V;
}
*/
// pointwise multiplication
anum::Linav anum::Linav::operator*(Linav rhs) {
	std::vector<double> v;
	try {
		// check the criteria of performing pointwise multiplication of two vectors.
		// If two vectors have different dimension, then terminate the program.
		if (D != rhs.get_dim())
			throw std::domain_error("cannot do pointwise multiplication of two vectors having different dimension\n");
		for (int ith = 0; ith < D; ith++) {
			double temp = x.at(ith) * rhs.accs(ith);
			v.push_back(temp);
		}
	} catch (const std::domain_error &doerr) {
		std::cerr << "Domain Error Occurs: " << doerr.what(); 
	}
	
	Linav V(v);
	return V;
}

// pointwise substraction
anum::Linav anum::Linav::operator-(Linav rhs) {
	std::vector<double> v;
	try {
		// check the criteria of performing pointwise substraction of two vectors.
		// If two vectors have different dimension, then domain error will be catched.
		if (D != rhs.get_dim())
			throw std::domain_error("cannot substract two vectors having different dimension\n");
		for (int ith = 0; ith < D; ith++) {
			double temp = x.at(ith) - rhs.accs(ith);
			v.push_back(temp);
		}
	} catch (const std::domain_error &doerr) {
		std::cerr << "Domain Error Occurs: " << doerr.what();
	}
	Linav V(v);
	return V;
}
