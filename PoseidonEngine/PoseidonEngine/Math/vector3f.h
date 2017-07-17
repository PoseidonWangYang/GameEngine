//--------------------------
// 3D Vector
//--------------------------
#ifndef VECTOR3F_H
#define VECTOR3F_H

#include "../Source/define.h"


class vector3f
{
public:
	vector3f();
	vector3f( const vector3f &a );
	vector3f( F32 x, F32 y, F32 z );

	// casting

	// assignment operators
	vector3f& operator += ( const vector3f& a );
	vector3f& operator -= ( const vector3f& a );
	vector3f& operator *= ( F32 a );
	vector3f& operator /= ( F32 a );

	// unary operators
	vector3f operator + () const;
	vector3f operator - () const;

	// binary operators
	vector3f operator + ( const vector3f& a ) const;
	vector3f operator - ( const vector3f& a ) const;
	vector3f operator * ( F32 a ) const;
	vector3f operator / ( F32 a ) const;


	// 	friend vector2f operator * ( F32, const vector2f& );

	bool operator == ( const vector3f& a ) const;
	bool operator != ( const vector3f& a ) const;


public:
	F32 _x, _y, _z;
};

#endif