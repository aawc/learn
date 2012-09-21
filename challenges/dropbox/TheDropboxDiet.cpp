/*
The Dropbox Diet
Of the boatload of perks Dropbox offers, the ones most threatening to our 
engineers' waistlines are the daily lunches, the fully-stocked drink fridge, 
and a full-length bar covered with every snack you could want. All of those 
calories add up. Luckily, the office is also well-equipped with ping-pong, a 
DDR machine, and a subsidized gym right across the street that can burn those 
calories right back off. Although we often don't, Dropboxers should choose the 
food they eat to counterbalance the activities they perform so that they don't 
end up with caloric deficit or excess.

Help us keep our caloric intake in check. You'll be given a list of activities 
and their caloric impact. Write a program that outputs the names of activities 
a Dropboxer should choose to partake in so that the sum of their caloric 
impact is zero. Once the activity is selected, it cannot be chosen again.

Input
Your program reads an integer N (1 <= N <= 50) from STDINrepresenting the 
number of list items in the test input. The list is comprised of activities or 
food items and its respective calorie impact separated by a space, one pair 
per line. Activity names will use only lowercase ASCII letters and the dash 
(-) character.

Output
Output should be sent to stdout, one activity name per line, alphabetized. If 
there is no possible solution, the output should be no solution. If there are 
multiple solutions, your program can output any one of them.

Sample Input
2
red-bull 140
coke 110

Sample Output
no solution

Sample Input
12
free-lunch 802
mixed-nuts 421
orange-juice 143
heavy-ddr-session -302
cheese-snacks 137
cookies 316
mexican-coke 150
dropballers-basketball -611
coding-six-hours -466
riding-scooter -42
rock-band -195
playing-drums -295

Sample Output
coding-six-hours
cookies
mexican-coke

 */

#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <assert.h>

using namespace std;

#define DEBUG_CODE 0

/*
 * This class represents a food item or an activity, depending on the sign bit of the associated calorie number.
 */
