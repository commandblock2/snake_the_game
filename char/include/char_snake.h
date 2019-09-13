#pragma once
#include "snake_the_game.h"
#include <string>

namespace char_snake
{
	using namespace std::literals::chrono_literals;


	class char_snake : public snake_the_game::game
	{
	private:
		std::string frame;

	public:
		char_snake(const int width = 20, const int height = 20,
			const int length_strech_per_food = 3,
			const std::chrono::milliseconds regular_interval = 500ms,
			const std::chrono::milliseconds fast_interval = 200ms);
		void exec();//note: hide snake_the_game::game::exec function
	private:
		void draw_at(int x, int y, char c);
	};
}