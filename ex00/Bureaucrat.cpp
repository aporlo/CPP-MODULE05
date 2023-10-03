#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ): _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src)
{
	std::cout <<"Copy constructor for Bureaucrat called" << std::endl;
	*this = src;
	return;
}
