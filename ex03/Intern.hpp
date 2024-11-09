#ifndef INTERN_HPP
# define INTERN_HPP

#include <isostream>
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

		Form *makeForm(const std::string form, const std::string target);
};


