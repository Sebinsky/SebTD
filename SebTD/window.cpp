#include "window.h"

namespace sebtd
{
namespace graphics
{

	bool Window::m_Keys[MAX_KEYS];
	bool Window::m_MouseButtons[MAX_BUTTONS];
	double Window::m_MouseX;
	double Window::m_MouseY;

	void window_resize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		if (!init())
		{
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "<<<GLFW ERROR!>>>" << std::endl;

			return false;
		}
		else
		{
			std::cout << "<<<GLFW INITIALIZED!>>>" << std::endl;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "<<<Failed to create GLFW Window!>>>" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouseButton_callback);
		glfwSetCursorPosCallback(m_Window, cursorPosition_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "<<<Failed to initialize GLEW!>>>" << std::endl;
			return false;
		}
		else
		{
			std::cout << "<<<GLEW INITIALIZED!>>>" << std::endl;
		}

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	bool Window::isKeyPressed(unsigned int keycode)
	{
		if (keycode >= MAX_KEYS)
		{
			return false;
		}

		return m_Keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int keycode)
	{
		if (keycode >= MAX_BUTTONS)
		{
			return false;
		}

		return m_MouseButtons[keycode];
	}

	void Window::getMousePosition(double &x, double &y)
	{
		x = m_MouseX;
		y = m_MouseY;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}

	void window_resize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouseButton_callback(GLFWwindow *window, int button, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursorPosition_callback(GLFWwindow *window, double xpos, double ypos)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		
		win->m_MouseX = xpos;
		win->m_MouseY = ypos;
	}

}
}