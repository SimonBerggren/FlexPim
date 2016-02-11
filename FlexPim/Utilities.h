#pragma once
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <random>
#include <ctime>

//extern inline void Print(char* toPrint, ...)
//{
//	va_list vl;
//	va_start(vl, toPrint);
//	for (int i = 0; toPrint[i] != '\0'; ++i)
//	{
//		union Printable_t {
//			int i;
//			float f;
//			char c;
//			char *s;
//		} Printable;
//
//		switch (toPrint[i])
//		{
//		case 'i':
//			Printable.i = va_arg(vl, int);
//			printf_s("%i", Printable.i);
//			break;
//		case 'f':
//			Printable.f = va_arg(vl, float);
//			printf_s("%f", Printable.i);
//			break;
//		case 'c':
//			Printable.i = va_arg(vl, char);
//			printf_s("%c", Printable.i);
//			break;
//		case 's':
//			Printable.s = va_arg(vl, char*);
//			printf_s("%s", Printable.i);
//			break;
//		}
//	}
//	va_end(vl);
//	std::cout << std::endl;
//}

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

extern inline const float RandomFloat(float min, float max)
{
	static std::mt19937 randomGenerator(time(0));
	static std::uniform_real_distribution<float> random(min, max);
	return random(randomGenerator);
}

extern inline const int RandomInt(int min, int max)
{
	static std::mt19937 randomGenerator(time(0));
	static std::uniform_int_distribution<int> random(min, max);
	return random(randomGenerator);
}