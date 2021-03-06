/*
You are given a list of stories, each having a time of publication, a score and a certain height in pixels that it takes to display the story.
Given the total number of pixels in the browser available for displaying the feed, you want to maximize the sum of scores for the stories
that you can display in the feed at each time the user reloads their home page.
We only want to consider recent stories, so only stories that were published in a recent time window from the time of reload should be considered.
You do not have to use up all the pixels in the browser.

Input format (read from STDIN):
The first line of input will be 3 positive integers:
 * N the number of events,
 * W the time window representing the window of recent stories, and
 * H the height of the browser in pixels.

There will be N lines following that, each beginning with ‘S’ if it is a story event, or ‘R’ if it is a reload event.
A story event will have 3 positive integers: the time of publication, the score and the height in pixels of that story.
A reload event will have 1 positive integer: the time of reload.

The events will always be in chronological order, and no two events will happen at the same time.

For example:
9 10 100
S 11 50 30
R 12
S 13 40 20
S 14 45 40
R 15
R 16
S 18 45 20
R 21
R 22

Output format (write to STDOUT):
For each reload event given in the input, you are to output a line of integers.
First, the maximum score of stories you can show in the feed.
This should be followed by the number of stories picked and the id number for each story picked, in increasing order.
Stories are given an id starting from 1 in the order of their time of publication.
If two sets of stories give the same score, choose the set with fewer stories.
If there is still a tie, choose the set which has the lexicographically smaller set of ids, e.g. choose [1, 2, 5] over [1, 3, 4].

For example:
50 1 1
135 3 1 2 3
135 3 1 2 3
140 3 1 3 4
130 3 2 3 4


Explanation:
There are 4 stories (with ids 1 to 4) and 5 reload events.
At the first reload, there is only one story with score of 50 available for display.
The next two reloads, we have 3 stories that take up 90 of the 100 pixels available, for a total score of 135.
When we reload at time 21, there are 4 stories available for choosing, but only 3 will fit into the browser height.
The best set is [1, 3, 4] for a total score of 140. At the last reload event, we no longer consider story 1 when choosing stories
because it is more than 10 time units old. The best set is thus [2, 3, 4].

Constraints
All times are positive integers up to 1,000,000,000.
All scores are positive integers up to 1,000,000.
All heights are positive integers.
0 < N <= 10,000
0 < H <= 2,000
0 < W <= 2,000

You should aim to have your algorithm be fast enough to solve our largest test inputs in under 5 seconds, or be as close to that as possible.
*/

#include <iostream>
using namespace std;

struct Story
{
	unsigned id;
	unsigned long long time;
	unsigned long long score;
	unsigned long long height;
	double scorePerPixel;

	static unsigned idCount;
	Story(unsigned time, unsigned score, unsigned height) :
		id(++Story::idCount),
		time(time),
		score(score),
		height(height),
		scorePerPixel(double(score)/height)
	{}
};

class FeedOptimizer
{
private:
	unsigned numberOfEvents;
	unsigned recentWindow;
	unsigned browserHeight;

public:
	FeedOptimizer()
	{
		cin >> this->numberOfEvents;
		cin >> this->recentWindow;
		cin >> this->browserHeight;

		for (unsigned i=0; i<this->numberOfEvents; i++)
		{
			char eventType;
			cin >> eventType;
			switch (eventType)
			{
				case 'S':
				case 'R':
					;
			}
		}
	}

	~FeedOptimizer()
	{
	}
};