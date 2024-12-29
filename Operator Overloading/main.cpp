#include <iostream>

using namespace std;

class complex
{
private:
    int img, real;

public:
    // Constructors
    complex()
    {
        img = real = 0;
    }
    complex(int m)
    {
        img = real = m;
    }
    complex(int m, int n)
    {
        real = m;
        img = n;
    }
    complex(const complex &rst) // Copy constructor
    {
        real = rst.real;
        img = rst.img;
    }

    // Setters
    void set_real(int r)
    {
        real = r;
    }
    void set_img(int i)
    {
        img = i;
    }

    // Getters
    int get_real() const
    {
        return real;
    }
    int get_img() const
    {
        return img;
    }

    // Overloaded operators
    complex operator+(const complex &c);         // Add two complex numbers
    complex operator+(int m);                   // Add an integer to the complex number
    complex operator++();                       // Prefix increment
    complex operator++(int);                    // Postfix increment
    bool operator==(const complex &c) const;    // Check equality
    complex &operator=(const complex &c);       // Assignment operator
    friend complex operator+(int m, const complex &c); // Add int + complex (friend function)
    operator int();                             // Conversion operator to int
};

// Definition of overloaded operators
complex complex::operator+(const complex &c)
{
    complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

complex complex::operator+(int m)
{
    complex temp;
    temp.real = real + m;
    temp.img = img;
    return temp;
}

complex complex::operator++() // Prefix increment
{
    real++;
    img++;
    return *this; // Return the updated object
}

complex complex::operator++(int) // Postfix increment
{
    complex old = *this; // Save the current state
    real++;
    img++;
    return old; // Return the old state
}

bool complex::operator==(const complex &c) const
{
    return ((real == c.real) && (img == c.img));
}

complex &complex::operator=(const complex &c)
{
    if (this != &c) // Avoid self-assignment
    {
        real = c.real;
        img = c.img;
    }
    return *this;
}

complex operator+(int m, const complex &c)
{
    complex temp;
    temp.real = m + c.real;
    temp.img = c.img;
    return temp;
}

complex::operator int()
{
    return real; // Convert to the real part
}

// Main function to test the class
int main()
{
    // Test constructors
    complex c1(3, 6), c2(2, 4), c3;

    // Test addition
    c3 = c1 + c2;
    cout << "c1 + c2 = (" << c3.get_real() << ", " << c3.get_img() << ")\n";

    // Test addition with an integer
    c3 = c1 + 5;
    cout << "c1 + 5 = (" << c3.get_real() << ", " << c3.get_img() << ")\n";

    // Test prefix increment
    ++c1;
    cout << "++c1 = (" << c1.get_real() << ", " << c1.get_img() << ")\n";

    // Test postfix increment
    c3 = c1++;
    cout << "c1++ = (" << c3.get_real() << ", " << c3.get_img() << ")\n";
    cout << "After c1++ = (" << c1.get_real() << ", " << c1.get_img() << ")\n";

    // Test equality
    bool isEqual = (c1 == c2);
    cout << "c1 == c2: " << (isEqual ? "True" : "False") << "\n";

    // Test assignment
    c3 = c2;
    cout << "After c3 = c2: (" << c3.get_real() << ", " << c3.get_img() << ")\n";

    // Test addition using friend function
    c3 = 10 + c1;
    cout << "10 + c1 = (" << c3.get_real() << ", " << c3.get_img() << ")\n";

    // Test conversion operator
    int realPart = c1;
    cout << "Real part of c1: " << realPart << "\n";

    return 0;
}
