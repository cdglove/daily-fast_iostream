// ****************************************************************************
// fast_locale.h
// 
// std::locale object containing much faster facet implementations.
// Makes the iostreams significantly faster than the stock versions
// but still 1.5x slower than fast_*stream.
//
// Chris Glover (c.d.glover@gmail.com)
// Nov 8th, 2013
// 
// ****************************************************************************
#pragma once
#ifndef __DAILY_FAST_LOCALE_
#define __DAILY_FAST_LOCALE_

#include <locale>

namespace daily {

std::locale generate_fast_locale(char const* loc_name);

}

#if DAILY_INLINE_IMPL
#  define DAILY_INLINE inline
#  include "src/fast_locale.cpp" 
#endif

#endif
