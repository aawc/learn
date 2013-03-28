#ifndef PROBLEM3_H
#define PROBLEM3_H

class Problem3
{
    public:
        Problem3(long long number);
        virtual ~Problem3();
        Problem3(const Problem3& other);
        Problem3& operator=(const Problem3& other);

        long long getLargestPrime();
    protected:
    private:
        long long number;
        bool isPrime(long long);
};

#endif // PROBLEM3_H
