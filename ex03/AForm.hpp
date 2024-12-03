#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	private:
		std::string const	_name;
		bool	_signed;
		int const	_signGrade;
		int const	_execGrade;

	public:
		static int const	lowestGrade = 150;
		static int const	highestGrade = 1;

		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & src);
		virtual ~AForm(void);

		AForm &operator=(AForm const &ref );

		std::string		getName(void) const;
		bool			isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		void	beSigned(Bureaucrat const & bur);
		virtual	void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator<<( std::ostream &ostr, AForm const & ref );

#endif
