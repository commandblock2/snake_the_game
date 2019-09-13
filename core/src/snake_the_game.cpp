#include "snake_the_game.h"

#include <cassert>

#include <thread>
#include <mutex>

using point = snake_the_game::game::point;

snake_the_game::game::game(const int width, const int height,
	const int length_strech_per_food,
	const std::chrono::milliseconds regular_interval,
	const std::chrono::milliseconds fast_interval) :
	width(width), height(height), regular_interval(regular_interval), fast_interval(fast_interval),
	interval(regular_interval), length_to_strech(length_strech_per_food)
{
	body.push_front({ 0,0 });
}

void snake_the_game::game::exec()
{
	using namespace std::literals::chrono_literals;

	while (check_available(body.front()) != block::death)
	{
		advance_snake();

		//at last
		if (!instant_tick)
			std::this_thread::sleep_for(interval.load());
		else
			instant_tick = false;
	}
	gameover = true;
}

const std::list<point>& snake_the_game::game::get_snake_body() const
{
	std::lock_guard guard(rwlock);
	return body;
}

const std::vector<point>& snake_the_game::game::get_food() const
{
	std::lock_guard guard(rwlock);
	return food;
}

const snake_the_game::direction& snake_the_game::game::get_direction() const
{
	std::lock_guard guard(rwlock);
	return direction;
}

void snake_the_game::game::on_key_down(snake_the_game::direction & d)
{
	direction = d;
	interval = fast_interval;
	instant_tick = true;
}

void snake_the_game::game::on_key_up()
{
	interval = regular_interval;
}

const point snake_the_game::game::cauculate_next_pos()
{
	point head = body.front();
	switch (direction)
	{
	case direction::up:
		head.second--;
		break;
	case direction::down:
		head.second++;
		break;
	case direction::left:
		head.first--;
		break;
	case direction::right:
		head.first++;
		break;
	default:
		assert(false); // doesn't exist
		break;
	}
	return head;
}

void snake_the_game::game::advance_snake()
{
	std::lock_guard guard(rwlock);
	body.push_front(cauculate_next_pos());
	if (length_to_strech)
		length_to_strech--;
	else
		body.pop_back();
}

snake_the_game::block snake_the_game::game::check_available(const point& position) const
{
	std::lock_guard guard(rwlock);
	bool dead = (position.first < 0) || (position.first > width) ||
		(position.second < 0) || (position.second > height) ||
		(std::count(body.begin(), body.end(), position) == 0);
	bool food_exist = std::count(food.begin(), food.end(), position);

	return dead ? block::death : (food_exist ? block::food : block::none);
}

bool snake_the_game::game::game_over()
{
	return gameover;
}