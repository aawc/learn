/*
Your task will be to write a program that will be able to find topics or questions that are near to a given input location, up to a specified limit.

Input format (read from STDIN):
The first line of input will be 3 integers: number of topics T, number of questions Q, and number of queries N.
There will be T lines following that, each with a topic id integer, and two doubles representing that topic's location
(you can consider the points to be located on a XY plane, location of a entity is in form of its x and y coordinate in the plane).

There will be Q lines following that, each with a question id integer and number of topics the question is associated with, Qn,
followed by Qn number of topic ids associated with that question. These integers are guaranteed to be well-formed existing topics.
There may be 0 topics associated with a question, and in such cases, the question should never appear in the query results.

The next N lines will consist of a char, an integer and two doubles each, representing the type of results required
("t" for topic or "q" for question), the number of results required, and the location to be used as the query.

Sample Input:
 1 3 6 2
 2 0 0.0 0.0
 3 1 1.0 1.0
 4 2 2.0 2.0
 5 0 1 0
 6 1 2 0 1
 7 2 3 0 1 2
 8 3 0
 9 4 0
10 5 2 1 2
11 t 2 0.0 0.0
12 q 5 100.0 100.0

 3 6 2
 0 0.0 0.0
 1 1.0 1.0
 2 2.0 2.0
 0 1 0
 1 2 0 1
 2 3 0 1 2
 3 0
 4 0
 5 2 1 2
 t 2 0.0 0.0
 q 5 100.0 100.0

Output format (write to STDOUT):
For each query line given in the input, you are to output the ids of the nearest entities in ascending order of distance
from the query location, up to the specified number of results.
When there is a tie between different entities in the ordering due to equal distances (threshold of 0.001 for equality comparisons),
the entity with the larger id should be ranked first.

Distance of a question from a point is the minimum of the distance of all topics associated with that question.

Sample Output:
1 0 1
2 5 2 1 0

Explanation:
There are 3 topics with ids 0, 1 and 2. There are also 6 questions, with ids 0 to 5. We first ask a nearest topic query.
The closest 2 topics to (0.0, 0.0) are topics 0 and 1.
The next query asks for upto 5 closest questions to (100.0, 100.0). Since questions 5 and 2 are tagged with topic 2 located at (2.0, 2.0),
they are closest to the query location.
Because of the tie in distance, we put question 5 before question 2.
The next closest question is question 1, followed by question 0.
We do not output questions 3 or 4 because there are no topics associated with them.

Constraints:
1 <= T <= 10000
1 <= Q <= 1000
1 <= N <= 10000
Integer ids are between 0 and 100000 inclusive.
Number of topics associated with a question is not more than 10.
The number of results required for a query is not more than 100.
0.0 <= x,y <= 1000000.0 (10^6)

For the large testcases, all topic x,y co-ordinates will be approximately uniformly distributed over the bounds.

You should aim to have your algorithm be fast enough to solve our largest test inputs in under 5 seconds, or be as close to that as possible.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class IDObject
{
public:
	virtual ~IDObject() {}
	virtual unsigned GetID() = 0;
};

class Location
{
private:
	Location(void);

public:
	double x;
	double y;

	Location(double x, double y) : x(x), y(y)
	{}

	bool operator== (const Location &other)
	{
		return this->x == other.x && this->y == other.y;
	}
	bool operator!= (Location &other)
	{
		return !(*this == other);
	}

	double distanceFrom (const Location& other)
	{
		return sqrt( (this->x - other.x)*(this->x - other.x) + (this->y - other.y)*(this->y - other.y) );
	}
};

class Topic : public IDObject
{
public:
	unsigned id;
	Location location;

	Topic(unsigned id, double x, double y) : id(id), location(x, y)
	{}
	~Topic()
	{}

	bool operator== (const Topic &other)
	{
		return this->id == other.id;
	}
	bool operator!= (Topic &other)
	{
		return !(*this == other);
	}

	unsigned GetID()
	{
		return this->id;
	}
};

class Question : public IDObject
{
public:
	unsigned id;
	vector<Topic*> topics;

	Question(unsigned id) : id(id)
	{}
	~Question()
	{}

	unsigned GetID()
	{
		return this->id;
	}
};

class Query
{
public:
	char type;
	unsigned numberOfResults;
	Location *location;

	Query(char type, unsigned numberOfResults, Location* location) : type(type), numberOfResults(numberOfResults), location(location)
	{}

	~Query()
	{
		delete this->location;
	}
};

struct IDObjectAndDistance
{
	IDObject *object;
	double distance;

	static inline bool comparer(const IDObjectAndDistance* a, const IDObjectAndDistance* b)
	{
		if(a->distance == b->distance)
			return a->object->GetID() < b->object->GetID();

		return a->distance < b->distance;
	}
};

class ProblemNearby
{
private:
	unsigned tn, qn, nn;
	vector<Topic*> topics;
	vector<Question*> questions;
	vector<Query*> queries;

	Topic* getTopicWithId(unsigned topicId)
	{
		for (unsigned i = 0; i < topics.size(); i++)
		{
			if (this->topics[i]->id == topicId)
				return topics[i];
		}
		return NULL;
	}

public:
	ProblemNearby()
	{
		cin >> tn;
		cin >> qn;
		cin >> nn;

		for (unsigned i = 0; i < tn; i++)
		{
			unsigned id;
			double x, y;
			cin >> id;
			cin >> x;
			cin >> y;

			this->topics.push_back(new Topic(id, x, y));
		}

		for (unsigned i = 0; i < qn; i++)
		{
			unsigned id;
			unsigned numTopics, topicId;
			cin >> id;
			cin >> numTopics;

			if (numTopics > 0)
			{
				Question *question = new Question(id);
				for (unsigned j = 0; j < numTopics; j++)
				{
					cin >> topicId;
					question->topics.push_back(this->getTopicWithId(topicId));
				}
				this->questions.push_back(question);
			}
		}

		for (unsigned i = 0; i < nn; i++)
		{
			char ctype;
			unsigned numberOfResults;
			double x, y;
			cin >> ctype;
			cin >> numberOfResults;
			cin >> x >> y;
			Location *queryLocation = new Location(x, y);

			this->queries.push_back(new Query(ctype, numberOfResults, queryLocation));
		}

		for (unsigned i = 0; i < nn; i++)
		{
			Query* query = this->queries[i];

			if (query->type == 't' && this->topics.size() != 0)
			{
				vector<IDObjectAndDistance*> topicsAndDistances;
				for (unsigned j = 0; j < this->topics.size(); j++)
				{
					IDObjectAndDistance* topicAndDistance = new IDObjectAndDistance;
					topicAndDistance->distance = query->location->distanceFrom(this->topics[j]->location);
					topicAndDistance->object = this->topics[j];

					topicsAndDistances.push_back(topicAndDistance);
				}

				std::sort(topicsAndDistances.begin(), topicsAndDistances.end(), IDObjectAndDistance::comparer);

				unsigned numberOfResults = query->numberOfResults > topicsAndDistances.size() ? topicsAndDistances.size() : query->numberOfResults;
				for (unsigned j = 0; j < numberOfResults; j++)
				{
					cout << topicsAndDistances[j]->object->GetID() << " ";
				}

				for (unsigned j = 0; j < topicsAndDistances.size(); j++)
				{
					delete topicsAndDistances[j];
				}
			}
			else if (this->questions.size() != 0)
			{
			}
		}
	}

	~ProblemNearby()
	{
		for (unsigned i = 0; i < this->queries.size(); i++)
		{
			delete this->queries[i];
		}

		for (unsigned i = 0; i < this->questions.size(); i++)
		{
			delete this->questions[i];
		}

		for (unsigned i = 0; i < this->topics.size(); i++)
		{
			delete this->topics[i];
		}
	}
};