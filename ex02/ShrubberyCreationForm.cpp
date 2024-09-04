#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberCreationFrom Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberCreationFrom", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref)
{
	if (this == &ref)
		return (*this);
	this->_target = ref._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;
	std::string		file;

	if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();

	file = this->getTarget() + "_shrubbery";

	outfile.open(file.c_str());
	if (outfile.fail())
	{
		std::cout << LRED << "Could not open file" << RESET << std::endl;
		return;
	}
	outfile << treeAscii;
	outfile.close();
	std::cout << GREEN << executor.getName() << "sucessfully to created a shrubbery" << RESET << std::endl;
 }

std::ostream & operator<<( std::ostream & ostr, ShrubberyCreationForm const & ref ) {
	ostr << GREEN <<ref.getTarget() << "has been signed" << RESET;
	return ostr;
}
