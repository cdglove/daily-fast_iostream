// ****************************************************************************
// fast_ostream.h
// 
// std::ostream wrapper that provides much faster conversion of primitives.
//
// Chris Glover (c.d.glover@gmail.com)
// Nov 8th, 2013
// 
// ****************************************************************************
#pragma once
#ifndef __DAILY_FAST_OSTREAM_
#define __DAILY_FAST_OSTREAM_

#include "detail/format.h"

namespace daily {

template<typename ostream_sink>
class fast_ostream
{
public:

	fast_ostream(ostream_sink& sink)
		: _sink(sink)
	{}
	
	ostream_sink& stream() { return _sink; }
	ostream_sink const& stream() const { return _sink; }
	
private:

	ostream_sink& _sink;
};

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, char const* v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, signed char const* v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned char const* v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, float v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::real_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, double v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::real_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, long double v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::real_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, char v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, signed char v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned char v)
{
	o.stream() << v;
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, short v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::int_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, int v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::int_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, long v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::int_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, long long v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::int_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned short v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::uint_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned int v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::uint_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned long v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::uint_to_string(out, v);
	return o;
}

template<typename ostream_sink>
fast_ostream<ostream_sink>& operator<<(fast_ostream<ostream_sink>& o, unsigned long long v)
{
	std::ostreambuf_iterator<char> out = std::ostreambuf_iterator<char>(o.stream());
	detail::uint_to_string(out, v);
	return o;
}

}

#endif //__DAILY_FAST_STREAM_