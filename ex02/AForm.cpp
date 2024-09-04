#include "AForm.hpp"

AForm::AForm(std::string name, int signedGrade, int execGrade): _name(name), _signed(false), _signGrade(signedGrade), _execGrade(execGrade) {
	if (this->_signGrade < AForm::highestGrade || this->_execGrade < AForm::highestGrade)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > AForm::lowestGrade || this->_execGrade > AForm::lowestGrade)
		throw AForm::GradeTooLowException();
};


AForm::AForm(AForm const & src): _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

AForm & AForm::operator=(AForm const & ref) {
	if (this == &ref)
		return *this;
	this->_signed = ref._signed;
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const {
	return this->_name;
}
bool	AForm::isSigned() const {
	return this->_signed;
}
unsigned int	AForm::getSignGrade() const {
	return this->_signGrade;
}
unsigned int	AForm::getExecGrade() const {
	return this->_execGrade;
}

std::ostream & operator<<( std::ostream & ostr, AForm const & ref ) {
	ostr << ref.getName() << "-Form: " << ref.getSignGrade() << "<" << ref.getExecGrade();
	if (ref.isSigned())
		ostr << GREEN << " [OK]" << RESET;
	else
		ostr << LRED << " [NO]" << RESET;
	return ostr;
}


void	AForm::beSigned(Bureaucrat const & bur) {
	if (bur.getGrade() < this->getSignGrade())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}


