#include <iostream>

int nod(int); // прототип указываемой функции

int main()
{
    setlocale(LC_ALL, "Russian");
    bool tr = true;         // 00
    bool fl = false;        // 01
    char r = 'r';           // 72
    char R = 'р';           // f0
    wchar_t wr = L'r';      // 72 00
    wchar_t wR = L'р';      // 40 04
    short x = 13;           // 0d 00
    short m_x = -13;        // f3 ff
    short max = SHRT_MAX;   // ff 7f
    short min = SHRT_MIN;   // 00 80
    unsigned short umax = USHRT_MAX;// ff ff
    unsigned short umin = 0;// 00 00
    int y = 21;             // 15 00 00 00
    int m_y = -21;          // eb ff ff ff
    int max_i = INT_MAX;    // ff ff ff 7f
    int min_i = INT_MIN;    // 00 00 00 80
    unsigned int umax_i = UINT_MAX;// ff ff ff ff
    unsigned int umin_i = 0;// 00 00 00 00
    long z = 22;            // 16 00 00 00
    long m_z = -22;         // ea ff ff ff
    long max_l = LONG_MAX;  // ff ff ff 7f
    long min_l = LONG_MIN;  // 00 00 00 80
    unsigned long umax_l = ULONG_MAX;// ff ff ff ff
    unsigned long umin_l = 0;// 00 00 00 00
    float s = 12.234;       // 77 be 43 41
    float m_s = -12.234;    // 77 be 43 c1

    float f1 = 23.625f;     // 00 00 bd 41
    float f2 = -23.625f;    // 00 00 bd c1
    float f3 = f1 / 0;      // 00 00 80 7f
    float f4 = f2 / 0;      // 00 00 80 ff
    float f5 = sqrt(-2.0f); // 00 00 c0 ff
    double dbl = 123.567;   // 3f 35 5e ba 49 e4 5e 40

    char* ptrr = &r;        // ef f6 55 00
    wchar_t* ptrwr = &wr;   // d4 f6 55 00
    short* ptrx = &x;       // bc f6 55 00
    int* ptry = &y;         // 74 f6 55 00
    float* ptrs = &s;       // e4 f5 55 00
    double* ptrdbl = &dbl;  // 8c f5 55 00

    int (*ptrnod)(int) = nod;// 29 14 b0 00         
    std::cout << "Hello World!\n";
}
int nod(int number)
{
        return number * number;
}