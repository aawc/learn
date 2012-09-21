// http://hyperpublic.com/challenge/question2

using namespace std;

#include <iostream>
#include <assert.h>
#include <limits>

bool accountForKarma (
		unsigned staffKarma[],
		unsigned staffKarmaLen,
		unsigned taskKarma[],
		unsigned taskKarmaLen,
		unsigned tasksForThisPerson[],
		unsigned person,
		unsigned taskNumber,
		unsigned accountedForSoFar) {
	assert (person < staffKarmaLen);
	assert (taskNumber < taskKarmaLen);

	unsigned stillToBeAccounted = staffKarma[person] - accountedForSoFar;
	unsigned numberOfTasksForThisKarma = stillToBeAccounted / taskKarma[taskNumber];
	unsigned karmaPointsAccountedByThisTask = numberOfTasksForThisKarma * taskKarma[taskNumber];
	bool result = false;

	accountedForSoFar += karmaPointsAccountedByThisTask;
	if (accountedForSoFar == staffKarma[person]) {
		tasksForThisPerson[taskNumber] = numberOfTasksForThisKarma;
		return true;
	} else {
		if (0 == taskNumber) {
			return false;
		}

		while (numberOfTasksForThisKarma <= (numberOfTasksForThisKarma + 1)) {
			result = accountForKarma (staffKarma, staffKarmaLen, taskKarma, taskKarmaLen, tasksForThisPerson, person, taskNumber-1, accountedForSoFar);
			if (result) {
				tasksForThisPerson[taskNumber] = numberOfTasksForThisKarma;
				return true;
			} else {
				numberOfTasksForThisKarma --;
				if ((numberOfTasksForThisKarma) > (numberOfTasksForThisKarma + 1)) {
					return false;
				} else {
					accountedForSoFar -= taskKarma[taskNumber];
				}
			}
		}

		return false;
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

	int i, j;
	unsigned **tasksPerPerson = new unsigned* [staffKarmaLen];
	unsigned tasksForThisPerson [taskKarmaLen];

	for (i = 0; i < staffKarmaLen; i++) {
		tasksPerPerson[i] = new unsigned [taskKarmaLen];
		for (j = taskKarmaLen-1; j >= 0; j--) {
			tasksPerPerson[i][j] = 0;
		}
	}

	double productOfTotalTasks = 1;
	for (i = 0; i < staffKarmaLen; i++) {
		cout << "Staff " << i << ": ";

		for (j = taskKarmaLen-1; j >= 0; j--) {
			tasksForThisPerson[j] = 0;
		}
		assert (true == accountForKarma (staffKarma, staffKarmaLen, taskKarma, taskKarmaLen, tasksForThisPerson, i, taskKarmaLen-1, 0));

		int totalTasksForThisMember = 0;
		for (j = taskKarmaLen-1; j >= 0; j--) {
			totalTasksForThisMember += tasksForThisPerson[j];
			cout << tasksForThisPerson[j] << "*" << taskKarma[j] << " + ";
		}
		cout << "\t| Total: " << totalTasksForThisMember << endl;

		productOfTotalTasks *= totalTasksForThisMember;
	}

	cout << endl << "Product:  " << productOfTotalTasks << endl;
}
