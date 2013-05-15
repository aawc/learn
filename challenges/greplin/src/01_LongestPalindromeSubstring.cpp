/*
  The Cue Programming Challenge

  Level 1

  ----------------------------------------

  Embedded in this block of text is the password for level 2.
  The password is the longest substring that is the same in reverse.

  As an example, if the input was "I like racecars that go fast"
  the password would be "racecar".

  Source: http://challenge.greplin.com/static/gettysburg.txt
  FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth
*/

#include <iostream>
#include <string>
using namespace std;

class LongestPalindromeSubstring
{
private:
	string input;

public:
	string getLongestPalindromeSubstring(void)
	{
		cin >> input;

		string longestPalindromeSubstring = "";
		for (unsigned i = 0; i < input.size(); i++)
		{
			string one = getPalindromeCenteredAt(i);
			string two = (i == 0) ? "" : getPalindromeCenteredAt(i-1, i);

			string larger = (one.size() > two.size()) ? one : two;
			if (larger.size() > longestPalindromeSubstring.size())
			{
				longestPalindromeSubstring = larger;
			}
		}

		return longestPalindromeSubstring;
	}

private:
	string getPalindromeCenteredAt(unsigned left, unsigned right)
	{
		unsigned pre = left, post = right;
		while(true)
		{
			if (input[pre] != input[post])
			{
				pre++; post--;
				break;
			}

			if (pre == 0 || post == input.size())
			{
				break;
			}

			pre--; post++;
		}

		return (pre <= post) ? input.substr(pre, post-pre+1) : "";
	}

	string getPalindromeCenteredAt(unsigned center)
	{
		return getPalindromeCenteredAt(center, center);
	}
};