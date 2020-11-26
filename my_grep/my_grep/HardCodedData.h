#ifndef HARD_CODED_DATA_H
#define HARD_CODED_DATA_H

#define MAX_BUFFER 4096
// Options_flags is a global enum to numerate the option flags
// therefore we declare it in the Hard Coded Data header
enum Option_Flags 
{
	_i = 0b10000000,
	_v = 0b01000000,
	_n = 0b00100000,
	_b = 0b00010000,
	_x = 0b00001000,
	_A = 0b00000100,
	_c = 0b00000010,
	_E = 0b00000001
};

#endif // !HARD_CODED_DATA_H




