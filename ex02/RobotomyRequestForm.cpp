#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm::AForm(src), _target(src._target){}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	if (this == &ref)
		return (*this);
	this->_target = ref._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

std::ostream & operator <<( std::ostream & ostr, RobotomyRequestForm const & ref)
{
	ostr << GREEN << ref.getTarget() << "has been signed" << RESET;
	return ostr;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	srand(time(NULL));
	if ( rand() % 2 == 0)
		std::cout << *this << std::endl;
	else
		std::cout << LRED << "failed to robotomy to"	<< executor.getName() << RESET << std::endl;

}
