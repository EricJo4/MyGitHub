#include "pch.h"
#include "CppUnitTest.h"
#include "box_r.h"
#include "truck_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{
	namespace BoxUnitTest {
		TEST_CLASS(IsValidSizeTest) {
			TEST_CLASS_INITIALIZE(IsValidSizeTestInitialize)
			{
				Logger::WriteMessage("IsValidSize Tests");
			}

			TEST_METHOD(VSO1)
			{
				double size = 0.25;
				int result = IsValidSize(size);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VSO2)
			{
				double size = 0.5;
				int result = IsValidSize(size);
				Assert::AreEqual(0, result);
			}  
			TEST_METHOD(VSO3)
			{
				double size = 1;
				int result = IsValidSize(size);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VSO4)
			{
				double size = -1;
				int result = IsValidSize(size);
				Assert::AreEqual(-1, result);
			}
			TEST_METHOD(VSO5)
			{
				double size = -0.25;
				int result = IsValidSize(size);
				Assert::AreEqual(-1, result);
			}
			TEST_METHOD(VSO6)
			{
				double size = 0.3;
				int result = IsValidSize(size);
				Assert::AreEqual(-1, result);
			}   
		};

		TEST_CLASS(IsValidWeightTest) {
			TEST_CLASS_INITIALIZE(IsValidWeightTestInitialize)
			{
				Logger::WriteMessage("IsValidWeight Tests");
			}

			TEST_METHOD(VWO1)
			{
				int weight = 0;
				int result = IsValidWeight(weight);
				Assert::AreEqual(-1, result);
			}
			TEST_METHOD(VWO2)
			{
				int weight = 1;
				int result = IsValidWeight(weight);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VWO3)
			{
				int weight = 100;
				int result = IsValidWeight(weight);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VWO4)
			{
				int weight = 500;
				int result = IsValidWeight(weight);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VWO5)
			{
				int weight = 1000;
				int result = IsValidWeight(weight);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VWO6)
			{
				int weight = -1;
				int result = IsValidWeight(weight);
				Assert::AreEqual(-1, result);
			}
			TEST_METHOD(VWO7)
			{
				int weight = 1001;
				int result = IsValidWeight(weight);
				Assert::AreEqual(-1, result);
			}
		};

		TEST_CLASS(IsValidDestinationTest) {
			TEST_CLASS_INITIALIZE(IsValidDestinationTestInitialize) {
				Logger::WriteMessage("IsValidDestination Tests");
			}

			TEST_METHOD(VDO1)
			{
				const Point des = { 1 - 1, 'A' - 'A'};
				int result = IsValidDestination(&des);
				Assert::AreEqual(0, result);
			}
			TEST_METHOD(VDO2)
			{
				const Point des = { 4 - 1, 'Z' - 'A' };
				int result = IsValidDestination(&des);
				Assert::AreEqual(-1, result);
			}
			TEST_METHOD(VDO3)
			{
				const Point des = { -1 - 1, 'B' - 'A' };
				int result = IsValidDestination(&des);
				Assert::AreEqual(-1, result);
			}
		};
	}

	namespace TruckUnitTest {
		TEST_CLASS(FindClosestTruckTest) {
			TEST_CLASS_INITIALIZE(FindClosestTruckTestInitialize) {
				Logger::WriteMessage("FindClosestTruck Tests");
			}

			TEST_METHOD(FCTO1)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 3 - 1, 'D' - 'A' };
				Assert::AreEqual(0, FindClosestTruck(trucks, 3, &des)); //
			}
			TEST_METHOD(FCTO2)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 5 - 1, 'S' - 'A' };
				Assert::AreEqual(1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCTO3)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 9 - 1, 'I' - 'A' };
				Assert::AreEqual(0, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCTO4)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { -1 - 1, 'B' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCTO5)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 1 - 1, '$' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCTO6)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'L' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 0, &des));
			}
			TEST_METHOD(FCTO7)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'L' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, -1, &des));
			}
			TEST_METHOD(FCTO8)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'L' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 1, &des));
			}
			TEST_METHOD(FCTO9)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'L' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 4, &des));
			}
			TEST_METHOD(FCT10)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'L' - 'A' };
				Assert::AreEqual(0, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT11)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 2 - 1, 'Q' - 'A' };
				Assert::AreEqual(1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT12)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'A' - 'A' };
				Assert::AreEqual(2, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT13)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 0 - 1, 'A' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT14)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { -1 - 1, 'A' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT15)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 26 - 1, 'A' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT16)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 15 - 1, 'A' - 'A' };
				Assert::AreEqual(2, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT17)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'X' - 'A' };
				Assert::AreEqual(1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT18)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'Z' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT19)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'a' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT20)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'y' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(FCT21)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 12 - 1, 'p' - 'A' };
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}

			TEST_METHOD(IntegrationTesting_FCT01)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 0 - 1, '2' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT02)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { -1 - 1, 'D' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT03)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 26 - 1, 'D' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT04)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 100 - 1, 'D' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT05)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'D' - 'A'};
				Assert::AreEqual(2, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT06)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'd' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT07)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'z' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT08)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'a' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT09)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'y' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT10)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 25 - 1, 'Z' - 'A'};
				Assert::AreEqual(-1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT11)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 6 - 1, 'X' - 'A'};
				Assert::AreEqual(1, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT12)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 1 - 1, 'A' - 'A'};
				Assert::AreEqual(0, FindClosestTruck(trucks, 3, &des));
			}
			TEST_METHOD(IntegrationTesting_FCT13)
			{
				// Create the blue, green, and yellow truck
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };

				// Initialize an array of trucks with values blueT, greenT, and yellowT
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 5 - 1, 'K' - 'A'};
				Assert::AreEqual(1, FindClosestTruck(trucks, 3, &des));
			}
		};

		TEST_CLASS(FindTruckForShipmentTest) {
			TEST_CLASS_INITIALIZE(FindTruckForShipmentTestInitialize) 
			{
				Logger::WriteMessage("FindTruckForShipment Tests");
			}

			TEST_METHOD(FTSO1)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };  
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };

				struct Point des = { 1 - 1, 'B' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package)); // 0
			}  
			TEST_METHOD(FTSO2)
			{
				struct Truck blueT = { {0}, 1, 500, 3, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 2, 700, 4, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'M' - 'A'};
				struct Box package = { 200, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTSO3)
			{
				struct Truck blueT = { {0}, 1, 1000, 1, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 1, 1000, 1, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 1, 1000, 1, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A'};
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTSO4)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 0, &des, &package));
			}
			TEST_METHOD(FTSO5)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, -1, &des, &package));
			}
			TEST_METHOD(FTSO6)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 1, &des, &package));
			}
			TEST_METHOD(FTSO7)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 6, &des, &package));
			}
			TEST_METHOD(FTSO8)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 10 - 1, 'C' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTSO9)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 7 - 1, 'B' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS10)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 12 - 1, 'E' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS11)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 3 - 1, 'N' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS12)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 8 - 1, 'W' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS13)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 12 - 1, 'U' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS14)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 14 - 1, 'O' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS15)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 16 - 1, 'Q' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS16)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 12 - 1, 'L' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(FTS17)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 25 - 1, 'L' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}                            

			TEST_METHOD(IntegrationTesting_FTS01)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 0 - 1, 'L' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS02)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { -1 - 1, 'L' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS03)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 26 - 1, 'L' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS04)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 25 - 1, 'a' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS05)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 25 - 1, 'y' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS06)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 25 - 1, 'j' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS07)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 25 - 1, 'Z' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS08)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));  
			}
			TEST_METHOD(IntegrationTesting_FTS09)
			{
				struct Truck blueT = { {0}, 50, 1000, 20, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS10)
			{
				struct Truck blueT = { {0}, 50, 500, 20, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS11)
			{
				struct Truck blueT = { {0}, 50, 500, 36, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS12)
			{
				struct Truck blueT = { {0}, 50, 500, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 50, 1000, 35, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS13)
			{
				struct Truck blueT = { {0}, 50, 500, 36, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 50, 500, 36, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(2, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS14)
			{
				struct Truck blueT = { {0}, 50, 500, 36, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 50, 500, 36, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 50, 500, 36, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS15)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 1001, 1 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS16)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 1000, 37 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS17)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 1000, 36 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS18)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 1000, 0.6 };
				Assert::AreEqual(-1, FindTruckForShipment(trucks, 3, &des, &package));
			}
			TEST_METHOD(IntegrationTesting_FTS19)
			{
				struct Truck blueT = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Truck greenT = { {0}, 0, 0, 0, green, getGreenRoute() };
				struct Truck yellowT = { {0}, 0, 0, 0, yellow, getYellowRoute() };
				struct Truck trucks[3] = { blueT, greenT, yellowT };
				struct Point des = { 5 - 1, 'D' - 'A' };
				struct Box package = { 1000, 0.25 };
				Assert::AreEqual(0, FindTruckForShipment(trucks, 3, &des, &package));
			}
		};   

		TEST_CLASS(addPackageToTruckTest) {
			TEST_CLASS_INITIALIZE(addPackageToTruckTestInitialize) 
			{
				Logger::WriteMessage("addPackageToTruck Tests");
			}

			TEST_METHOD(APTO1)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { 500, 100 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(APTO2)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { 500, 0.5 };
				Assert::AreEqual(0, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(APTO3)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { 500, 0 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(APTO4)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { 1500, 0.5 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(APTO5)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { -500, 0.5 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(APTO6)
			{
				struct Truck truck = { {0}, 100, 1, 1, blue, getBlueRoute() };
				struct Box package = { 500, 0.3 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}  

			TEST_METHOD(IntegrationTesting_APTO1)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { -1, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO2)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 0, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO3)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 1, 1 };
				Assert::AreEqual(0, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO4)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 1500, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO5)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 1001, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO6)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO7)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 500, 0 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APTO8)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 500, -1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APT09)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 500, 0.3 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APT10)
			{
				struct Truck truck = { {0}, 0, 0, 0, blue, getBlueRoute() };
				struct Box package = { 500, 1.2 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APT11)
			{
				struct Truck truck = { {0}, 30, 1000, 0, blue, getBlueRoute() };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APT12)
			{
				struct Truck truck = { {0}, 30, 500, 36, blue, getBlueRoute() };
				struct Box package = { 500, 1 };
				Assert::AreEqual(-1, addPackageToTruck(&truck, &package));
			}
			TEST_METHOD(IntegrationTesting_APT13)
			{
				struct Truck truck = { {0}, 30, 500, 35, blue, getBlueRoute() };
				struct Box package = { 500, 1 };
				Assert::AreEqual(0, addPackageToTruck(&truck, &package));
			}
		};
	}
}