class FoodItemOrActivity
{
	char *_name;
	int _calories;
	FoodItemOrActivity *_next;

public:
	FoodItemOrActivity () : _next(NULL)
	{
#if DEBUG_CODE
		printf ("%s:%d: %s: %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, this);
#endif //DEBUG_CODE
		_name = new char [PATH_MAX];
	}

	FoodItemOrActivity(char *name, int calories) : _next(NULL), _calories(calories)
	{
#if DEBUG_CODE
		printf ("%s:%d: %s: %p:  name: %s |  calories: %d\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, this, name, calories);
#endif //DEBUG_CODE
		_name = new char [strlen(name)+1];
		strncpy (_name, name, strlen(name));
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
	FoodItemOrActivity*& next()
	{
		return _next;
	}
};

/*
 * Creates a queue by adding the incoming 'item' to the head of the queue.
 * If the head is NULL, it marks the incoming item as the head.
 */
bool addToQueue (FoodItemOrActivity **ptrToHead, FoodItemOrActivity *item)
{
	if (!item)
	{
#if DEBUG_CODE
		printf ("%s:%d: %s: item is NULL\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
#endif //DEBUG_CODE
		return false;
	}
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s to add (%s, %d) to %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, item->name(), item->calories(), ptrToHead);
#endif //DEBUG_CODE

	if (!(*ptrToHead))
	{
		*ptrToHead = item;
	}
	else
	{
		item->next() = *ptrToHead;
		*ptrToHead = item;
	}

	return true;
}

/*
 * Empties the activity and the food queue after we are done looking for a match.
 */
bool emptyQueue (FoodItemOrActivity *queueHead)
{
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s to empty %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, queueHead);
#endif //DEBUG_CODE
	while (queueHead)
	{
		FoodItemOrActivity *ptr = queueHead;
		queueHead = queueHead->next();
		ptr->next() = NULL;
#if DEBUG_CODE
		printf ("%s:%d: Removing: (%s, %d) at %p\n", __FILE__, __LINE__, ptr->name(), ptr->calories(), ptr);
#endif //DEBUG_CODE
		delete ptr;
	}
}

/*
 * This function returns an array of all the element in the queue.
 * This helps in item look-up later.
 */
FoodItemOrActivity** buildItemArray (FoodItemOrActivity *queueHead, int &numberOfItemsInArray)
{
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s to build an array for: %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, queueHead);
#endif //DEBUG_CODE
	FoodItemOrActivity *ptr = NULL;
	FoodItemOrActivity **array = NULL;
	int n = 0;

	if (!queueHead)
	{
		numberOfItemsInArray = 0;
		return NULL;
	}
	ptr = queueHead;
	while (ptr)
	{
		n++;
		ptr = ptr->next();
	}
#if DEBUG_CODE
	printf ("%s:%d: In: %s: Found %d elements in the array: %p\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, n, queueHead);
#endif //DEBUG_CODE
	array = new FoodItemOrActivity* [n];
	if (!array)
	{
		numberOfItemsInArray = 0;
		return NULL;
	}
	ptr = queueHead; n = 0;
	while (ptr)
	{
		array[n] = ptr;
		ptr = ptr->next();
		n++;
	}
	numberOfItemsInArray = n;
	return array;
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
int* buildItemCombinationsArray (FoodItemOrActivity **array, int numberOfItemsInArray, int &numberOfCombos)
{
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s: To find combos for %p with %d elements\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, array, numberOfItemsInArray);
#endif //DEBUG_CODE
	numberOfCombos = 1 << numberOfItemsInArray - 1;
	int *combosArray = new int [numberOfCombos];
	if (!combosArray)
	{
		return NULL;
	}

	int i;
	for (i = 1; i <= numberOfCombos; i++)
	{
		int sum = 0, j = 0;
		for (; j < numberOfItemsInArray; j++)
		{
			if (isBitSet (i, j))
			{
				sum += array[j]->calories();
			}
		}
		combosArray[i-1] = sum;
#if DEBUG_CODE
	printf ("%s:%d: Combo[%d] for %p = %d\n", __FILE__, __LINE__, i, array, sum);
#endif //DEBUG_CODE
	}
	return combosArray;
}

int main (int argc, char* argv[])
{
#if DEBUG_CODE
	printf ("\n%s:%d: Entered: %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
#endif //DEBUG_CODE
	int items = 0, count = 0;
	FoodItemOrActivity *foodQueue = NULL, *activityQueue = NULL;
	FoodItemOrActivity **activityArray = NULL, **foodArray = NULL;

	scanf ("%d", &items);
	if (items < 1) return -1;
	for (count = 0; count < items; count++)
	{
		FoodItemOrActivity *item = new FoodItemOrActivity ();
		if (!item) return -1;

		int &calories = item->calories();
		scanf ("%s %d", item->name(), &calories);
		if (item->calories() > 0)
		{
			addToQueue (&foodQueue, item);
		}
		else if (item->calories() < 0)
		{
			addToQueue (&activityQueue, item);
		}
		else
		{
			return -1;
		}
	}

	int numberOfActivities = 0, numberOfFoods = 0;
	activityArray = buildItemArray (activityQueue, numberOfActivities);
	foodArray     = buildItemArray (foodQueue, numberOfFoods);
#if DEBUG_CODE
	printf ("%s:%d: Total: %d | Activities: %d | Foods: %d\n", __FILE__, __LINE__, items, numberOfActivities, numberOfFoods);
#endif //DEBUG_CODE
	assert (numberOfActivities+numberOfFoods == items);

	int numberOfActivityCombos= 0, numberOfFoodCombos = 0;
	int *activityItemsComboArray = buildItemCombinationsArray (activityArray, numberOfActivities, numberOfActivityCombos);
	int *foodItemsComboArray = buildItemCombinationsArray (foodArray, numberOfFoods, numberOfFoodCombos);
#if DEBUG_CODE
	printf ("\n%s:%d: Activity combos: %d | Food combos: %d\n", __FILE__, __LINE__, numberOfActivityCombos, numberOfFoodCombos);
#endif //DEBUG_CODE

	bool solutionFound = false;
	for (int i = 0; i < numberOfActivityCombos; i++)
	{
		for (int j = 0; j < numberOfFoodCombos; j++)
		{
#if DEBUG_CODE && 0
			printf ("\n%s:%d: Activity[%d]: %d | Food[%d]: %d\n", __FILE__, __LINE__, i, activityItemsComboArray[i], j, foodItemsComboArray[j]);
#endif //DEBUG_CODE
			if (0 == (activityItemsComboArray[i] + foodItemsComboArray[j]))
			{
				solutionFound = true;
#if DEBUG_CODE
				printf ("\n\n%s:%d: %s: Found: %d at %d, %d\n\n\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, activityItemsComboArray[i], i, j);
#endif //DEBUG_CODE
				int foundActivityCombo = i+1, foundFoodCombo = j+1;
				for (int k = 0; k < numberOfActivities; k++)
				{
					if (isBitSet(foundActivityCombo, k))
					{
						printf ("%s\n", activityArray[k]->name());
					}
				}
				for (int k = 0; k < numberOfFoods; k++)
				{
					if (isBitSet(foundFoodCombo, k))
					{
						printf ("%s\n", foodArray[k]->name());
					}
				}
			}
		}
	}
	if (!solutionFound)
	{
		printf ("\nno solution\n");
	}

	delete [] activityArray;
	delete [] foodArray;
	delete [] activityItemsComboArray;
	delete [] foodItemsComboArray;
	emptyQueue (activityQueue);
	emptyQueue (foodQueue);

#if DEBUG_CODE
	printf ("%s:%d: Exiting: %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
#endif //DEBUG_CODE
	return 0;
}
