// http://hyperpublic.com/challenge/question2

using namespace std;

#include <iostream>
#include <assert.h>
#include <limits>

#define DEBUG_CODE 1

void checkForMinimumTasks (
		unsigned taskId,
		unsigned taskKarma[],
		unsigned taskKarmaLen,
		unsigned tasksForThisPerson[],
		unsigned *minTaskSumForThisPerson) {
	int i;

	unsigned sumOfThisPermutation = 0;
	for (i = taskKarmaLen-1; i >= (int)taskId; i--) {
		sumOfThisPermutation += tasksForThisPerson[i];
	}

	if (sumOfThisPermutation < *minTaskSumForThisPerson) {
		*minTaskSumForThisPerson = sumOfThisPermutation;
		double totalKarmaForThisMember = 0;
		for (i = taskKarmaLen-1; i >= (int)taskId; i--) {
			totalKarmaForThisMember += tasksForThisPerson[i] * taskKarma[i];
#if DEBUG_CODE
			cout << tasksForThisPerson[i] << "*" << taskKarma[i] << " + ";
#endif //DEBUG_CODE
		}
#if DEBUG_CODE
		cout << "\t| totalKarmaForThisMember: " << totalKarmaForThisMember << "\t| sumOfThisPermutation: " << sumOfThisPermutation << endl;
#endif //DEBUG_CODE
	}
}

void goSpend (
		unsigned karmaLeftToSpend,
		unsigned taskId,
		unsigned taskKarma[],
		unsigned taskKarmaLen,
		unsigned tasksForThisPerson[],
		unsigned *minTaskSumForThisPerson) {

	int i;
	unsigned maxTimesThisTaskCanBeDone = karmaLeftToSpend / taskKarma[taskId];

	if (0 == taskId) {
		if (0 == (karmaLeftToSpend % taskKarma[taskId])) {
			tasksForThisPerson[taskId] = maxTimesThisTaskCanBeDone;
			checkForMinimumTasks (taskId, taskKarma, taskKarmaLen, tasksForThisPerson, minTaskSumForThisPerson);
		}
		return;
	}

	for (i = maxTimesThisTaskCanBeDone; i >= 0; i--) {
		unsigned karmaLeftToSpendIncludingThis = karmaLeftToSpend - i * taskKarma[taskId];
		tasksForThisPerson[taskId] = i;
		if (tasksForThisPerson[taskId] <= *minTaskSumForThisPerson) {
			if (0 == karmaLeftToSpendIncludingThis) {
				checkForMinimumTasks (taskId, taskKarma, taskKarmaLen, tasksForThisPerson, minTaskSumForThisPerson);
			} else {
				goSpend(karmaLeftToSpendIncludingThis, taskId-1, taskKarma, taskKarmaLen, tasksForThisPerson, minTaskSumForThisPerson);
			}
		}
	}
}

int main () {
	const unsigned staffKarmaLen = 4;
	const unsigned taskKarmaLen = 6;

	unsigned staffKarma [staffKarmaLen] = {
		2349 /* Doug */,
		2102 /* Jordan */,
		2001 /* Eric */,
		1747 /* Jonathan */
	};

	unsigned taskKarma [taskKarmaLen] = {
		2  /* Add Place */,
		3  /* Add Thing */,
		17 /* Tag Object */,
		23 /* Upload Photo */,
		42 /* Twitter Share */,
		98 /* Facebook Share */
	};

	int i, j, k;
	unsigned tasksForThisPerson [taskKarmaLen];
	unsigned minTaskSumForThisPerson;
	double productOfTotalTasks = 1;
	for (i = 0; i < staffKarmaLen; i++) {
#if DEBUG_CODE
		cout << "Staff " << i << ": " << endl;
#endif //DEBUG_CODE

		minTaskSumForThisPerson = (unsigned)-1;
		for (j = 0; j < taskKarmaLen; j++) {
			tasksForThisPerson[j] = 0;
		}

		goSpend (staffKarma[i], taskKarmaLen-1, taskKarma, taskKarmaLen, tasksForThisPerson, &minTaskSumForThisPerson);
#if DEBUG_CODE
		cout << "\n\n*** Min sum of tasks: " << minTaskSumForThisPerson << endl;
#endif //DEBUG_CODE

		productOfTotalTasks *= minTaskSumForThisPerson;
	}

#if DEBUG_CODE
	cout << endl << "Product:  " << productOfTotalTasks << endl;
#else
	cout << productOfTotalTasks << endl;
#endif //DEBUG_CODE
}
