//--------------------------
// 3D Vector + w
//--------------------------
#ifndef VECTOR4F_H
#define VECTOR4F_H

#include "../Source/define.h"

class vector3f;

class vector4f
{
public:
	vector4f();
	vector4f( const vector3f& xyz, F32 w );
	vector4f( const vector4f& a );
	vector4f( F32 x, F32 y, F32 z, F32 w );

	// casting


	// assignment operators
	vector4f& operator += ( const vector4f& a );
	vector4f& operator -= ( const vector4f& a );
	vector4f& operator *= ( F32 a );
	vector4f& operator /= ( F32 a );

	// unary operators
	vector4f operator + () const;
	vector4f operator - () const;

	// binary operators
	vector4f operator + ( const vector4f& a ) const;
	vector4f operator - ( const vector4f& a ) const;
	vector4f operator * ( F32 a ) const;
	vector4f operator / ( F32 a ) const;

	//friend vector4f operator * (//32, const vector4f& a );

	bool operator == ( const vector4f& a ) const;
	bool operator != ( const vector4f& a ) const;

public:
	F32 _x, _y, _z, _w;
};

#endif