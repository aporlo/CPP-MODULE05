#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonFrom", 25, 5), _target("null"){}
PresidentialPardonForm::PresidentialPardonForm(std::string const & target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm::AForm(src), _target(src._target){}

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ref)
{
	if (this == &ref)
		return (*this);
	this->_target = ref._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	std::cout<< *this << std::endl;
}


std::ostream & operator<<( std::ostream & ostr, PresidentialPardonForm const & ref)
{
	ostr << GREEN << ref.getTarget() << "has been pardoned by Aaphod Beeblebrox" << RESET << std::endl;
	return ostr;
}
