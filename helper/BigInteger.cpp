#include "BigInteger.hpp"

#include <algorithm>
#include <numeric>
#include <sstream>

BigInteger::BigInteger(long long number)
{
    if (number == 0)
    {
        digits_.push_back(0);
        return;
    }

    if (number < 0)
    {
        sign_ = false;
        number *= -1;
    }

    while (number > 0)
    {
        digits_.push_back(number % base_);
        number /= base_;
    }
}

BigInteger::BigInteger(const std::string& number)
{
    int startIdx = number[0] == '-';

    if (number.empty() || number.begin() + startIdx == number.end() ||
        std::any_of(number.begin() + startIdx, number.end(), [](char c) { return !isdigit(c); }))
        throw std::runtime_error("Invalid string input");
    
    for (auto it = number.rbegin(); it != number.rend() - startIdx; ++it)
    {
        digits_.push_back(*it - '0');
    }
    
    sign_ = startIdx == 0;
    removeZeros();
}

BigInteger::BigInteger(const BigInteger& other) : 
    digits_(other.digits_), 
    sign_(other.sign_) 
{}

BigInteger::BigInteger(BigInteger&& other) noexcept : 
    digits_(std::move(other.digits_)), 
    sign_(other.sign_) 
{}

BigInteger& BigInteger::operator=(const BigInteger& other)
{
    if (*this == other)
        return *this;

    digits_ = other.digits_;
    sign_ = other.sign_;
    return *this;
}

BigInteger& BigInteger::operator=(BigInteger&& other) noexcept
{
    if (*this == other)
        return *this;

    digits_ = std::move(other.digits_);
    sign_ = other.sign_;
    return *this;
}

void swap(BigInteger& lhs, BigInteger& rhs) noexcept
{
    using std::swap;
    swap(lhs.digits_, rhs.digits_);
    swap(lhs.sign_, rhs.sign_);
}

auto operator<<(std::ostream& os, const BigInteger& bigInteger) -> std::ostream&
{
    if (bigInteger.sign_ == false)
        os << '-';

    for (auto it = bigInteger.digits_.rbegin(); it != bigInteger.digits_.rend(); ++it)
        os << *it;
    
    return os;
}

auto BigInteger::print() const -> std::string
{
    std::stringstream out;
    out << *this;
    return out.str();
}

bool operator==(const BigInteger& lhs, const BigInteger& rhs)
{
    return lhs.sign_ == rhs.sign_ && lhs.digits_ == rhs.digits_;
}

bool operator!=(const BigInteger& lhs, const BigInteger& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const BigInteger& lhs, const BigInteger& rhs)
{
    if (lhs.sign_ != rhs.sign_)
        return lhs.sign_ < rhs.sign_;

    if (lhs.digitCnt() != rhs.digitCnt())
        return lhs.sign_ == true? lhs.digitCnt() < rhs.digitCnt() : lhs.digitCnt() > rhs.digitCnt();

    for (int i = lhs.digitCnt() - 1; i >= 0; --i)
    {
        if (lhs.digits_[i] != rhs.digits_[i])
            return lhs.sign_ == true? lhs.digits_[i] < rhs.digits_[i] : lhs.digits_[i] > rhs.digits_[i];
    }

    return false;
}

bool operator>(const BigInteger& lhs, const BigInteger& rhs)
{
    return rhs < lhs;
}

bool operator<=(const BigInteger& lhs, const BigInteger& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const BigInteger& lhs, const BigInteger& rhs)
{
    return !(lhs < rhs);
}

auto BigInteger::operator++() -> BigInteger&
{
    if (sign_ == false && digits_[0] == 1 && digitCnt() == 1) // special case -1 -> 0
    {
        --digits_[0];    
        changeSign();
    }
    else if (sign_ == true)
    {
        ++digits_[0];
        handleCarry();
    }
    else
    {
        --digits_[0];
        handleBorrow();
        removeZeros();
    }

    return *this;
}

auto BigInteger::operator++(int) -> BigInteger
{
    BigInteger result(*this);
    ++*this;
    return result;
}

auto BigInteger::operator--() -> BigInteger&
{
    if (isZero()) // special case 0 -> -1
    {
        ++digits_[0];
        changeSign();
    }
    else if (sign_ == true)
    {
        --digits_[0];
        handleBorrow();
        removeZeros();
    }
    else
    {
        ++digits_[0];
        handleCarry();
    }

    return *this;
}

auto BigInteger::operator--(int) -> BigInteger
{
    BigInteger result(*this);
    --*this;
    return result;
}

auto BigInteger::operator+(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result += other;
    return result;
}

auto BigInteger::operator+=(BigInteger other) -> BigInteger&
{
    if (other.isZero())
        return *this;

    if (sign_ != other.sign_)
    {
        other.changeSign();
        *this -= other;
    }    
    else
    {
        if (digitCnt() < other.digitCnt())
        {
            digits_.resize(other.digitCnt());
        } 

        for (std::size_t i = 0; i < other.digitCnt(); ++i)
        {
            digits_[i] += other.digits_[i];
        }

        handleCarry();
    }

    return *this;
}

auto BigInteger::operator-(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result -= other;
    return result;
}

