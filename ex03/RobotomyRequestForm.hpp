#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);

	std::string		getTarget(void) const;
	void			execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<( std::ostream & ostr, RobotomyRequestForm const & ref);

#endif
