#pragma once
#include "snake_the_game.h"
#include <chrono>

namespace SFML_snake
{
	using namespace std::literals::chrono_literals;

	class SFML_snake : public snake_the_game::game
	{
		static constexpr int piexels_per_block = 40;
		static constexpr int border_width_block = 1;
		const int window_width,window_height;

	public:
		SFML_snake(const int width = 20, const int height = 20,
			const int length_strech_per_food = 3,
			const std::chrono::milliseconds regular_interval = 500ms,
			const std::chrono::milliseconds fast_interval = 200ms);
		
		void exec(); //name hiding
	private:
		const std::pair<int,int> cauculate_lefttop_position(const point & point);
	};
}