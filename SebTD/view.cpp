#include "view.h"
#include "sprite.h"

namespace sebtd
{
namespace view
{

	View::View()
	{

	}

	View::~View()
	{

	}

	void View::render()
	{
		renderMap();
		renderUI();
	}

	void View::renderMap()
	{
		// for now the map is a 32/18 grid (should be fitting for 16/9 filled with squares)

		float xFactor = 2.0f / 32.0f;
		float yFactor = 2.0f / 18.0f;

		float y = 1.0f;

		for (int i = 0; i < 18; i++)
		{
			float x = -1.0f;

			for (int j = 0; j < 32; j++)
			{
				glBegin(GL_QUADS);

				glColor4f(sprite::Sprite::GRASS.rValue, 
					sprite::Sprite::GRASS.gValue, 
					sprite::Sprite::GRASS.bValue, 
					sprite::Sprite::GRASS.aValue);

				glVertex2f(x, y - yFactor);
				glVertex2f(x, y);
				glVertex2f(x + xFactor, y);
				glVertex2f(x + xFactor, y - yFactor);

				glEnd();

				x += xFactor;
			}

			y -= yFactor;
		}


		//sprite::Sprite::grass;
	}

	void View::renderUI()
	{
	}

}
}