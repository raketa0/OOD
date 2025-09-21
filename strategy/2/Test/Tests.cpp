#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "MockDuck.h"
#include "MockFlyBehavior.h"
#include "MockQuakBehavior.h"


TEST_CASE("Testing the Fly method")
{
	SECTION("Flying duck with quack after every second flight")
	{
        auto flyBehavior = std::make_unique<MockFlyBehavior>();
        MockFlyBehavior* flyPtr = flyBehavior.get();
        flyBehavior->SetCanFly(true);

        auto quackBehavior = std::make_unique<MockQuackBehavior>();
        MockQuackBehavior* quackPtr = quackBehavior.get();
        quackBehavior->SetCanQuack(true);

        MockDuck duck(std::move(flyBehavior), std::move(quackBehavior));

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 1);
        REQUIRE(quackPtr->GetCanQuack() == false);

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 2);
        REQUIRE(quackPtr->GetCanQuack() == true);

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 3);
        REQUIRE(quackPtr->GetCanQuack() == false);

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 4);
        REQUIRE(quackPtr->GetCanQuack() == true);
	}

    SECTION("No flying duck and no quack")
    {
        auto flyBehavior = std::make_unique<MockFlyBehavior>();
        MockFlyBehavior* flyPtr = flyBehavior.get();
        flyBehavior->SetCanFly(false);

        auto quackBehavior = std::make_unique<MockQuackBehavior>();
        MockQuackBehavior* quackPtr = quackBehavior.get();

        MockDuck duck(std::move(flyBehavior), std::move(quackBehavior));

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 0);
        REQUIRE(quackPtr->GetCanQuack() == false);

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 0);
        REQUIRE(quackPtr->GetCanQuack() == false);
    }

    SECTION("No flying duck and quack")
    {
        auto flyBehavior = std::make_unique<MockFlyBehavior>();
        MockFlyBehavior* flyPtr = flyBehavior.get();
        flyBehavior->SetCanFly(false);

        auto quackBehavior = std::make_unique<MockQuackBehavior>();
        MockQuackBehavior* quackPtr = quackBehavior.get();
        quackBehavior->SetCanQuack(true);

        MockDuck duck(std::move(flyBehavior), std::move(quackBehavior));

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 0);
        REQUIRE(quackPtr->GetCanQuack() == false);

        quackPtr->ResetQuack();
        duck.Fly();
        duck.Quack();
        REQUIRE(flyPtr->GetCountFly() == 0);
        REQUIRE(quackPtr->GetCanQuack() == true);
    }

    SECTION("Flying duck and no quack")
    {
        auto flyBehavior = std::make_unique<MockFlyBehavior>();
        MockFlyBehavior* flyPtr = flyBehavior.get();
        flyBehavior->SetCanFly(true);

        auto quackBehavior = std::make_unique<MockQuackBehavior>();
        MockQuackBehavior* quackPtr = quackBehavior.get();
        quackBehavior->SetCanQuack(false);

        MockDuck duck(std::move(flyBehavior), std::move(quackBehavior));

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 1);
        REQUIRE(quackPtr->GetCanQuack() == false);

        quackPtr->ResetQuack();
        duck.Fly();
        REQUIRE(flyPtr->GetCountFly() == 2);
        REQUIRE(quackPtr->GetCanQuack() == false);
    }
}