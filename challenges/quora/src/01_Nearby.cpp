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

#include <cmath>
#include <vector>
using namespace std;

class Location
{
public:
	unsigned long x;
	unsigned long y;

	bool operator== (const Location &other)
	{
		return this->x == other.x && this->y == other.y;
	}
	bool operator!= (Location &other)
	{
		return !(*this == other);
	}

	unsigned long distanceFrom (const Location& other)
	{
		return sqrt( (this->x - other.x)*(this->x - other.x) + (this->y - other.y)*(this->y - other.y) );
	}
};

struct Topic
{
	unsigned id;
	Location location;

	bool operator== (const Topic &other)
	{
		return this->id == other.id;
	}
	bool operator!= (Topic &other)
	{
		return !(*this == other);
	}
};

class Question
{
public:
	unsigned id;
	vector<Topic> topics;
};

enum QueryType
{
	t,
	q
};

class Query
{
public:
	QueryType type;
	unsigned numberOfResults;
	Location baseLocation;
};

class ProblemNearby
{
private:
	unsigned tn, qn, nn;
	vector<Topic> topics;
	vector<Question> questions;
	vector<Query> queries;

public:
	ProblemNearby()
	{
		cin >> tn;
		cin >> qn;
		cin >> nn;

		for (unsigned i = 0; i < tn; i++)
		{
			Topic* topic = new Topic;
			topic->
		}
	}
};