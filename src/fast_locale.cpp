// ****************************************************************************
// fast_locale.cpp
// 
// Implementation of fast locale.  See daily/fast_locale.h for details.
//
// Chris Glover (c.d.glover@gmail.com)
// Nov 8th, 2013
// 
// ****************************************************************************

#include "daily/fast_iostream/detail/format.h"
#include "daily/fast_iostream/fast_locale.h"

#ifndef DAILY_INLINE
#  define DAILY_INLINE
#endif

namespace daily {

class fast_num_put : public std::num_put<char>
{
protected:

	typedef std::num_put<char> base_type;

	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, bool v ) const
	{
		return base_type::do_put(out, str, fill, v);
	}
	
	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, long v ) const
	{
		return detail::int_to_string(out, v);
	}
	
	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, long long v ) const
	{
		return detail::int_to_string(out, v);
	}
	
	virtual iter_type do_put( 
		iter_type out, std::ios_base& str, char_type fill, unsigned long v ) const
	{
		return detail::uint_to_string(out, v);
	}
	
	virtual iter_type do_put( 
		iter_type out, std::ios_base& str, char_type fill, unsigned long long v ) const
	{
		return detail::uint_to_string(out, v);
	}
	
	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, float v ) const
	{
		return detail::real_to_string(out, v);
	}
	
	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, double v ) const
	{
		return detail::real_to_string(out, v);
	}
	
	virtual iter_type do_put(
		iter_type out, std::ios_base& str, char_type fill, long double v ) const
	{
		return detail::real_to_string(out, v);
	}
	
	virtual iter_type do_put( iter_type out, std::ios_base& str, char_type fill, const void* v ) const
	{
		return base_type::do_put(out, str, fill, v);
	}
};

class fast_num_get : public std::num_get<char>
{
protected:

	typedef std::num_get<char> base_type;

	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, bool& v ) const
	{
		return base_type::do_get(in, end, str, err, v);
	}
	
	virtual iter_type do_get( 
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, long& v ) const
	{
		v = detail::string_to_int<long>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, long long& v ) const
	{
		v = detail::string_to_int<long long>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get( 
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, unsigned short& v ) const
	{
		v = detail::string_to_uint<unsigned short>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, unsigned int& v ) const
	{
		v = detail::string_to_uint<unsigned int>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, unsigned long& v ) const
	{
		v = detail::string_to_uint<unsigned long>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, unsigned long long& v ) const
	{
		v = detail::string_to_uint<unsigned long long>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, float& v ) const
	{
		v = detail::string_to_real<float>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get( 
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, double& v ) const
	{
		v = detail::string_to_real<double>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get(
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, long double& v ) const
	{
		v = detail::string_to_real<long double>(detail::fs_istring<32>(in, end));
		return in;
	}
	
	virtual iter_type do_get( 
		iter_type in, iter_type end, std::ios_base& str, 
		std::ios_base::iostate& err, void*& v ) const
	{
		return base_type::do_get(in, end, str, err, v);
	}
};

DAILY_INLINE std::locale generate_fast_locale(char const* loc_name)
{
	std::locale r = std::locale(loc_name);
	
	r = std::locale(r, new fast_num_put);
	r = std::locale(r, new fast_num_get);
	
	return r;
}

}