#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <helper/MathPackage.hpp>

// Project Euler - Problem 60
// https://projecteuler.net/problem=60
// Prime pair sets
// Result: 26033

using namespace math;

// The solver starts with generation of primes and sets of primes which make prime pairs together.
// Primes are then recursively added to the family (if they make a prime pair with each member of the family)
// until the desired family size is reached.
class PrimePairFamilySolver
{
public:
    PrimePairFamilySolver(int familySize) : familySize_(familySize)
    {
        initPrimePairs();

        for (int i = 0; i < primes_.size() && familySum_ + primes_[i] < minFamilySum_; ++i)
        {
            addToFamily(primes_[i]);
            findNextPrime(i + 1);
            removeFromFamily();
        }
    }

    int getMinFamilySum() const { return minFamilySum_; }

private:
    const int limit_ = 20000; // enough to avoid overflow during integer concatenation
    std::vector<int> primes_;
    std::unordered_map<int, std::unordered_set<int>> pairsStore_;

    const int familySize_;
    int minFamilySum_ = std::numeric_limits<int>::max();
    int familySum_ = 0;
    std::vector<int> family_;

    void initPrimePairs()
    {
        primes_ = sieveOfEratosthenes(limit_);

        for (int i = 0; i < primes_.size(); ++i)
        {
            auto primeIt = pairsStore_.insert(pairsStore_.end(), { primes_[i], {} });

            for (int j = i + 1; j < primes_.size(); ++j)
            {
                if (isPrime(concat(primes_[i], primes_[j])) && isPrime(concat(primes_[j], primes_[i])))
                    primeIt->second.insert(primes_[j]);
            }
        }
    }

    void findNextPrime(int idx)
    {
        for (int i = idx; i < primes_.size() && familySum_ + primes_[i] < minFamilySum_; ++i)
        {
            if (!makesFamily(primes_[i]))
                continue;

            addToFamily(primes_[i]);

            if (family_.size() == familySize_)
                minFamilySum_ = std::min(familySum_, minFamilySum_);

            if (family_.size() < familySize_)
                findNextPrime(i + 1);

            removeFromFamily();
        }
    }

    void addToFamily(int number)
    {
        family_.push_back(number);
        familySum_ += number;
    }

    void removeFromFamily()
    {
        familySum_ -= family_.back();
        family_.pop_back();
    }

    bool makesFamily(int number) const
    {
        for (auto prime : family_)
        {
            const auto& pairs = pairsStore_.find(prime)->second;

            if (pairs.find(number) == pairs.end())
                return false;
        }

        return true;
    }
};

int main()
{
    int count = 5;
    auto result = PrimePairFamilySolver(count).getMinFamilySum();
    std::cout << result << std::endl;

    return 0;
}
