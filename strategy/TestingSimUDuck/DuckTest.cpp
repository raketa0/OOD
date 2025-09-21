#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "MockDuck.h"
#include "MockDanceBehavior.h"

TEST_CASE("Testing the Dance method")
{
	auto mockDance = std::make_unique<MockDanceBehavior>();
	MockDanceBehavior* mockDancePtr = mockDance.get();
	REQUIRE(mockDance->isCalled == false);

	MockDuck mockDuck(std::move(mockDance));
	REQUIRE(mockDuck.m_danceBehavior != nullptr);

	mockDuck.Dance();
	REQUIRE(mockDancePtr->isCalled == true);

}