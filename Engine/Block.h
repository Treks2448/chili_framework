#pragma once

#include "Vector2D.h"
#include <random>
#include "Graphics.h"
#include "Board.h"
#include "Keyboard.h"

class Block
{
public:
	/* Generates a random block type and assigns it the coordinates*/
	Block();

	/* Draws the block on the board*/
	void Draw(Graphics& gfx, Board& board) const;

	/* Used to set the coordinate of the center of the block */
	void SetCenterPosition(Vector2D centerPosition);

	/* Handles falling of the block*/
	void Fall();

	/* Handles rotation of the block*/
	void Rotate();

	/* Handles movement of the brick*/
	void Move(Vector2D direction);

	/* Checks if the block is on top of another block. Returns true if this is the case*/
	bool IsOnTop(Block& block);

	/* Checks if the block*/
	bool IsAtBottom(int bottomY);

	/* Returns the coordinates of the ith element of the block*/
	Vector2D GetBlockCoordinates(int i) const;

	bool IsFalling();

private:
	/* Position of the central cell of the block */
	Vector2D CenterPosition = { 4,3 };

	/* The number of cells that the blocks are made out of */
	static constexpr int BlockSize = 4;

	/* Shows whether the brick is falling or stationary */
	bool bIsFalling = true;

	/* Set of coordinates of each cell of the block*/
	Vector2D BlockCoordinates[BlockSize];

	Keyboard kbd;

};