auto BigInteger::operator-=(BigInteger other) -> BigInteger&
{
    if (other.isZero())
        return *this;

    if (*this == other)
        return *this = 0;

    if (sign_ != other.sign_)
    {
        other.changeSign();
        *this += other;
    }
    else
    {
        bool needSignChange = false;

        if (*this < other && sign_ == true || *this > other && sign_ == false)
        {
            swap(*this, other);
            needSignChange = true;
        }

        for (std::size_t i = 0; i < other.digitCnt(); ++i)
        {
            digits_[i] -= other.digits_[i];
        }

        handleBorrow();
        removeZeros();

        if (needSignChange)
            changeSign();
    }
    
    return *this;
}

auto BigInteger::operator*(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result *= other;
    return result;
}

auto BigInteger::operator*=(BigInteger other) -> BigInteger&
{
    if (this->isZero())
        return *this;

    if (other.isZero())
        return *this = 0;

    BigInteger result;
    result.digits_.resize(digitCnt() + other.digitCnt());
    result.sign_ = sign_ == other.sign_;

    for (std::size_t i = 0, p = 0; i < other.digitCnt(); ++i, ++p) // long multiplication
    {
        for (std::size_t j = 0; j < digitCnt(); ++j)
        {
            result.digits_[j + p] += digits_[j] * other.digits_[i]; // counter p adjusts position        
        }
    }

    result.handleCarry();
    result.removeZeros();

    return *this = result;
}

auto BigInteger::operator/(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result /= other;
    return result;
}

auto BigInteger::operator/=(BigInteger other) -> BigInteger&
{
    if (other.isZero())
        throw std::logic_error("Cannot divide or mod by zero");
    
    if (this->isZero())
        return *this;

    bool needSignChange = sign_ != other.sign_;
    sign_ = true;
    other.sign_ = true;

    if (*this < other)
        return *this = 0;
    
    BigInteger result;
    BigInteger tmp;

    for (std::size_t i = digitCnt(); i > 0;) // long division
    {
        while (tmp < other && i > 0)
        {
            tmp = tmp * base_ + digits_[--i];
            result *= base_;
        }

        while (tmp >= other) // division by repeated subtraction
        {
            tmp -= other;
            ++result;
        }
    } 
    
    if (needSignChange)
        result.changeSign();

    return *this = result;
}

auto BigInteger::operator%(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result %= other;
    return result;
}

auto BigInteger::operator%=(BigInteger other) -> BigInteger&
{
    if (other.isZero())
        throw std::logic_error("Cannot divide or mod by zero");

    bool needSignChange = sign_ == false;
    sign_ = true;
    other.sign_ = true;

    if (*this == other)
        return *this = 0;

    if (*this < other)
        return *this;

    BigInteger result(*this);
    BigInteger tmp(*this);
    tmp /= other;
    tmp *= other;
    result -= tmp;

    if (needSignChange)
        result.changeSign();

    return *this = result;
}

auto BigInteger::operator^(const BigInteger& other) const -> BigInteger
{
    BigInteger result(*this);
    result ^= other;
    return result;
}

auto BigInteger::operator^=(BigInteger other) -> BigInteger&
{
    if (this->isZero() && (other.isZero() || other.sign_ == false))
        throw std::logic_error("Cannot divide or mod by zero");

    if (this->isZero())
        return *this;

    if (other.isZero())
        return *this = 1;

    if (other.sign_ == false) // supports whole numbers only
        return *this = 0;

    BigInteger result(1);
    BigInteger expBase(*this);

    while (!other.isZero()) // exponentiation by squaring
    {
        if (other.isEven())
        {
            expBase *= expBase;
            other /= 2;
        }
        else
        {
            result *= expBase;
            --other;
        }
    }

    return *this = result;
}

auto BigInteger::digitCnt() const -> std::size_t
{
    return digits_.size();
}

int BigInteger::digitSum() const
{
    return std::accumulate(digits_.begin(), digits_.end(), 0);
}

bool BigInteger::isZero() const
{
    return digits_[0] == 0 && digitCnt() == 1;
}

bool BigInteger::isEven() const
{
    return digits_[0] % 2 == 0;
}

auto BigInteger::reverse() const -> BigInteger
{
    BigInteger result(*this);
    std::reverse(result.digits_.begin(), result.digits_.end());
    result.removeZeros();
    return result;
}

bool BigInteger::isPalindrome() const
{
    for (std::size_t i = 0, j = digitCnt() - 1; i < j; ++i, --j)
    {
        if (digits_[i] != digits_[j])
            return false;
    }

    return true;
}

void BigInteger::changeSign()
{
    sign_ = !sign_;
}

// If the digit is greater or equal to base, adjust it and increase the next digit.
void BigInteger::handleCarry()
{
    for (std::size_t i = 0; i < digitCnt(); ++i)
    {
        if (digits_[i] < base_)
            continue;

        if (i == digitCnt() - 1)
        {
            digits_.push_back(0);
        } 

        digits_[i + 1] += digits_[i] / base_;
        digits_[i] %= base_;
    }
}

// If the digit is negative, adjust it and decrease the next digit.
void BigInteger::handleBorrow()
{
    for (std::size_t i = 0; i < digitCnt(); ++i)
    {
        if (digits_[i] >= 0)
            continue;

        --digits_[i + 1];
        digits_[i] += base_;
    }
}

// Remove starting zeros i.e. 003 -> 3 (this can happen in substraction and multiplication).
void BigInteger::removeZeros()
{
    while (digits_.back() == 0 && digitCnt() > 1)
    {
        digits_.pop_back();
    }

    if (isZero())
        sign_ = true;
}
