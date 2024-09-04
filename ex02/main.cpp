#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	ShrubberyCreationForm shrub("shrub");
	RobotomyRequestForm	robot("robot");
	PresidentialPardonForm pardon("pardon");
	Bureaucrat a("A", 25);
	Bureaucrat b("B", 72);
	Bureaucrat c("C", 145);
	{
		try
		{
			std::cout<< a << std::endl;
			std:: cout<< shrub << std::endl;
			std:: cout<< pardon << std::endl;
			c.executeForm(shrub);
			b.executeForm(robot);
			a.executeForm(pardon);
			std::cout<< a << std::endl;
			std::cout<< b << std::endl;
			std::cout<< c << std::endl;
			std:: cout<< shrub << std::endl;
			std:: cout<< pardon << std::endl;
			std::cout <<"..................1.............\n\n";

			shrub.beSigned(b);
			a.executeForm(shrub);

			std::cout <<"..................2.............\n\n";
			robot.beSigned(c);
			pardon.beSigned(c);
			c.executeForm(shrub);
			std::cout <<"...................4............\n\n";
			c.executeForm(robot);
			std::cout <<"....................5...........\n\n";
			c.executeForm(pardon);

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	return 0;
}
