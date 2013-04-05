#ifndef PROBLEM11_H
#define PROBLEM11_H

class Problem11
{
	public:
		Problem11();
		virtual ~Problem11();
		Problem11(const Problem11& other);
		Problem11& operator=(const Problem11& other);

		long long getLargestSubSeqProduct();
	protected:
	private:
};

#endif // PROBLEM11_H
