//--------------------------
// 4x4  Matrix
//--------------------------
#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "../Source/define.h"

class matrix4x4
{
public:
	matrix4x4();
	matrix4x4( F32 _m11, F32 _m12, F32 _m13, F32 _m14,
		F32 _m21, F32 _m22, F32 _m23, F32 _m24,
		F32 _m31, F32 _m32, F32 _m33, F32 _m34,
		F32 _m41, F32 _m42, F32 _m43, F32 _m44 );


	// access grants
	F32& operator () ( UI32 Row, UI32 Col );
	F32  operator () ( UI32 Row, UI32 Col ) const;

	// casting operators

	// assignment operators
	matrix4x4& operator *= ( const matrix4x4& a );
	matrix4x4& operator += ( const matrix4x4& a );
	matrix4x4& operator -= ( const matrix4x4& a );
	matrix4x4& operator *= ( F32 a );
	matrix4x4& operator /= ( F32 a );

	// unary operators
	matrix4x4 operator + () const;
	matrix4x4 operator - () const;

	// binary operators
	matrix4x4 operator * ( const matrix4x4& a ) const;
	matrix4x4 operator + ( const matrix4x4& a ) const;
	matrix4x4 operator - ( const matrix4x4& a ) const;
	matrix4x4 operator * ( F32 a ) const;
	matrix4x4 operator / ( F32 a ) const;

	//friend matrix4x4 operator * ( F32, CONST matrix4x4& );

	bool operator == ( const matrix4x4& ) const;
	bool operator != ( const matrix4x4& ) const;
public:
	F32 _m11, _m12, _m13, _m14;
	F32	_m21, _m22, _m23, _m24;
	F32	_m31, _m32, _m33, _m34;
	F32	_m41, _m42, _m43, _m44;
};

#endif