#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

#include <helper/FileReader.hpp>

// Project Euler - Problem 59
// https://projecteuler.net/problem=59
// XOR decryption
// Result: 129448

using namespace reader;

int countSubstrings(const std::string& text, const std::string& substring)
{
    const auto subLen = substring.size();
    int count = 0;

    for (std::size_t i = 0; i < text.size() - subLen + 1; ++i)
    {
        if (text.substr(i, subLen) == substring)
            ++count;
    }

    return count;
}

auto decryptMessageWithKey(const std::vector<int>& message, const std::string& key) -> std::optional<std::string>
{
    std::string decodedMessage;

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        char c = message[i] ^ key[i % 3];

        if (c < 32 || c == 127) // must be a valid ASCII character
            break;

        decodedMessage.push_back(c);
    }

    // Discard the message if the lengths are not matching (meaning the key produced some invalid characters).
    // Verify the correct result by assuming that a valid English text would contain the word "the" multiple times.
    if (decodedMessage.size() == message.size() && countSubstrings(decodedMessage, " the ") >= 3)
        return decodedMessage;

    return {};
}

int sumCharsInDecryptedMessage(const std::vector<int>& message)
{
    for (char x = 'a'; x <= 'z'; ++x)
    {
        for (char y = 'a'; y <= 'z'; ++y)
        {
            for (char z = 'a'; z <= 'z'; ++z)
            {
                const std::string key = { x, y, z };
                const auto decodedMessage = decryptMessageWithKey(message, key);

                if (decodedMessage.has_value())
                {
                    const auto& originalMessage = decodedMessage.value();
                    //std::cout << originalMessage << std::endl;
                    return std::accumulate(originalMessage.begin(), originalMessage.end(), 0);
                }
            }
        }
    }

    return 0;
}

int main()
{
    std::string filename = "input/euler059input.txt";

    auto input = readNumbers(filename, ',');
    auto result = sumCharsInDecryptedMessage(input.front());
    std::cout << result << std::endl;

    return 0;
}
