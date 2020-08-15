#pragma once
#include <iostream>

class Vec2
{
public:
	float x;
	float y;

	Vec2();
	Vec2(float x, float y);

	Vec2& Add(const Vec2& vec);
	Vec2& Subtract(const Vec2& vec);
	Vec2& Multiply (const Vec2& vec);
	Vec2& Divide(const Vec2& vec);

	friend Vec2& operator+(Vec2& v1, const Vec2& v2);
	friend Vec2& operator-(Vec2& v1, const Vec2& v2);
	friend Vec2& operator*(Vec2& v1, const Vec2& v2);
	friend Vec2& operator/(Vec2& v1, const Vec2& v2);

	Vec2& operator +=(const Vec2& vec);
	Vec2& operator -=(const Vec2& vec);
	Vec2& operator *=(const Vec2& vec);
	Vec2& operator /=(const Vec2& vec);

	Vec2& operator*(const int& i);
	Vec2& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);
};