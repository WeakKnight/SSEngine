#pragma once

#include "Vector2.h"

struct Vector4;

struct Vector3 {
public:
	FORCEINLINE Vector3() {}
	FORCEINLINE Vector3(const float i_x, const float i_y, const float i_z);
	FORCEINLINE Vector3(const Vector3 & i_vector);
	FORCEINLINE explicit Vector3(const Vector2 & i_vector, const float i_z = 0.0f);
	FORCEINLINE explicit Vector3(const Vector4 & i_vector);

	FORCEINLINE void operator =(const Vector3 &i_vector);

	FORCEINLINE static Vector3 Zero();
	FORCEINLINE static Vector3 Unit();
	FORCEINLINE static Vector3 RandomNormal();

	FORCEINLINE void Normalize(float i_tolerance = 0.0000001);

	FORCEINLINE static float Dot(const Vector3 &i_vector1, const Vector3 &i_vector2);
	FORCEINLINE float Dot(const Vector3 &i_vector) const;
	FORCEINLINE float operator ^(const Vector3 &i_vector) const;

	FORCEINLINE static Vector3 Cross(const Vector3 &i_vector1, const Vector3 &i_vector2);
	FORCEINLINE Vector3 Cross(const Vector3 &i_vector) const;
	FORCEINLINE Vector3 operator |(const Vector3 &i_vector) const;

	FORCEINLINE static float Distance(const Vector3 &i_vector1, const Vector3 &i_vector2);
	FORCEINLINE float Distance(const Vector3 &i_vector) const;
	FORCEINLINE float Length() const;
	FORCEINLINE float LengthSquare() const;

	FORCEINLINE bool Equal(const Vector3 &i_vector, const float i_tolerance) const;

	FORCEINLINE Vector3 operator -() const;

	FORCEINLINE Vector3 operator +(const Vector3 &i_vector) const;
	FORCEINLINE Vector3 operator -(const Vector3 &i_vector) const;
	FORCEINLINE Vector3 operator *(const float i_float) const;
	FORCEINLINE Vector3 operator *(const Vector3 &i_vector) const;
	FORCEINLINE Vector3 operator /(const float i_float) const;
	FORCEINLINE Vector3 operator /(const Vector3 &i_vector) const;

	FORCEINLINE void operator +=(const Vector3 &i_vector);
	FORCEINLINE void operator -=(const Vector3 &i_vector);
	FORCEINLINE void operator *=(const float i_float);
	FORCEINLINE void operator *=(const Vector3 &i_vector);
	FORCEINLINE void operator /=(const float i_float);
	FORCEINLINE void operator /=(const Vector3 &i_vector);

	FORCEINLINE float operator [](const uint32 i_index) const;

public:
	float X, Y, Z;
};







// implement forceinline

FORCEINLINE Vector3::Vector3(const Vector2 & i_vector, const float i_z)
	:X(i_vector.X), Y(i_vector.Y), Z(i_z) 
{
}

FORCEINLINE Vector3::Vector3(const float i_x, const float i_y, const float i_z) 
	: X(i_x), Y(i_y), Z(i_z) 
{
}

FORCEINLINE Vector3::Vector3(const Vector3 & i_vector) 
	: X(i_vector.X), Y(i_vector.Y), Z(i_vector.Z) 
{
}

FORCEINLINE void Vector3::operator =(const Vector3 &i_vector)
{
	X = i_vector.X;
	Y = i_vector.Y;
	Z = i_vector.Z;
}

FORCEINLINE Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

FORCEINLINE Vector3 Vector3::Unit()
{
	return Vector3(1.0f, 1.0f, 1.0f);
}

FORCEINLINE Vector3 Vector3::RandomNormal()
{
	return Vector3(static_cast<float>(rand() / RAND_MAX) * 2.0f - 1.0f, 
				   static_cast<float>(rand() / RAND_MAX) * 2.0f - 1.0f, 
				   static_cast<float>(rand() / RAND_MAX) * 2.0f - 1.0f);
}

FORCEINLINE void Vector3::Normalize(float i_tolerance)
{
	const float magSq = Length();
	ASSERT(magSq > i_tolerance);

	X /= magSq;
	Y /= magSq;
	Z /= magSq;
}

FORCEINLINE float Vector3::Dot(const Vector3 &i_vector1, const Vector3 &i_vector2)
{
	return i_vector1.X * i_vector2.X + i_vector1.Y * i_vector2.Y + i_vector1.Z * i_vector2.Z;
}

FORCEINLINE float Vector3::Dot(const Vector3 &i_vector) const
{
	return X * i_vector.X + Y * i_vector.Y + Z * i_vector.Z;
}

FORCEINLINE float Vector3::operator ^(const Vector3 &i_vector) const
{
	return X * i_vector.X + Y * i_vector.Y + Z * i_vector.Z;
}

