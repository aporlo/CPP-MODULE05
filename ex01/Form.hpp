#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:
		std::string const	_name;
		bool	_signed;
		int const	_signGrade;
		int const	_execGrade;

	public:
		static int const	lowestGrade = 150;
		static int const	highestGrade = 1;

		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & src);
		~Form(void);

		Form &operator=(Form const &ref );

		std::string		getName(void) const;
		bool			isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		void	beSigned(Bureaucrat const & bur);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade too low");
				}
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The grade too high");
				}
		};
};

std::ostream	&operator<<( std::ostream &ostr, Form const & ref );

#endif
