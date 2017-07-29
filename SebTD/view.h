#pragma once

#include <GLFW\glfw3.h>

namespace sebtd
{
namespace view
{

	class View
	{
		private:
			void renderMap();
			void renderUI();

		public:
			View();
			~View();

			void render();
	};

}
}