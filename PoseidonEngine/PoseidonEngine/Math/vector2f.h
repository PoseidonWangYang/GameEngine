//--------------------------
// 2D Vector
//--------------------------
#ifndef VECTOR2F_H
#define VECTOR2F_H

#include "../Source/define.h"


class vector2f
{
public:
	vector2f();
	vector2f( const vector2f &a );
	vector2f( F32 x, F32 y );

	// casting

	// assignment operators
	vector2f& operator += ( const vector2f& a );
	vector2f& operator -= ( const vector2f& a );
 	vector2f& operator *= ( F32 a );
 	vector2f& operator /= ( F32 a );

	// unary operators
	vector2f operator + () const;
	vector2f operator - () const;

	// binary operators
	vector2f operator + ( const vector2f& a ) const;
	vector2f operator - ( const vector2f& a ) const;
	vector2f operator * ( F32 a ) const;
	vector2f operator / ( F32 a ) const;


// 	friend vector2f operator * ( F32, const vector2f& );

	bool operator == ( const vector2f& a ) const;
	bool operator != ( const vector2f& a ) const;


public:
	F32 _x, _y;
};

#endif
