#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace System
{
	/// Class to handle the system inputs (keyboard and mouse).
	class Inputs
	{
	public:
		struct Irx
		{
			virtual void on_rx();
		};

		/// Constructor, with window.
		explicit Inputs(sf::WindowBase& win0);

		/// Add listener.
		typedef sf::Mouse::Button Mouse_event;
		typedef sf::Keyboard::Key Keyboard_event;
		void add_mouse_list(std::vector<Mouse_event> ins, Irx* irx);
		void add_keyboard_list(std::vector<Keyboard_event> ins, Irx* irx);

		/// Step to get input from window and forward to relevant listeners.
		void step();

	private:
		sf::WindowBase& win;								///< Window, to poll events.

		typedef std::map<Mouse_event, Irx*> Mouse_listener;
		typedef std::map<Keyboard_event, Irx*> Keyboard_listener;
		Mouse_listener		mouse_list;		///< Map of listener for mouse.
		Keyboard_listener	keyboard_list;	///< Map of listener for mouse.

		template <typename IN>
		static void add_list(std::vector<IN> ins, Irx* irx, std::map<IN, Irx*>& map);

		Inputs(const Inputs& orig); ///< = delete
		Inputs& operator=(const Inputs& orig); ///< = delete
	};

	template <typename IN>
	void Inputs::add_list<IN>(std::vector<IN> ins, Irx* irx, std::map<IN, Irx*>& map)
	{
		for(IN in : ins)
		{
			map.insert({ in, irx });
		}
	}

	inline Inputs::Inputs(sf::WindowBase& win0) :
		win(win0)
	{
	};

	inline void Inputs::add_mouse_list(std::vector<sf::Mouse::Button> ins, Irx* irx)
	{
		add_list(ins, irx, mouse_list);
	};

	inline void Inputs::add_keyboard_list(std::vector<Keyboard_event> ins, Irx* irx)
	{
		add_list(ins, irx, keyboard_list);
	};

	inline void Inputs::step()
	{
		sf::Event tmp;
		if(win.pollEvent(tmp))
		{
			if((tmp.type == sf::Event::MouseButtonPressed) && mouse_list.count(static_cast<sf::Event::KeyEvent>(tmp.key)))
			{

			}
			else if(tmp.type == sf::Event::KeyPressed)
			{

			}
			else
			{

			}
		}
	}
};