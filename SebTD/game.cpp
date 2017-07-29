#include "game.h"

namespace sebtd
{
namespace controller
{

	Game::Game(graphics::Window &window)
		:m_Window(window)
	{
		m_View = view::View();
	}

	Game::~Game()
	{
		stop();
	}

	void Game::start()
	{
		running = true;

		run();
	}

	void Game::run()
	{
		// time when the method is first started in milliseconds
		unsigned long long lastTime = std::chrono::system_clock::now().time_since_epoch() 
			/ std::chrono::nanoseconds(1);
        unsigned long long timer = std::chrono::system_clock::now().time_since_epoch() 
			/ std::chrono::milliseconds(1);
        // create quotient
        double ns = 1000000000.0 / UPS;
        // difference between start time and current time
        double delta = 0;
        // counter for frames per second
        int frames = 0;
        // counter for updates per second
        int updates = 0;

        while (running && !m_Window.closed())
        {
            unsigned long long now = std::chrono::system_clock::now().time_since_epoch() 
			/ std::chrono::nanoseconds(1);
            // add up the times of every loop run and get the value in seconds /
            // 60 (basically increase by 1/60th of a second every loop)
            delta += (now - lastTime) / ns;
            lastTime = now;
            // gets called 60 times per second because of delta calculation
            while (delta >= 1)
            {
                update();
                updates++;
                delta--;
            }



			glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
			//<<<<THIS PART SHOULD BE IN view.render()
			m_Window.clear();

			m_View.render();

			m_Window.update();
			//<<<<

            frames++;
            
            // gets called every second
            if ((std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1)) 
				- timer > 1000)
            {
                // "reset" timer variable
                timer += 1000;
				std::cout << updates << " ups, " << frames << " fps" << std::endl;

                // reset frames and updates variables to start counting from 0
                // at the start of every second
                frames = 0;
                updates = 0;
            }
        }
	}

	void Game::stop()
	{
		running = false;
	}

	void Game::update()
	{

	}

	void Game::setView(view::View &view)
	{
		m_View = view;
	}

}
}