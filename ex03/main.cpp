#include "Bureaucrat.hpp"
// #include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
		Intern	somRandomIntern;
		AForm*	rrf;
		AForm*	rrr;

		rrf = somRandomIntern.makeForm("robotomy request", "Bender");
		rrr = somRandomIntern.makeForm("presidential p pardon", "Aporlo");
		std::cout << *rrf << std::endl;

		Bureaucrat	a = Bureaucrat("A", 1);
		a.signForm(*rrf);
		a.executeForm(*rrf);

		rrf->execute(a);

		std::cout << *rrf << std::endl;
		std::cout << a << std::endl;

		delete rrr;
		delete rrf;

	return 0;
}
