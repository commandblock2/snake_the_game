#include "char_snake.h"
#include <thread>

#include <conio.h>

char_snake::char_snake::char_snake(const int width, const int height,
	const int length_strech_per_food,
	const std::chrono::milliseconds regular_interval,
	const std::chrono::milliseconds fast_interval)
{
	game(width, height, length_strech_per_food, regular_interval, fast_interval);
	//explicitly call the base class constructor
}

void char_snake::char_snake::exec()
{
	std::thread([this]() {snake_the_game::game::exec(); }).detach();
	using namespace std::literals::string_literals;
	while (!game_over())
	{
		frame = "";
		const auto& snake_body = get_snake_body();
		//const auto& direction = get_direction();
		const auto& food = get_food();


		frame += "||";
		for (int j = 0; j < width; j++)
			frame += "==";
		frame += "||\n";
		for (int i = 1; i < height + 1; i++)
		{
			frame += "||";
			for (int j = 0; j < width; j++)
				frame += "  ";
			frame += "||\n";
		}
		frame += "||";
		for (int j = 0; j < width; j++)
			frame += "==";
		frame += "||\n";

		for (const auto& elem : snake_body)
			draw_at(elem.first, elem.second, 'O');

		for (const auto& elem : food)
			draw_at(elem.first, elem.second, 'F');

		printf(frame.c_str());

		std::this_thread::sleep_for(100ms);
	}
}

void char_snake::char_snake::draw_at(int x, int y, char c)
{
	frame[(x + 1) * 2 + (y + 1) * (2 * (width + 2) + 1)] = c;
	frame[(x + 1) * 2 + (y + 1) * (2 * (width + 2) + 1) + 1] = c;
}