#include <iostream>
#include <limits.h>
#include <float.h>
#include <windows.h>
#include <math.h>
using namespace std;

int getSum(int x, int y) {
	return x + y;
}

int main() {
	setlocale(LC_CTYPE, "Russian");

	//объявление переменных
	int n = 10, X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 11.0;

	//4 (bool 1 байт)
	bool tr = true;//tr = 01;
	bool fal = false;//fal = 00;

	//5,6 (char 1 байт)
	char eng_second_letter = 'i';//eng = 69;
	char ru_second_letter = 'и';//ru = e8;

	//7,8 (wchar_t 2 байта)
	wchar_t eng_first_letter = 'L';//eng = 4c 00;
	wchar_t ru_first_letter = 'L';//ru = 1b 04;

	//9  short(unsigned short) (2 байта)
	short n_short_p = X; //DEC(19) -> HEX(13)
	short n_short_m = -X; //DEC(-19) -> BIN(10010011) -> 11101100 -> BIN(11101101) -> HEX(ed)

	//10
	short min_short = 0x8000;//min_short = -32767, HEX(8000);
	short max_shotr = 0x7fff;//max_shotr = 32768, HEX(7FFF);

	//11
	unsigned short min_unsigned_short = 0x0;//min_unsigned_short = 0, HEX(0);
	unsigned short max_unsigned_short = 0xffff;//max_unsigned_short = 65535, HEX(ffff);

	//12 int(unsigned int) (4 байта)
	int n_int_p = Y;//DEC(20) -> HEX(14)
	int n_int_m = -Y;//DEC(-20) -> BIN(10010100) -> 11101011 -> BIN(11101100) -> HEX(ec)

	//13
	int min_int = 0x80000001; //DEC(-2147483647) -> HEX(80000001)
	int max_int = 0x7fffffff; //DEC(2147483647) -> HEX(7fffffff)

	//14
	unsigned int min_unsigned_int = 0x0; //HEX(0)
	unsigned int max_unsigned_int = 0xffffffff; //DEC(4294967295) -> HEX(ffffffff)

	//15 long(unsigned long) (4 байта)
	long n_long_p = Z; // DEC(21) -> HEX(15)
	long n_long_m = -Z; // DEC(-21) -> BIN(10010101) -> 11101010 -> BIN(11101011) -> HEX(eb)

	//16
	long min_long = 0x80000001; //DEC(-2147483647) -> HEX(80000001)
	long max_long = 0x7fffffff; //DEC(2147483647) -> HEX(7fffffff)

	//17
	unsigned long min_unsigned_long = 0x0; // HEX(0)
	unsigned long max_unsigned_long = 0xffffffff; //DEC(4294967295) -> HEX(ffffffff)

	//18 float (4 байта)
	float n_float_p = S; // 41 30 00 00       
	float n_float_m = -S; // c1 30 00 00   

	//19
	float f1 = S / 0; // #INF
	float f2 = -S / 0; // -#INF
	double f3 = sqrt(-13.0); // -#IND

	//20
	char c01 = 'c';
	wchar_t wc01 = L'c';
	short s01 = 18;
	int i01 = 180;
	float f01 = 18.1;
	double d01 = 18.0001;

	char* yc = &c01; // 47 f9 6f 00
	wchar_t* ywc = &wc01; // 38 f9 6f 00
	short* ys = &s01; // 2c f9 6f 00
	int* yi = &i01; //20 f9 6f 00
	float* yf = &f01; //74 f9 6f 00
	double* yd = &d01;//64 f9 6f 00

	char* yc1 = yc + 3; // 4a f9 6f 00
	wchar_t* ywc1 = ywc + 3; // 3e f9 6f 00
	short* ys1 = ys + 3; // 32 f9 6f 00
	int* yi1 = yi + 3; // 2c f9 6f 00 
	float* yf1 = yf + 3; // 80 f9 6f 00
	double* yd1 = yd + 3; // 7c f9 6f 00

	int(*pointer_on_function)(int x, int y) = getSum;
	pointer_on_function(2, 3);
}
