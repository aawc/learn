/*
Input comes into the service as the following commands:
ADD <type> <id> <score> <data string that can contain spaces>
Adds the following <type> of item (user | topic | question | board) with the unique <id> string and <score> float,
corresponding to the <data string> that would be used to match queries.

DEL <id>
Deletes the item specified by unique identifier <id>.

QUERY <number of results> <query string that can contain spaces>
Queries for the specified integer number of results (up to 20) that match a given query string.
For a data item to be considered a matching result to a query, each token in the query must be found in the data string
as a case-insensitive prefix to any token in the data string.
The results are ranked in descending order of score, and we only take the top few results as specified.
When there is a tie in the score, newer items (more recently added) should be ranked higher.
If there are no results, just output the empty string on that line.

WQUERY <number of results> <number of boosts> (<type>:<boost>)* (<id>:<boost>)* <query string that can contain spaces>
Same as QUERY, except that instead of using the raw input score specified by ADD for the particular item,
the scores are weighted by the optional number of boosting factors.
The boosts are floats that should be multiplied to the raw score, and affect either whole types, or specific items with the given <id>s.
If there are multiple boosts applicable, they each are multiplied commutatively to the raw score.

Your task will be to write an equivalent service as a standalone program, with input files that correspond to the queries and updates to the data, and expected output files that correspond to the results obtained for each query.

Input format (read from STDIN):
Your program will be given an integer N on the first line of stdin, followed by N lines of the form:

<command> <command data>

The input commands are: ADD | DEL | QUERY | WQUERY
Types are: user | topic | question | board
Ids are alphanumeric strings without spaces or punctuation and will not include the same strings used for types.
Data strings can be any ASCII character, but are delimited by spaces or tabs.
We will not be using anything special unprintable characters or \r and \n in the data string.

Command data for each command is as specified above.  For example:

ADD user u1 1.0 Adam D’Angelo
ADD user u2 1.0 Adam Black
ADD topic t1 0.8 Adam D’Angelo
ADD question q1 0.5 What does Adam D’Angelo do at Quora?
ADD question q2 0.5 How did Adam D’Angelo learn programming?
QUERY 10 Adam
QUERY 10 Adam D’A
QUERY 10 Adam Cheever
QUERY 10 LEARN how
QUERY 1 lear H
QUERY 0 lea
WQUERY 10 0 Adam D’A
WQUERY 2 1 topic:9.99 Adam D’A
DEL u2
QUERY 2 Adam

Output format (write to STDOUT):
For each QUERY and WQUERY command, you should output the following line:
<sorted result ids>

Where each line contains the <id>s in descending score order, up to the required number of results, as specified above according to the QUERY and WQUERY commands.  If there are no matches, output the empty line.  For example:
u2 u1 t1 q2 q1
u1 t1 q2 q1

q2
q2

u1 t1 q2 q1
t1 u1
u1 t1


Constraints:
0 < N < 100000
0 < number of ADDs < 40000
0 < number of DELs < 10000
0 < number of QUERYs < 20000
0 < number of WQUERYs < 1000
0 < number of boosts < 25
0.0 < each score < 100.0
0 < data string length < 100 chars
*/

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Item
{
	string type;
	string id;
	double score;
	vector<string> data;
	unsigned index;

	~Item()
	{
		//cout << "Deleting: " << this->id << " from index: " << this->index << endl;
		this->data.clear();
	}
};

struct Boost
{
	string id;
	double boost;
};

struct BoostedItem
{
	double boost;
	Item* item;
};

class TypeAhead
{
public:
	vector<Item*> items;

	static inline bool comparer(const BoostedItem* a, const BoostedItem* b)
	{
		double aBoostededScore = a->item->score * a->boost;
		double bBoostededScore = b->item->score * b->boost;

		// In case of tie, use the one which is added more recently,
		// so, has higher index in this->items
		if(aBoostededScore == bBoostededScore)
		{
			return a->item->index > b->item->index;
		}

		return aBoostededScore > bBoostededScore;
	}

