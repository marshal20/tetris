#include "Objects.hpp"

namespace Constants
{
	const int NumberOfPoss = 7;

	namespace Patterns
	{
		const char* I = "1111";
		const char* J = "111\n001";
		const char* L = "111\n1";
		const char* O = "11\n11";
		const char* S = "011\n11";
		const char* T = "111\n01";
		const char* Z = "11\n011";

		const char* Poss[] = { I, J, L, O , S, T, Z };
	}

	namespace Color
	{
		const sf::Color I = sf::Color(000, 255, 255);
		const sf::Color J = sf::Color(000, 000, 255);
		const sf::Color L = sf::Color(255, 165, 000);
		const sf::Color O = sf::Color(255, 255, 000);
		const sf::Color S = sf::Color(000, 255, 000);
		const sf::Color T = sf::Color(128, 000, 128);
		const sf::Color Z = sf::Color(255, 000, 000);

		const sf::Color Poss[] = { I, J, L, O , S, T, Z };
	}

	namespace Origin
	{
		const sf::Vector2i I = { 2, 0 };
		const sf::Vector2i J = { 2, 0 };
		const sf::Vector2i L = { 0, 0 };
		const sf::Vector2i O = { -1, -1 };
		const sf::Vector2i S = { 1, 1 };
		const sf::Vector2i T = { 1, 0 };
		const sf::Vector2i Z = { 1, 1 };

		const sf::Vector2i Poss[] = { I, J, L, O , S, T, Z };
	}
}