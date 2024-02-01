#include "Harl.hpp"

int main (void)
{
	Harl harl;

	harl.complain("debug");
	harl.complain("warning");
	harl.complain("error");
	harl.complain("info");
	harl.complain("random");
	return (0);
}
