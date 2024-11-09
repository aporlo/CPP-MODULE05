#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, unsigned int grade): _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Constructor for Bureaucrat called" << std::endl;
};

Bureaucrat::Bureaucrat( Bureaucrat const & src)
{
	std::cout << "Copy constructor for Bureaucrat called" << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor for Bureaucrat called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & ref)
{
	std::cout << "Assignement operator for Bureaucrat called" << std::endl;
	if (this == &ref)
		return (*this);
	this->_grade = ref.getGrade();
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::decrease()
{
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::increase()
{
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::setGrade(unsigned int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;

	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the lowest grade is " << form.getSignGrade() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't executed " << form.getName() << std::endl;
	}

}
std::ostream & operator<<( std::ostream & ostr, Bureaucrat const & ref ) {
	ostr << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return ostr;
}
