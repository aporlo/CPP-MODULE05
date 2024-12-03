#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
	/* data */
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern &operator=(const Intern & ref);

		AForm *makeForm(const std::string form, const std::string target);
};

#endif

