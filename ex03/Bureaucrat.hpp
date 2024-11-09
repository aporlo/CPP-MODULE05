#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

# define LRED	"\033[0;91m"
# define RESET	"\033[0m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"


class AForm;

class Bureaucrat
{
	private:
		std::string		_name;
		unsigned int	_grade;

	public:
		static unsigned int const	lowestGrade = 150;
		static unsigned int const	highestGrade = 1;

		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat(void);

		Bureaucrat  &operator=( const Bureaucrat & ref );

		std::string	getName(void) const;
		unsigned int	getGrade(void) const;

		void	increase(void);
		void	decrease(void);
		void	setGrade(unsigned int grade);
		void	signForm(AForm & form);
		void	executeForm(AForm & form);

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

std::ostream	&operator<<( std::ostream &ostr, const Bureaucrat &ref );

#endif
