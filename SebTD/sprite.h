#pragma once

namespace sebtd
{
namespace sprite
{

	class Sprite
	{
		public:
			unsigned int value; // TODO: maybe make a bitmask
			float rValue;
			float gValue;
			float bValue;
			float aValue;
			bool isSolid; // TODO


			// sprites
			static const Sprite GRASS;
			static const Sprite DIRT;

		public:
			Sprite(unsigned int value, float rValue, float gValue, float bValue, float aValue);
			~Sprite();
	};

	// sprites
	//const Sprite Sprite::grass = Sprite(0, 0.3f, 0.6f, 0.0f, 1.0f);
	//const Sprite Sprite::dirt = Sprite(1, 0.6f, 0.3f, 0.0f, 1.0f);
}
}