#pragma once

#include "Block.h"

class Grass : public Block
{
public:
	Grass();
	void draw() override;
private:
	float anim;
};