
#include "vector3f.h"

vector3f::vector3f()
{
}
vector3f::vector3f( const vector3f &a ):_x( a._x ), _y( a._y )
{
}
vector3f::vector3f( F32 x, F32 y, F32 z )
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

vector3f& vector3f::operator += ( const vector3f& a )
{
	this->_x += a._x;
	this->_y += a._y;
	this->_z += a._z;
	return *this;
}

vector3f& vector3f::operator -= ( const vector3f& a )
{
	this->_x -= a._x;
	this->_y -= a._y;
	this->_z -= a._z;
	return *this;
}

vector3f& vector3f::operator *= ( F32 a )
{
	this->_x *= a;
	this->_y *= a;
	this->_z *= a;
	return *this;
}

vector3f& vector3f::operator /= ( F32 a )
{
	this->_x /= a;
	this->_y /= a;
	this->_z /= a;
	return *this;
}

vector3f vector3f::operator + () const
{
	return vector3f( _x, _y, _z );
}

vector3f vector3f::operator - () const
{
	return vector3f( -_x, -_y, -_z );
}

vector3f vector3f::operator + ( const vector3f& a ) const
{
	return vector3f( this->_x + a._x, this->_y + a._y, this->_z + a._z );
}

vector3f vector3f::operator - ( const vector3f& a ) const
{
	return vector3f( this->_x - a._x, this->_y - a._y, this->_z - a._z );
}

vector3f vector3f::operator * ( F32 a ) const
{
	return vector3f(this->_x * a, this->_y * a, this->_z * a);
}

vector3f vector3f::operator / ( F32 a ) const
{
	return vector3f(this->_x / a, this->_y / a, this->_z / a);
}

bool vector3f::operator == ( const vector3f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y && this->_z == a._z )
	{
		return true;
	}
	else 
		return false;
}

bool vector3f::operator != ( const vector3f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y && this->_z == a._z)
	{
		return false;
	}
	else 
		return true;
}