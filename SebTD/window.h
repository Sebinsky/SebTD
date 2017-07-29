#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace sebtd
{
namespace graphics
{

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window
	{
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double m_MouseX, m_MouseY;

		private:
			bool init();

			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouseButton_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursorPosition_callback(GLFWwindow *window, double xpos, double ypos);

		public:
			Window(const char *name, int width, int height);
			~Window();
			bool closed() const;
			void clear() const;
			void update();

			int getWidth() const { return m_Width; };
			int getHeight() const { return m_Height; };

			static bool isKeyPressed(unsigned int keycode);
			static bool isMouseButtonPressed(unsigned int keycode);
			static void getMousePosition(double &x, double &y);
	};

}
}