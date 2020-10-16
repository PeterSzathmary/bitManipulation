#include <bitset>
#include <cstdint>
#include <iostream>

constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
constexpr std::uint_fast8_t mask6{ 0b0100'0001 }; // represents bit 6
constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

constexpr std::uint_fast32_t redBits{ 0xFF000000 };
constexpr std::uint_fast32_t greenBits{ 0x00FF0000 };
constexpr std::uint_fast32_t blueBits{ 0x0000FF00 };
constexpr std::uint_fast32_t alphaBits{ 0x000000FF };

void printBits(std::bitset<8U> bits);
void printMore(int times, char c);

int main()
{
    std::bitset<8> bits0{ 0b0000'0101 };     // we need 8 bits, start with bit pattern 0000 0101
    std::bitset<8> bits1{ 0b1001'0101 };     // we need 8 bits, start with bit pattern 1001 0101
    std::bitset<8> bits2{ 0b1101'0101 };     // we need 8 bits, start with bit pattern 1101 0101
    bits0.set(3);                            // set bit position 3 to 1 (now we have 0000 1101)
    bits0.flip(4);                           // flip bit 4 (now we have 0001 1101)
    bits0.reset(4);                          // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits0 << '\n';
    std::cout << "Bit 3 has value: " << bits0.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits0.test(4) << "\n\n";

    // bitwise left shift operator (<<)
    std::cout << "bitwise left shift operator (<<)\n";
    int count{ 3 };
    for (int i{ 1 }; i <= count; i++)
    {
        std::cout << '(' << static_cast<int>(bits0.to_ulong()) << ")\t" << bits0 << " << " << i << " is " << (bits0 << i) << " (" << static_cast<int>((bits0 << i).to_ulong()) << ")\n";
        if (i == count)
        {
            std::cout << '\n';
        }
    }

    // bitwise right shift operator (>>)
    std::cout << "bitwise right shift operator (>>)\n";
    for (int i{ 1 }; i <= count; i++)
    {
        std::cout << '(' << static_cast<int>(bits0.to_ulong()) << ")\t" << bits0 << " >> " << i << " is " << (bits0 >> i) << " (" << static_cast<int>((bits0 >> i).to_ulong()) << ")\n";
        if (i == count)
        {
            std::cout << '\n';
        }
    }

    // bitwise NOT operator (~)
    std::cout << "bitwise NOT operator (~)\n";
    count = 4;
    for (int i{ 0 }; i < count; i++)
    {
        std::cout << '(' << static_cast<int>((bits0 << i).to_ulong()) << ")\t" << '~' << (bits0 << i) << " is " << ~(bits0 << i) << " (" << static_cast<int>((~(bits0 << i)).to_ulong()) << ")\n";
        if (i == count - 1)
        {
            std::cout << '\n';
        }
    }

    // bitwise OR operator (|)
    std::cout << "bitwise OR operator (|)\n";
    printBits(bits0);
    std::cout << "OR\n";
    printBits(bits1);
    std::cout << '\n';
    printMore(bits0.size(), '-');
    std::cout << '\n';
    printBits(bits0 | bits1);
    std::cout << "\n\n";

    // bitwise AND operator (&)
    std::cout << "bitwise AND operator (&)\n";
    printBits(bits0);
    std::cout << "AND\n";
    printBits(bits1);
    std::cout << '\n';
    printMore(bits0.size(), '-');
    std::cout << '\n';
    printBits(bits0 & bits1);
    std::cout << "\n\n";

    // bitwise XOR operator (^)
    std::cout << "bitwise XOR operator (^)\n";
    printBits(bits0);
    std::cout << "XOR\n";
    printBits(bits1);
    std::cout << '\n';
    printMore(bits0.size(), '-');
    std::cout << '\n';
    printBits(bits0 ^ bits1);
    std::cout << "\n\n";

    std::cout << "bitwise XOR operator (^)\n";
    printBits(bits0);
    std::cout << "XOR\n";
    printBits(bits1);
    std::cout << "XOR\n";
    printBits(bits2);
    std::cout << '\n';
    printMore(bits0.size(), '-');
    std::cout << '\n';
    printBits(bits0 ^ bits1 ^ bits2);
    std::cout << "\n\n";

    printMore(30, '*');
    std::cout << '\n';
    printMore(30, '*');
    std::cout << "\n\n";

    // testing a bit (to see if it is on or off)
    std::uint_fast8_t flags{ 0b0000'0101 };
    std::cout << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    std::cout << "turning bit 1 to on\n";

    // setting bits
    // turning on bit 1
    flags |= mask1;
    std::cout << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    // turning on bit 4 and 5
    flags |= (mask4 | mask5);
    std::cout << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");

    // resetting bits
    flags = 0b0000'0101;
    std::cout << '\n' << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    // turn off bit 2
    flags &= ~mask2;
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    std::cout << "\nturning on bit 4 and bit 5";
    flags |= (mask4 | mask5);
    std::cout << '\n' << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "turning off bit 4 and bit 5";
    flags &= ~(mask4 | mask5);
    std::cout << '\n' << static_cast<std::bitset<8>>(flags) << '\n';

    // flipping a bit
    flags = 0b0000'0101;
    std::cout << '\n' << static_cast<std::bitset<8>>(flags) << '\n';
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= (mask7 | mask6);
    std::cout << static_cast<std::bitset<8>>(flags) << '\n';

    std::cout << "\n\t\t****************************************************************************\n";
    std::cout << "\t\t****************************************************************************\n";
    std::cout << "\t\t****************************************************************************\n\n";

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint_fast32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows me to read in a hex value

    // use Bitwise AND to isolate red pixels,
    // then right shift the value into the lower 8 bits
    // (we're not using brace initialization to avoid a static_cast)
    std::uint_fast32_t red = (pixel & redBits) >> 24;
    std::uint_fast32_t green = (pixel & greenBits) >> 16;
    std::uint_fast32_t blue{ (pixel & blueBits) >> 8 };
    std::uint_fast32_t alpha{ pixel & alphaBits };

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    return 0;
}

void printBits(std::bitset<8U> bits)
{
    std::cout << '(' << static_cast<int>(bits.to_ulong()) << ")\t";
    for (int i = bits.size() - 1; i >= 0; i--)
    {
        std::cout << bits[i] << " ";
    }
}

void printMore(int times, char c)
{
    std::cout << '\t';
    for (int i = 0; i < times; i++)
    {
        std::cout << c << " ";
    }
}