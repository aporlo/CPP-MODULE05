#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Copy constructor for Intern called" << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const &ref)
{
	(void) ref;
	return (*this);
}

AForm	*Intern::makeForm(const std::string form_create, const std::string target_form)
{
	AForm *all_forms[3] = {new PresidentialPardonForm(target_form), new RobotomyRequestForm(target_form) , new ShrubberyCreationForm(target_form)};
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (form_create == forms[i])
		{
			std::cout << GREEN << "Intern creates" << form_create << RESET << std::endl;
			for (int j = 0; j < 3; j++) {
				if (j != i) {
					delete all_forms[j];
				}
			}
			return (all_forms[i]);
		}
	}
	for (int i = 0; i < 3; i++) {delete all_forms[i];}
	std::cout << LRED << "Intern can't create a form called" << form_create << RESET << std::endl;
	return (NULL);
}
