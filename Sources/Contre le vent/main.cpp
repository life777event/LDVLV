
#include <SFML/Graphics.hpp>

namespace
{
	using namespace sf;
	using namespace std;

	static const uint16_t WIN_WIDTH = 1920;
	static const uint16_t WIN_HEIGHT = 1080;
	static const uint16_t WIN_BPPX = 32;
	static const string WIN_TITLE("Contre le vent");
}

int main(int argc, char* argv[])
{
	RenderWindow win(VideoMode(WIN_WIDTH, WIN_HEIGHT, WIN_BPPX), WIN_TITLE);

	while (win.isOpen())
	{
		win.clear();
		//win.draw();
		win.display();
	};

	return 0;
}