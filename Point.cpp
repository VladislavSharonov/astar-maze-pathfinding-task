#include "Point.h"

bool operator==(const Point& left, const Point& right)
{
	return left.x == right.x && left.y == right.y;
}

bool operator!=(const Point& left, const Point& right) noexcept
{
	return !(left == right);
}

Point operator+(const Point& left, const Point& right)
{
	return Point(left.x + right.x, left.y + right.y);
}

Point operator-(const Point& left, const Point& right)
{
	return Point(left.x - right.x, left.y - right.y);
}

Point operator*(const Point& left, const int right)
{
	return Point(left.x * right, left.y * right);
}

Point operator*(const int left, const Point& right)
{
	return Point(left * right.x, left * right.y);
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "(" << std::to_string(point.x) << ", " << std::to_string(point.y) << ")";
	return out;
}

Point& Point::operator=(const Point& other)
{
	if (&other != this)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}
