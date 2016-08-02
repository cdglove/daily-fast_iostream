// ****************************************************************************
// format.h
// 
// String conversion utilities for fast iostream and locale.
//
// Chris Glover (c.d.glover@gmail.com)
// Nov 8th, 2013
// 
// ****************************************************************************
#pragma once
#ifndef __DAILY_DETAIL_FAST_FORMAT_
#define __DAILY_DETAIL_FAST_FORMAT_

#include <array>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/qi.hpp>
#include <iostream>

namespace daily {

// ----------------------------------------------------------------------------
//
namespace detail
{	
	template<typename OutIter, typename float_type>
	OutIter real_to_string(OutIter out, float_type value)
	{
		using namespace boost::spirit::karma;
		typedef real_generator<float_type> float_gen_type;
		const float_gen_type floater = float_gen_type();
		generate(out, floater, value);
		return out;
	}
	
	template<typename OutIter, typename int_type>
	OutIter int_to_string(OutIter out, int_type value)
	{
		using namespace boost::spirit::karma;
		typedef int_generator<int_type> int_gen_type;
		const int_gen_type inter = int_gen_type();
		generate(out, inter, value);
		return out;
	}
	
	template<typename OutIter, typename int_type>
	OutIter uint_to_string(OutIter out, int_type value)
	{
		using namespace boost::spirit::karma;
		typedef uint_generator<int_type> int_gen_type;
		const int_gen_type inter = int_gen_type();
		generate(out, inter, value);
		return out;
	}
	
	template<std::size_t N>
	class fs_istring
	{
	public:
		fs_istring()
			: length(0)
		{}
		
		template<typename Iter>
		fs_istring(Iter b, Iter e)
			: length(0)
		{
			while(b != e && std::isspace(*b))
			{
				++b;
			}
			
			while(b != e && !std::isspace(*b))
			{
				data[length++] = *b;
				++b;
			}
		}
		
		std::array<char, N> data;
		std::size_t length;
	};
	
	template<typename float_type, typename InIter>
	InIter string_to_real(InIter b, InIter e, float_type& v)
	{
		using namespace boost::spirit::qi;
		typedef real_parser<float_type> float_parse_type;
		const float_parse_type floater = float_parse_type();
		parse(b, e, floater, v);
		return b;
	}
	
	template<typename int_type, typename InIter>
	InIter string_to_int(InIter b, InIter e, int_type& v)
	{
		using namespace boost::spirit::qi;
		typedef int_parser<int_type> int_parse_type;
		const int_parse_type inter = int_parse_type();
		parse(b, e, inter, v);
		return b;
	}
	
	template<typename int_type, typename InIter>
	InIter string_to_uint(InIter b, InIter e)
	{
		using namespace boost::spirit::qi;
		typedef uint_parser<int_type> int_parse_type;
		const int_parse_type inter = int_parse_type();
		int_type result = 0;
		parse(b, e, inter, result);
		return b;
	}
	
	template<typename float_type, std::size_t N>
	float_type string_to_real(fs_istring<N> const& s)
	{
		float_type ret_val = 0;
		string_to_real<float_type>(s.data.data(), s.data.data() + s.length, ret_val);
		return ret_val;
	}
	
	template<typename int_type, std::size_t N>
	int_type string_to_int(fs_istring<N> const& s)
	{
		int_type ret_val = 0;
		string_to_int<int_type>(s.data.data(), s.data.data() + s.length, ret_val);
		return ret_val;
	}
	
	template<typename int_type, std::size_t N>
	int_type string_to_uint(fs_istring<N> const& s)
	{
		int_type ret_val = 0;
		string_to_int<int_type>(s.data.data(), s.data.data() + s.length, ret_val);
		return ret_val;
	}
}

template<std::size_t N>
std::istream& operator>>(std::istream& is, detail::fs_istring<N>& v)
{
	std::istreambuf_iterator<char> b = std::istreambuf_iterator<char>(is);
	std::istreambuf_iterator<char> e = std::istreambuf_iterator<char>();
	
	v = detail::fs_istring<N>(b, e);
	
	return is;
}

}

#endif // __DAILY_DETAIL_FAST_FORMAT_
