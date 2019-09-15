#include "SFML_snake.h"
#include <SFML/Graphics.hpp>

SFML_snake::SFML_snake::SFML_snake(const int width, const int height,
	const int length_strech_per_food,
	const std::chrono::milliseconds regular_interval,
	const std::chrono::milliseconds fast_interval) :
	window_width(piexels_per_block* (width + border_width_block * 2)),
	window_height(piexels_per_block* (height + border_width_block * 2))
{
	game(width, height, length_strech_per_food, regular_interval, fast_interval);
	//explicitly call the base class constructor
}

void SFML_snake::SFML_snake::exec()
{
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "snake the game(SFML)");


	while ((!game_over()) && window.isOpen())
	{
		sf::RenderTexture render_texture;

		render_texture.create(window_width, window_height);

		const auto& snake_body = get_snake_body();
		const auto& food = get_food();

		for (auto i = snake_body.begin(); i != snake_body.end(); ++i)
		{
			const auto [x, y] = cauculate_lefttop_position(*i);
		}


		window.display();
	}
}

const std::pair<int, int> SFML_snake::SFML_snake::cauculate_lefttop_position(const point& point)
{
	const auto [x, y] = point;
	return { (x+ border_width_block) * piexels_per_block,
		(y + border_width_block) * piexels_per_block };
}