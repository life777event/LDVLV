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
		Inputs();

		/// Add listener.
		void add_rx(std::vector<typename C> ins, Irx* irx);

		/// Step to get input from window and forward to relevant listeners.
		void step(C in);

	private:
		sf::WindowBase& win;			///< Window, to poll events.
		std::map<typename C, Irx*> map;	///< Map of keys/listener.

		Inputs(const Inputs& orig); ///< = delete
		Inputs& operator=(const Inputs& orig); ///< = delete
	};

	template <typename C>
	Inputs<C>::Inputs()
	{
	};

	template <typename C>
	void Inputs<C>::add_rx(std::vector<typename C> ins, Irx* irx)
	{
		for(C in : ins)
		{
			map.insert(in, irx);
		}
	};

	template <typename C>
	void Inputs<C>::step(C in)
	{
		if(map.count(in))
		{
			for (Irx* irx : map.at(in))
			{
				irx->on_rx();
			}
		}
	};
};