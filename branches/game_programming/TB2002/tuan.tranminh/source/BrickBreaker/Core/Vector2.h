#ifndef Vector2_h__
#define Vector2_h__

struct Vector2
{
	float x;
	float y;

	Vector2(float xValue = 0.0f, float yValue = 0.0f)
	{
		x = xValue;
		y = yValue;
	}

	Vector2 operator+	(const Vector2& v)
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 operator=	(const Vector2& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector2 operator+=	(const Vector2& v)
	{
		*this = this->operator+(v);
		return *this;
	}

	Vector2 operator*	(const float& value)
	{
		return Vector2((float)(x * value), (float)(y * value));
	}

	Vector2 operator/	(const float& value)
	{
		return (*this) * (1 / value);
	}
};

#endif // Vector2_h__
