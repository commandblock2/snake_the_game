#pragma once

#include <atomic>
#include <chrono>
#include <list>
#include <vector>
#include <mutex>


namespace snake_the_game
{
	using namespace std::literals::chrono_literals;

	enum class direction
	{
		up, down, left, right
	};

	enum class block
	{
		death, food, none
	};

	class game
	{
	public:
		//type alias section
		using point = std::pair<int, int>;
		//point::first stands for x(horizontal),second for y
		// x positive -> horizontal right, y positive -> verticle down

	protected:
		//constant section
		const int width, height;
		const std::chrono::milliseconds regular_interval;
		const std::chrono::milliseconds fast_interval;

	private:
		//private data section
		std::list<point> body; //front is head and back is tail
		std::vector<point> food;
		mutable std::mutex rwlock;
		bool gameover = false;

		int length_to_strech;

		//atomic
		std::atomic<direction> direction_{direction::right};
		std::atomic<bool> instant_tick{false};
		std::atomic<std::chrono::milliseconds> interval;

	public:
		game(const int width = 20, const int height = 20,
			const int length_strech_per_food = 3,
			const std::chrono::milliseconds regular_interval = 500ms,
			const std::chrono::milliseconds fast_interval = 200ms);

	protected:
		void exec();
		const std::list<point> get_snake_body() const;
		const std::vector<point> get_food() const;
		//const snake_the_game::direction& get_direction() const;

		void on_key_down(snake_the_game::direction d);
		void on_key_up();

		bool game_over();

	private:
		const point cauculate_next_pos();
		void advance_snake();
		block check_available(const point& position) const;

	};
}