FORCEINLINE Vector3 Vector3::Cross(const Vector3 &i_vector1, const Vector3 &i_vector2)
{
	return Vector3(i_vector1.Y * i_vector2.Z - i_vector1.Z * i_vector2.Y,
		i_vector1.Z * i_vector2.X - i_vector1.X * i_vector2.Z,
		i_vector1.X * i_vector2.Y - i_vector1.Y * i_vector2.X);
}
FORCEINLINE Vector3 Vector3::Cross(const Vector3 &i_vector) const
{
	return Vector3(Y * i_vector.Z - Z * i_vector.Y, Z * i_vector.X - X * i_vector.Z, X * i_vector.Y - Y * i_vector.X);
}

FORCEINLINE Vector3 Vector3::operator |(const Vector3 &i_vector) const
{
	return Vector3(Y * i_vector.Z - Z * i_vector.Y, Z * i_vector.X - X * i_vector.Z, X * i_vector.Y - Y * i_vector.X);
}

FORCEINLINE float Vector3::Distance(const Vector3 &i_vector1, const Vector3 &i_vector2)
{
	return static_cast<float>(sqrt((i_vector1.X - i_vector2.X) * (i_vector1.X - i_vector2.X) +
		(i_vector1.Y - i_vector2.Y) * (i_vector1.Y - i_vector2.Y) +
		(i_vector1.Z - i_vector2.Z) * (i_vector1.Z - i_vector2.Z)));
}

FORCEINLINE float Vector3::Distance(const Vector3 &i_vector) const
{
	return static_cast<float>(sqrt((X - i_vector.X) * (X - i_vector.X) + (Y - i_vector.Y) * (Y - i_vector.Y) + (Z - i_vector.Z) * (Z - i_vector.Z)));
}

FORCEINLINE float Vector3::Length() const
{
	return static_cast<float>(sqrt(X * X + Y * Y + Z * Z));
}

FORCEINLINE float Vector3::LengthSquare() const
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE bool Vector3::Equal(const Vector3 &i_vector, const float i_tolerance) const
{
	return Float::EqualFast(X, i_vector.X, i_tolerance) && Float::EqualFast(Y, i_vector.Y, i_tolerance) && Float::EqualFast(Z, i_vector.Z, i_tolerance);
}

FORCEINLINE Vector3 Vector3::operator -() const
{
	return Vector3(-X, -Y, -Z);
}

FORCEINLINE Vector3 Vector3::operator +(const Vector3 &i_vector) const
{
	return Vector3(X + i_vector.X, Y + i_vector.Y, Z + i_vector.Z);
}
FORCEINLINE Vector3 Vector3::operator -(const Vector3 &i_vector) const
{
	return Vector3(X - i_vector.X, Y - i_vector.Y, Z - i_vector.Z);
}
FORCEINLINE Vector3 Vector3::operator *(const float i_float) const
{
	return Vector3(X * i_float, Y * i_float, Z * i_float);
}
FORCEINLINE Vector3 Vector3::operator *(const Vector3 &i_vector) const
{
	return Vector3(X * i_vector.X, Y * i_vector.Y, Z * i_vector.Z);
}
FORCEINLINE Vector3 Vector3::operator /(const float i_float) const
{
	return Vector3(X / i_float, Y / i_float, Z / i_float);
}
FORCEINLINE Vector3 Vector3::operator /(const Vector3 &i_vector) const
{
	return Vector3(X / i_vector.X, Y / i_vector.Y, Z / i_vector.Z);
}

FORCEINLINE void Vector3::operator +=(const Vector3 &i_vector)
{
	X += i_vector.X;
	Y += i_vector.Y;
	Z += i_vector.Z;
}
FORCEINLINE void Vector3::operator -=(const Vector3 &i_vector)
{
	X -= i_vector.X;
	Y -= i_vector.Y;
	Z -= i_vector.Z;
}
FORCEINLINE void Vector3::operator *=(const float i_float)
{
	X *= i_float;
	Y *= i_float;
	Z *= i_float;
}
FORCEINLINE void Vector3::operator *=(const Vector3 &i_vector)
{
	X *= i_vector.X;
	Y *= i_vector.Y;
	Z *= i_vector.Z;
}
FORCEINLINE void Vector3::operator /=(const float i_float)
{
	X /= i_float;
	Y /= i_float;
	Z /= i_float;
}
FORCEINLINE void Vector3::operator /=(const Vector3 &i_vector)
{
	X /= i_vector.X;
	Y /= i_vector.Y;
	Z /= i_vector.Z;
}
FORCEINLINE float Vector3::operator[](const uint32 i_index) const
{
	ASSERT(i_index < 3);
	return *(&X + i_index);
}



// for Vector2
FORCEINLINE Vector2::Vector2(const Vector3 & i_vector)
	: X(i_vector.X), Y(i_vector.Y)
{
}


