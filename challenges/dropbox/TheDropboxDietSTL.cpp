#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define DEBUG_CODE 0

/*
 * This class represents a food item or an activity, depending on the sign bit of the associated calorie number.
 */
class FoodItemOrActivity
{
	char *_name;
	int _calories;

public:
	FoodItemOrActivity(char *name, int calories) : _calories(calories)
	{
#if DEBUG_CODE
		printf ("%s:%d: %s: %p:  name: %s |  calories: %d\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, this, name, calories);
#endif //DEBUG_CODE
		_name = new char [strlen(name)+1];
		strncpy (_name, name, strlen(name));
		_name [strlen(name)] = '\0';
#if DEBUG_CODE
		printf ("%s:%d: %s: %p: _name: %s | _calories: %d\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, this, _name, _calories);
#endif //DEBUG_CODE
	}

	~FoodItemOrActivity ()
	{
#if DEBUG_CODE
		printf ("%s:%d: %s: %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, this);
#endif //DEBUG_CODE
		if (_name)
		{
#if DEBUG_CODE
			printf ("%s:%d: %s: _name: %s | _calories: %d\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, _name, _calories);
#endif //DEBUG_CODE
			delete [] _name;
			_name = NULL;
		}
	}

	char* name()
	{
		return _name;
	}
	int& calories()
	{
		return _calories;
	}
};

bool emptyArray (std::vector<FoodItemOrActivity*> foodOrActivityVector)
{
	// start from the beginning of the array
	std::vector<FoodItemOrActivity*>::iterator itPos = foodOrActivityVector.begin();
	// clear all elements from the vector
	for (; itPos < foodOrActivityVector.end(); itPos++)
		delete *itPos; // free the element from memory
	// finally, clear all elements from the vector
	foodOrActivityVector.clear();
}

/*
 * Returns true if it finds the bit 'bit' set in the number 'number'.
 * Otherwise, returns false.
 */
bool isBitSet (int number, int bit)
{
	return (number & 1<<bit);
}

/*
 * The solution to the problem is to enlist all the possible ways to gain calories and matches that against all the possible ways to lose calories.
 * If it finds a match in these 2 lists, then we know we have found a way.
 *
 * This function creates the integer list of all the possible calorie counts for all the activities and for all the food items.
 */
std::vector<int> buildItemCombinationsArray (std::vector<FoodItemOrActivity*> foodOrActivityVector)
{
	int numberOfItemsInArray = foodOrActivityVector.size();
	int numberOfCombos = (1 << numberOfItemsInArray) - 1;
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s: To find %d combos for %p with %d elements\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, numberOfCombos, &foodOrActivityVector, numberOfItemsInArray);
#endif //DEBUG_CODE
	std::vector<int> combosArray (numberOfCombos);

	for (int i = 1; i <= numberOfCombos; i++)
	{
		int sum = 0, j = 0;
		for (; j < numberOfItemsInArray; j++)
		{
			if (isBitSet (i, j))
			{
				sum += foodOrActivityVector[j]->calories();
			}
		}
		combosArray[i-1] = sum;
#if DEBUG_CODE
	printf ("%s:%d: Combo[%d] for %p = %d\n", __FILE__, __LINE__, i-1, &foodOrActivityVector, sum);
#endif //DEBUG_CODE
	}

	return combosArray;
}

int main (int argc, char* argv[])
{
	int items = 0, count = 0;
	std::vector<FoodItemOrActivity*>foodArray, activityArray;

	int ret = scanf ("%d", &items);
	if (items < 1) return -1;
	char name [PATH_MAX];
	int calories;
	for (count = 0; count < items; count++)
	{
		ret = scanf ("%s %d", name, &calories);
#if DEBUG_CODE
		printf ("%s:%d: %s: name: %s |  calories: %d\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, name, calories);
#endif //DEBUG_CODE
		FoodItemOrActivity *item = new FoodItemOrActivity (name, calories);
		if (!item) return -1;
		if (item->calories() > 0)
		{
			foodArray.push_back (item);
		}
		else if (item->calories() < 0)
		{
			activityArray.push_back (item);
		}
		else
		{
			return -1;
		}
	}

	std::vector<int> activityItemsComboArray = buildItemCombinationsArray (activityArray);
	std::vector<int> foodItemsComboArray     = buildItemCombinationsArray (foodArray);
	int numberOfActivityCombos = activityItemsComboArray.size(), numberOfFoodCombos = foodItemsComboArray.size();
#if DEBUG_CODE
	printf ("\n%s:%d: Activity combos: %d | Food combos: %d\n", __FILE__, __LINE__, numberOfActivityCombos, numberOfFoodCombos);
#endif //DEBUG_CODE

	bool solutionFound = false;
	for (int i = 0; i < numberOfActivityCombos; i++)
	{
		for (int j = 0; j < numberOfFoodCombos; j++)
		{
			if (0 == (activityItemsComboArray[i] + foodItemsComboArray[j]))
			{
				solutionFound = true;
#if DEBUG_CODE
				printf ("\n\n%s:%d: %s: Found: %d at %d, %d:\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, activityItemsComboArray[i], i, j);
#endif //DEBUG_CODE
				int foundActivityCombo = i+1, foundFoodCombo = j+1;
				for (int k = 0; k < activityArray.size(); k++)
				{
					if (isBitSet(foundActivityCombo, k))
					{
						printf ("%-30s %5d\n", activityArray[k]->name(), activityArray[k]->calories());
					}
				}
				for (int k = 0; k < foodArray.size(); k++)
				{
					if (isBitSet(foundFoodCombo, k))
					{
						printf ("%-30s %5d\n", foodArray[k]->name(), foodArray[k]->calories());
					}
				}
				printf ("\n");
			}
		}
	}
	if (!solutionFound)
	{
		printf ("\nno solution\n");
	}

	emptyArray (activityArray);
	emptyArray (foodArray);

	return 0;
}
