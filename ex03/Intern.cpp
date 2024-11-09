#include "Intern.cpp"


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

Intern::~Intern(){}

Intern & Intern::operator=(Intern const &ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AFrom	*Intern::makeForm(const std::string form_create, const std::string target_form)
{
	AForm *(*allForms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3, i++)
	{
		if (form_create == forms[i])
		{
			std::cout << "Intern creates" << form_create << std::endl;
			return (allForms[i](target_form));
		}
	}
	std::cout << LRED << "Intern can't create a form called" << form_create << RESET << std::endl;
	return (NULL);
}
