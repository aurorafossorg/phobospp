/*****************************************************************************
**                                    / _|
**   __ _ _   _ _ __ ___  _ __ __ _  | |_ ___  ___ ___
**  / _` | | | | '__/ _ \| '__/ _` | |  _/ _ \/ __/ __|
** | (_| | |_| | | | (_) | | | (_| | | || (_) \__ \__ \
**  \__,_|\__,_|_|  \___/|_|  \__,_| |_| \___/|___/___/
**
** Copyright (C) 2018 Aurora Free Open Source Software.
**
** This file is part of the Aurora Free Open Source Software. This
** organization promote free and open source software that you can
** redistribute and/or modify under the terms of the GNU Lesser General
** Public License Version 3 as published by the Free Software Foundation or
** (at your option) any later version approved by the Aurora Free Open Source
** Software Organization. The license is available in the package root path
** as 'LICENSE' file. Please review the following information to ensure the
** GNU Lesser General Public License version 3 requirements will be met:
** https://www.gnu.org/licenses/lgpl.html .
**
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3 or later as published by the Free Software
** Foundation. Please review the following information to ensure the GNU
** General Public License requirements will be met:
** http://www.gnu.org/licenses/gpl-3.0.html.
**
** NOTE: All products, services or anything associated to trademarks and
** service marks used or referenced on this file are the property of their
** respective companies/owners or its subsidiaries. Other names and brands
** may be claimed as the property of others.
**
** For more info about intellectual property visit: aurorafoss.org or
** directly send an email to: contact (at) aurorafoss.org .
*****************************************************************************/

#ifndef PHOBOSPP_STDL_CIRCULARSHIFT_H
#define PHOBOSPP_STDL_CIRCULARSHIFT_H

#include <phobospp/core/compiler.h>
#if(PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#ifdef PHOBOSPP_TARGET_CXX
	namespace afw {
		template <typename intT>
		#ifdef PHOBOSPP_TARGET_CXX_11
			constexpr
		#endif
		intT rotl(const intT& val, const size_t& len)
		{
			#if defined(PHOBOSPP_TARGET_CXX_11) && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Left only makes sense for unsigned types");
			#endif
			return (val << len) | ((unsigned) val >> (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
		template <typename intT>
		#ifdef PHOBOSPP_TARGET_CXX_11
			constexpr
		#endif
		intT rotr(const intT& val, const size_t& len)
		{
			#if defined(PHOBOSPP_TARGET_CXX_11) && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Right only makes sense for unsigned types");
			#endif
			return (val >> len) | ((unsigned) val << (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
#endif
extern inline uint32_t rotl32 (const uint32_t& value, unsigned int count);
extern inline uint32_t rotr32 (const uint32_t& value, unsigned int count);
#if PHOBOSPP_TARGET_WORDSIZE == 64
	extern inline uint64_t rotl64 (const uint64_t& value, unsigned int count);
	extern inline uint64_t rotr64 (const uint64_t& value, unsigned int count);
#endif
#ifdef PHOBOSPP_TARGET_CXX
	}
#endif

#endif // PHOBOSPP_STDL_CIRCULARSHIFT_H
