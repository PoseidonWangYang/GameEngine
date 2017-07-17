
#include "vector2f.h"

vector2f::vector2f()
{
}
vector2f::vector2f( const vector2f &a ):_x( a._x ), _y( a._y )
{
}
vector2f::vector2f( F32 x, F32 y )
{
	this->_x = x;
	this->_y = y;
}

vector2f& vector2f::operator += ( const vector2f& a )
{
	this->_x += a._x;
	this->_y += a._y;
	return *this;
}

vector2f& vector2f::operator -= ( const vector2f& a )
{
	this->_x -= a._x;
	this->_y -= a._y;
	return *this;
}

vector2f& vector2f::operator *= ( F32 a )
{
	this->_x *= a;
	this->_y *= a;
	return *this;
}

vector2f& vector2f::operator /= ( F32 a )
{
	this->_x /= a;
	this->_y /= a;
	return *this;
}

vector2f vector2f::operator + () const
{
	return vector2f( _x, _y );
}

vector2f vector2f::operator - () const
{
	return vector2f( -_x, -_y );
}

vector2f vector2f::operator + ( const vector2f& a ) const
{
	return vector2f( this->_x + a._x, this->_y + a._y );
}

vector2f vector2f::operator - ( const vector2f& a ) const
{
	return vector2f( this->_x - a._x, this->_y - a._y );
}

vector2f vector2f::operator * ( F32 a ) const
{
	return vector2f(this->_x * a, this->_y * a);
}

vector2f vector2f::operator / ( F32 a ) const
{
	return vector2f(this->_x / a, this->_y / a);
}

bool vector2f::operator == ( const vector2f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y )
	{
		return true;
	}
	else 
		return false;
}

bool vector2f::operator != ( const vector2f& a ) const
{
	if ( this->_x == a._x && this->_y == a._y )
	{
		return false;
	}
	else 
		return true;
}