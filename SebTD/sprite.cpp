//for now sprites just have one color and a size
#include "sprite.h"

namespace sebtd
{
namespace sprite
{

	const Sprite Sprite::GRASS = Sprite(0, 0.3f, 0.6f, 0.0f, 1.0f);
	const Sprite Sprite::DIRT = Sprite(1, 0.6f, 0.3f, 0.0f, 1.0f);

	Sprite::Sprite(unsigned int value, float rValue, float gValue, float bValue, float aValue)
	{
		//github test
		rValue = rValue;
		gValue = gValue; 
		bValue = bValue;
		aValue = aValue;
	}

	Sprite::~Sprite()
	{
	}

}
}