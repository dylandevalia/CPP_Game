#pragma once
class Utility {
public:
	/*
	Remaps a number from one range to another
	
	@param value  The number to remap to the new range
	@param start1 The start of the first range
	@param stop1  The end of the first range
	@param start2 The start of the second range
	@param stop2  The end of the second range
	
	@return The initial value remapped from the first range to the second
	*/
	static int map(int value, int start1, int stop1, int start2, int stop2) {
		return ((value - start1) / (stop1 - start1))*(stop2 - start2) + start2;
	}

	static int sign(int value) {
		if (value > 0) {
			return 1;
		} else if (value < 0) {
			return -1;
		}
		return 0;
	}
};

