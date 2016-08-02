// ****************************************************************************
// fast_istream.h
// 
// std::istream wrapper that provides much faster parsing of primitives.
//
// Chris Glover (c.d.glover@gmail.com)
// Nov 8th, 2013
// 
// ****************************************************************************
#pragma once
#ifndef __DAILY_FAST_ISTREAM_
#define __DAILY_FAST_ISTREAM_

#include "detail/format.h"

namespace daily {

template<typename istream_source>
class fast_istream
{
public:

	fast_istream(istream_source& sink)
		: _sink(sink)
	{}
	
	istream_source& stream() { return _sink; }
	istream_source const& stream() const { return _sink; }
	
private:

	istream_source& _sink;
};

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, float& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;	
	v = detail::string_to_real<float>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, double& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_real<float>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, long double& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_real<float>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, char& v)
{
	is.stream() >> v;
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, signed char& v)
{
	is.stream() >> v;
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, unsigned char& v)
{
	is.stream() >> v;
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, short& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<short>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, int& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;	
	v = detail::string_to_int<int>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, long& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<long>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, long long& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<long long>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, unsigned short& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<unsigned short>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, unsigned int& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<unsigned int>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, unsigned long& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<unsigned long>(s);
	return is;
}

template<typename istream_source>
fast_istream<istream_source>& operator>>(fast_istream<istream_source>& is, unsigned long long& v)
{
	detail::fs_istring<32> s;
	is.stream() >> s;
	v = detail::string_to_int<unsigned long long>(s);
	return is;
}

}

#endif //__DAILY_FAST_STREAM_