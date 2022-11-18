#include <iostream>
using namespace std;

namespace ct01
{
    void test(void)
    {
        // signed char a = 300;
        // unsigned char b = -300;

        // clog << (int)a << endl;
        // clog << (int)b << endl;
    }
}

namespace ct02
{
    void test(void)
    {
        unsigned u = 10;
        int i = -42;

        clog << i + i << endl;
        clog << u + i << endl;
    }
}

namespace ct03
{
    void test(void)
    {
        unsigned u1 = 42, u2 = 10;

        clog << u1 - u2 << endl;
        clog << u2 - u1 << endl;
    }
}

namespace ct04
{
    void test(void)
    {
        for (int i = 10; i >= 0; --i)
            cout << i << endl;

        unsigned u = 11;
        while (u > 0)
        {
            --u;
            cout << u << endl;
        }
    }
}

namespace ct05
{
    void exercise(void)
    {
        unsigned u = 10, u2 = 42;
        cout << u2 - u << endl;
        cout << u - u2 << endl;

        int i = 10, i2 = 42;
        cout << i2 - i << endl;
        cout << i - i2 << endl;

        cout << i - u << endl;
        cout << u - i << endl;
    }
}

namespace ct06
{
    void test(void)
    {
        unsigned int a = 20, b = 024, c = 0x14;

        cout << a << endl;
        cout << b << endl;
        cout << c << endl;

        cout << hex << a << ' ' << b << ' ' << c << ' ' << endl;
        cout << oct << a << ' ' << b << ' ' << c << ' ' << endl;
    }
}

namespace ct07
{
    void test(void)
    {
        char16_t string_with_unicode_16[] = u"unicode 16 character";
        char32_t string_with_unicode_32[] = U"unicode 32 character";
        wchar_t string_with_wide[] = L"wide character";
        char string_with_utf8[] = u8"utf-8(string literals only)";

        cout << string_with_unicode_16 << endl;
        cout << string_with_unicode_32 << endl;
        cout << string_with_wide << endl;
        cout << string_with_utf8 << endl;

        auto i = -1U;
        auto j = 100L;
        auto k = 100;
        auto n = 100LL;

        cout << i << endl;
        cout << sizeof(j) << endl;
        cout << sizeof(k) << endl;
        cout << sizeof(n) << endl;

        auto g = 1.0F;
        auto q = 1.0L;

        cout << g << endl;
        cout << q << endl;
    }
}

int main()
{
    unsigned j = 10;
    int i = j;
    cout << i << endl;

    return 0;
}