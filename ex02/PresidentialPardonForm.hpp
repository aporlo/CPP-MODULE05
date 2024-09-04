#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;


class PresidentialPardonForm: public AForm
{
private:
	std::string		_target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);

	std::string		getTarget(void) const;
	void execute(Bureaucrat const &Bureaucrat) const;
};

std::ostream & operator<<( std::ostream & ostr, PresidentialPardonForm const & ref);

#endif
