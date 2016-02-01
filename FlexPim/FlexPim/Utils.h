#pragma once

#include <sstream>

template<class T>
extern inline const std::string ToString(T i)
{
	std::ostringstream stream;
	stream << i;
	return stream.str();
}

extern inline const int Clamp(int value, int min, int max)
{
	return (value < min) ? min : (value > max) ? max : value;
}

extern inline const float Clamp(float value, float min, float max)
{
	return (value < min) ? min : (value > max) ? max : value;
}

extern inline const double Clamp(double value, double min, double max)
{
	return (value < min) ? min : (value > max) ? max : value;
}

template <class T>
extern inline const sf::Vector2<T>& Clamp(const sf::Vector2<T> value, T min, T max)
{
	sf::Vector2<T> clamped = value;
	clamped.x = Clamp(clamped.x, min, max);
	clamped.y = Clamp(clamped.y, min, max);
	return clamped;
}

template <class T>
extern inline const T VectorDistance(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2)
{
	return sqrt(pow((v2.x - v1.x), 2.0f) + pow((v2.y - v1.y), 2.0f));
}

template <class T>
extern inline const T VectorLength(const sf::Vector2<T>& v)
{
	return sqrt(v.x * v.x) + (v.y * v.y);
}

template <class T>
extern inline const sf::Vector2<T> NormalizeVector(const sf::Vector2<T>& v)
{
	T length = VectorLength(v);
	
	return sf::Vector2<T>(v.x / length, v.y / length);
}

template <class T>
extern inline const sf::Vector2<T> NormalizeVectorBetween(const sf::Vector2<T>& v, float min, float max)
{
	sf::Vector2<T> normalized = v;

	normalized.x = (normalized.x - min) / max - min;
	normalized.x = (normalized.x - min) / max - min;

	return sf::Vector2<T>(v.x / length, v.y / length);
}

template <class T>
extern inline const sf::Vector2<T> DirectionBetween(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2)
{
	return sf::Vector2<T>(v2.x - v1.x, v2.y - v1.y);
}

extern inline const sf::Vector2f GetOrigin(const sf::FloatRect& r)
{
	return sf::Vector2f(r.width / 2.0f, r.height / 2.0f);
}