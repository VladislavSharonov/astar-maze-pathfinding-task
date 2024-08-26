#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct Point
{
	int x = 0;
	int y = 0;

	explicit Point() noexcept = default;
	explicit Point(int newX, int newY) noexcept : x(newX), y(newY) {}

	Point& operator=(const Point& other);
};

#pragma region Operators Overloading
bool operator==(const Point& left, const Point& right);

bool operator!=(const Point& left, const Point& right) noexcept;

Point operator+(const Point& left, const Point& right);

Point operator-(const Point& left, const Point& right);

Point operator*(const Point& left, const int right);

Point operator*(const int left, const Point& right);

std::ostream& operator<<(std::ostream& out, const Point& point);
#pragma endregion

namespace std {
	template <>
	struct hash<Point>
	{
		size_t operator()(const Point& p) const
		{
			return ((uint64_t)p.x) << 32 | (uint64_t)p.y;
			;
		}
	};
}  // namespace std