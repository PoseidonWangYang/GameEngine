#include "vector4f.h"
#include "vector3f.h"

vector4f::vector4f()
{
}

vector4f::vector4f( const vector3f& xyz, F32 w )
{
	this->_x = xyz._x;
	this->_y = xyz._y;
	this->_z = xyz._z;
	this->_w = w;
}

vector4f::vector4f( const vector4f& a )
{
	this->_x = a._x;
	this->_y = a._y;
	this->_z = a._z;
	this->_w = a._w;
}

vector4f::vector4f( F32 x, F32 y, F32 z, F32 w )
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
}

vector4f& vector4f::operator += ( const vector4f& a )
{
	this->_x += a._x;
	this->_y += a._y;
	this->_z += a._z;
	this->_w += a._w;
	return *this;
}

vector4f& vector4f::operator -= ( const vector4f& a )
{
	this->_x -= a._x;
	this->_y -= a._y;
	this->_z -= a._z;
	this->_w -= a._w;
	return *this;
}

vector4f& vector4f::operator *= ( F32 a )
{
	this->_x *= a;
	this->_y *= a;
	this->_z *= a;
	this->_w *= a;
	return *this;
}

vector4f& vector4f::operator /= ( F32 a )
{
	this->_x /= a;
	this->_y /= a;
	this->_z /= a;
	this->_w /= a;
	return *this;
}

vector4f vector4f::operator + () const
{
	return vector4f( _x, _y, _z, _w );
}

vector4f vector4f::operator - () const
{
	return vector4f( -_x, -_y, -_z, -_w );
}

vector4f vector4f::operator + ( const vector4f& a ) const
{
	return vector4f( this->_x + a._x, this->_y + a._y, this->_z + a._z, this->_w + a._w );
}

vector4f vector4f::operator - ( const vector4f& a ) const
{
	return vector4f( this->_x - a._x, this->_y - a._y, this->_z - a._z, this->_w - a._w );
}

vector4f vector4f::operator * ( F32 a ) const
{
	return vector4f(this->_x * a, this->_y * a, this->_z * a, this->_w * a);
}

vector4f vector4f::operator / ( F32 a ) const
{
	return vector4f(this->_x / a, this->_y / a, this->_z / a, this->_w / a);
}

bool vector4f::operator == ( const vector4f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y && this->_z == a._z && this->_w == a._w)
	{
		return true;
	}
	else 
		return false;
}

bool vector4f::operator != ( const vector4f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y && this->_z == a._z && this->_w == a._w)
	{
		return false;
	}
	else 
		return true;
}
