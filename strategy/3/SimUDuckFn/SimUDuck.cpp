#include "lib/Duck/DecoyDuck.h"
#include "lib/Duck/MallardDuck.h"
#include "lib/Duck/ModelDuck.h"
#include "lib/Duck/RedheadDuck.h"
#include "lib/Duck/RubberDuck.h"
#include "lib/DuckFunctions.h"
#include <cstdlib>

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(FlyWithWings());
	modelDuck.SetDanceBehavior(DanceAMinuet);
	PlayWithDuck(modelDuck);


	modelDuck.Fly();
	modelDuck.Fly();
	modelDuck.Fly();
	modelDuck.SetFlyBehavior(FlyNoWay);
	modelDuck.Fly();
	modelDuck.SetFlyBehavior(FlyWithWings());
	modelDuck.Fly();

	return EXIT_SUCCESS;
}