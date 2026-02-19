#pragma once

// Class Managing Matrix Position.
class Location2D
{
public:
	// row(세로)
	int row = 0;

	// column (가로)
	int col = 0;

public:
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}
};