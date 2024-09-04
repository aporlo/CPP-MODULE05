#include "Form.hpp"

Form::Form(std::string name, int signedGrade, int execGrade): _name(name), _signed(false), _signGrade(signedGrade), _execGrade(execGrade) {
	if (this->_signGrade < Form::highestGrade || this->_execGrade < Form::highestGrade)
		throw Form::GradeTooHighException();
	if (this->_signGrade > Form::lowestGrade || this->_execGrade > Form::lowestGrade)
		throw Form::GradeTooLowException();
};


Form::Form(Form const & src): _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

Form & Form::operator=(Form const & ref) {
	if (this == &ref)
		return *this;
	this->_signed = ref._signed;
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const {
	return this->_name;
}
bool	Form::isSigned() const {
	return this->_signed;
}
unsigned int	Form::getSignGrade() const {
	return this->_signGrade;
}
unsigned int	Form::getExecGrade() const {
	return this->_execGrade;
}

std::ostream & operator<<( std::ostream & ostr, Form const & ref ) {
	ostr << ref.getName() << "-Form: " << ref.getSignGrade() << "<" << ref.getExecGrade();
	if (ref.isSigned())
		ostr << GREEN << " [OK]" << RESET;
	else
		ostr << LRED << " [NO]" << RESET;
	return ostr;
}


void	Form::beSigned(Bureaucrat const & bur) {
	if (bur.getGrade() < this->getSignGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}
