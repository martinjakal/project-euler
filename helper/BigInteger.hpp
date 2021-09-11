#pragma once
#include <string>
#include <vector>

// Represents a large number and supports basic arithmetic operations.
class BigInteger
{
public:
    BigInteger() : BigInteger(0) {};
    BigInteger(long long number);
    BigInteger(const std::string& number);
    BigInteger(const BigInteger& other);
    BigInteger(BigInteger&& other) noexcept;
    BigInteger& operator=(const BigInteger& other);
    BigInteger& operator=(BigInteger&& other) noexcept;
    ~BigInteger() {};

    friend void swap(BigInteger& lhs, BigInteger& rhs) noexcept;
    friend auto operator<<(std::ostream& os, const BigInteger& bigInteger) -> std::ostream&;
    auto print() const -> std::string;

    friend bool operator==(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator!=(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator< (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator> (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator<=(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator>=(const BigInteger& lhs, const BigInteger& rhs);

    auto operator++() -> BigInteger&;
    auto operator++(int) -> BigInteger;
    auto operator--() -> BigInteger&;
    auto operator--(int) -> BigInteger;

    auto operator+(const BigInteger& other) const -> BigInteger;
    auto operator-(const BigInteger& other) const -> BigInteger;
    auto operator*(const BigInteger& other) const -> BigInteger;
    auto operator/(const BigInteger& other) const -> BigInteger;
    auto operator%(const BigInteger& other) const -> BigInteger;
    auto operator^(const BigInteger& other) const -> BigInteger;

    auto operator+=(BigInteger other) -> BigInteger&;
    auto operator-=(BigInteger other) -> BigInteger&;
    auto operator*=(BigInteger other) -> BigInteger&;
    auto operator/=(BigInteger other) -> BigInteger&;
    auto operator%=(BigInteger other) -> BigInteger&;
    auto operator^=(BigInteger other) -> BigInteger&;

    auto digitCnt() const -> std::size_t;
    int digitSum() const;
    bool isZero() const;
    bool isEven() const;
    auto reverse() const -> BigInteger;
    bool isPalindrome() const;

private:
    std::vector<int> digits_; // digits are stored in reversed order
    bool sign_ = true;
    const int base_ = 10;

    void changeSign();
    void handleCarry();
    void handleBorrow();
    void removeZeros();
};
