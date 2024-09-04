#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	aporlo("Aporlo", 5);
	Bureaucrat	guppom("Guppom", 150);
	Form	form("Form", 20, 45);


	/*Create a form with incorect grade : with grade too low*/
	try
	{
		Form form4("f4", 100, 160);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/*SignForm: Aporlo sign F1 */
	try
	{
		aporlo.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/*BeSigned: aporlo sign F2 */
	try
	{
		guppom.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