	TypeAhead()
	{
		unsigned numberOfInputRows;
		cin >> numberOfInputRows;

		for (unsigned i = 0; i < numberOfInputRows; i++)
		{
			string command;
			cin >> command;
			if (command == "ADD")
			{
				string type, id, scoreAsString, data, buf;
				cin >> type;
				cin >> id;
				cin >> scoreAsString;
				double score = atof(scoreAsString.c_str());
				getline(cin, data);
				istringstream sin(data);

				Item* item = new Item;
				item->type = type;
				item->id = id;
				item->score = score;
				while (sin >> buf)
				{
					item->data.push_back(buf);
				}
				item->index = this->items.size();

				this->items.push_back(item);
			}
			else if (command == "DEL")
			{
				string id;
				cin >> id;

				bool deleted = false;
				vector<Item*>::iterator deletedItem;
				for (vector<Item*>::iterator it = this->items.begin(); it != this->items.end(); it++)
				{
					if ((*it)->id == id)
					{
						deletedItem = it;
						deleted = true;
					}
					else if (deleted)
					{
						(*it)->index --;
					}
				}

				delete *deletedItem;
				this->items.erase(deletedItem);
			}
			else
			{
				unsigned numberOfResults;
				cin >> numberOfResults;

				vector<Boost*> boosts;
				if (command == "WQUERY")
				{
					unsigned numberOfBoosts;
					cin >> numberOfBoosts;
					string boostString;
					for (unsigned j = 0; j < numberOfBoosts; j++)
					{
						cin >> boostString;
						string::iterator it = std::find(boostString.begin(), boostString.end(), ':');

						Boost* boost = new Boost;
						boost->id = boostString.substr(0, it - boostString.begin());
						boost->boost = atof(boostString.substr(it+1 - boostString.begin(), boostString.end()-(it+1)).c_str());
						//cout << "Created boost: " << boost->id << " of " << boost->boost << endl;

						boosts.push_back(boost);
					}
				}

				string data;
				getline(cin, data);
				istringstream sin(data);
				string buffer;
				vector<string> searchTerms;
				while (sin >> buffer)
				{
					searchTerms.push_back(buffer);
				}

				if (numberOfResults > 0)
				{
					vector<BoostedItem*> results = this->getSortedBoostedItems(boosts, searchTerms);
					numberOfResults = numberOfResults > results.size() ? results.size() : numberOfResults;
					for (unsigned j = 0; j < numberOfResults; j++)
					{
						if (j != 0) cout << " ";
						cout << results[j]->item->id;
					}
				}
				cout << endl;

				for (vector<Boost*>::iterator boost = boosts.begin(); boost != boosts.end(); boost++)
				{
					delete *boost;
				}
				boosts.clear();
			}
		}
	}

	vector<BoostedItem*> getSortedBoostedItems(vector<Boost*> boosts, vector<string> searchTerms)
	{
		vector<BoostedItem*> boostedItems;

		for (vector<Item*>::iterator item = this->items.begin(); item != this->items.end(); item++)
		{
			if (!this->doesItemMatchSearchTerms(item, searchTerms))
			{
				continue;
			}
			//cout << "Matched! Item: " << (*item)->id << endl;

			double effectiveBoost = 1;
			for (vector<Boost*>::iterator boost = boosts.begin(); boost != boosts.end(); boost++)
			{
				if ((*item)->type == (*boost)->id || (*item)->id == (*boost)->id)
				{
					effectiveBoost *= (*boost)->boost;
					//cout << "effectiveBoost: " << effectiveBoost << "; item: " << (*item)->id << endl;
				}
			}

			BoostedItem* boostedItem = new BoostedItem;
			boostedItem->boost = effectiveBoost;
			boostedItem->item = *item;
			boostedItems.push_back(boostedItem);
		}

		std::sort(boostedItems.begin(), boostedItems.end(), TypeAhead::comparer);
		return boostedItems;
	}

	bool doesItemMatchSearchTerms (vector<Item*>::iterator item, vector<string> searchTerms)
	{
		for (vector<string>::iterator searchTerm = searchTerms.begin(); searchTerm != searchTerms.end(); searchTerm++)
		{
			bool found = false;
			const char* searchTermAsCStr = (*searchTerm).c_str();
			unsigned searchTermLength = (*searchTerm).length();

			for (vector<string>::iterator dataTerm = (*item)->data.begin(); dataTerm != (*item)->data.end(); dataTerm++)
			{
				unsigned dataTermLength = (*dataTerm).length();
				if (dataTermLength >= searchTermLength)
				{
					const char* dataTermCStr = (*dataTerm).c_str();
					const char* searchTermCStr = searchTermAsCStr;
					unsigned i = 0;

					while (i < dataTermLength && i < searchTermLength && tolower(*dataTermCStr) == tolower(*searchTermCStr))
					{
						dataTermCStr++; searchTermCStr++; i++;
					}
					found = (i == searchTermLength);
					if (found) break;
				}
			}

			if (!found)
				return false;
		}
		return true;
	}

	~TypeAhead()
	{
		for (vector<Item*>::iterator item = this->items.begin(); item != this->items.end(); item++)
		{
			delete *item;
		}
		this->items.clear();
	}
};
/*
int main(int argc, char **argv)
{
	TypeAhead* typeAhead = new TypeAhead;
	delete typeAhead; typeAhead = NULL;
	return 0;
}
*/