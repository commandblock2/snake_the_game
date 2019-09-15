#include "SFML_snake.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <thread>
#include <utility>

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
    
	std::thread([this](){snake_the_game::game::exec();}).detach();

	while ((!game_over()) && window.isOpen())
	{
		window.clear();
		const auto& snake_body = get_snake_body();
		const auto& food = get_food();

		for (auto i = std::next(snake_body.end(),-1); 
             i != std::next(snake_body.begin()); --i)
		{
			const auto block_begin = cauculate_lefttop_position(*i);
            
			const auto [square_begin_x,square_begin_y] = 
				std::tuple{block_begin.first + piexels_per_block / 10 * 2
				,block_begin.second + piexels_per_block / 10 * 2};
                
			const int square_length = piexels_per_block / 10 * 6;
            
			sf::RectangleShape rect(sf::Vector2f(square_length,square_length));
			rect.setPosition(square_begin_x,square_begin_y);
			rect.setFillColor(sf::Color::Red);
            
			window.draw(rect);
			
			//draw the connection
            
		}
		
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::KeyBoardPressed)
				switch(event.key.code)
				{
					case sf::Keyboard::W:
						break;
					case sf::Keyboard::W:
						break;
					case sf::Keyboard::W:
						break;
					case sf::Keyboard::W:
						break;
					default:
						break;
				}
			else if (event.type == sf::Event::KeyboardReleased)
				on_key_up();
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
