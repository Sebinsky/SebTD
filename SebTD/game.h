#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <chrono>
#include "window.h"
#include "view.h"

namespace sebtd
{
namespace controller
{

#define UPS 60

	class Game
	{
		private:
			graphics::Window &m_Window;
			view::View m_View;

		public: 
			bool running = false;

		private:
			void update();

		public:
			Game(graphics::Window &window);
			~Game();

			void start();
			void run();
			void stop();
			void setView(view::View &view);
	};

}
}