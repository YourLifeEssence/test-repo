#include "candle.h"

#include <cmath>
#include <string>
#include <stdexcept>

Candle::Candle(Price _open, Price _high, Price _low, Price _close)
	: open(_open), high(_high), low(_low), close(_close)
{
}

bool Candle::body_contains(const Price& price) const noexcept
{
	Price min = std::min(open, close);
	Price max = std::max(open, close);
	return price >= min && price <= max;
}

bool Candle::contains(const Price& price) const noexcept
{
	return price >= low && price <= high;
}

double Candle::full_size() const noexcept
{
	return std::abs(high - low);
}

double Candle::body_size() const noexcept
{
	return std::abs(open - close);
}

bool Candle::is_green() const noexcept
{
	return close > open;
}

bool Candle::is_red() const noexcept
{
	return close < open;
}
