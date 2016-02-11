#include "BuildingStates.h"

/////////////////////////////// PRODUCING HERO ///////////////////////////////

ProducingHero * ProducingHero::Instance()
{
	static ProducingHero instance;
	return &instance;
}

void ProducingHero::Enter(Building * owner)
{
	std::cout << "Entered producing hero state" << std::endl;
}

void ProducingHero::Execute(Building * owner)
{

}

void ProducingHero::Exit(Building * owner)
{
	std::cout << "Exited producing hero state" << std::endl;
}