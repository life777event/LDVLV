#pragma once

#include <System_inputs.h>

namespace Window
{
	class Inputs : public System::Inputs<sf::Keyboard::Key>::Irx
	{
	public:
		explicit Inputs(sf::RenderWindow& win0);
		virtual void on_rx();

	private:
		sf::RenderWindow& win;
		Inputs(const Inputs& orig); ///< = delete
		Inputs& operator=(const Inputs& orig); ///< = delete
	};

	inline Inputs::Inputs(sf::RenderWindow& win0):
		win(win0)
	{
	};
};