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

// TODO: Include all Compiler Targets ( https://sourceforge.net/p/predef/wiki/Compilers/ )

#ifndef PHOBOSPP_CORE_COMPILER_H
#define PHOBOSPP_CORE_COMPILER_H

#undef PHOBOSPP_CC
#undef PHOBOSPP_CXX

#ifdef __cplusplus
	#define PHOBOSPP_CXX __cplusplus
	#if PHOBOSPP_CXX >= 199711L
		#define PHOBOSPP_CXX_98
	#endif
	#if PHOBOSPP_CXX >= 201103L
		#define PHOBOSPP_CXX_11
	#endif
	#if PHOBOSPP_CXX >= 201402L
		#define PHOBOSPP_CXX_14
	#endif
	#if PHOBOSPP_CXX >= 201703L
		#define PHOBOSPP_CXX_17
	#endif
#else
	#define PHOBOSPP_CC
#endif

#if __USE_ISOC99
	#define PHOBOSPP_C99
#endif

#ifdef _MSC_VER
	#define PHOBOSPP_TARGET_COMPILER_MSVC _MSC_VER
	//For clang version
	#ifdef __clang__
		#define PHOBOSPP_TARGET_COMPILER_CLANG ((__clang_major__ * 100) + __clang_minor__)
		#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
	#endif

	//Compiler specifications
	#define PHOBOSPP_FUNC_INFO __FUNCSIG__
	#define PHOBOSPP_DECL_DEPRECATED __declspec(deprecated)

	#define PHOBOSPP_ALIGNED_ALLOC(s,a) _aligned_malloc(s,a)
	#define PHOBOSPP_ALIGNED_FREE(x) _aligned_free(x)

	#ifdef PHOBOSPP_TARGET_COMPILER_CLANG
		#define PHOBOSPP_DECL_DEPRECATED_X(x) __declspec(deprecated(x))
	#endif
	#define PHOBOSPP_DECL_EXPORT __declspec(dllexport)
	#define PHOBOSPP_DECL_IMPORT __declspec(dllimport)
	#define PHOBOSPP_DEBUGBREAK(x) __debugbreak();

	//Detect pragmaonce support
	#if _MSC_VER>=1020
		#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
	#endif

	#ifdef __INTEL_COMPILER
		#define PHOBOSPP_TARGET_COMPILER_INTEL __INTEL_COMPILER
	#endif

	#ifdef PHOBOSPP_TARGET_CXX
		#define PHOBOSPP_DECL_NOTHROW throw()
		#endif
#elif defined(__GNUG__) || defined(__GNUC__)
	#ifndef PHOBOSPP_TARGET_COMPILER_GNU
		#define PHOBOSPP_TARGET_COMPILER_GNU
	#endif
	#define PHOBOSPP_TARGET_COMPILER_GNU_GCC
	#ifdef PHOBOSPP_TARGET_CXX
		#define PHOBOSPP_TARGET_COMPILER_GNU_CXX
	#else
		#define PHOBOSPP_TARGET_COMPILER_GNU_CC
	#endif // PHOBOSPP_TARGET_CXX

	#ifdef __GNUG__
		#define PHOBOSPP_TARGET_COMPILER_GNU_GXX
	#endif

	#ifdef PHOBOSPP__DEBUG
		#define PHOBOSPP_FORCE_INLINE inline
	#else
		#define PHOBOSPP_FORCE_INLINE __always_inline
	#endif // PHOBOSPP__DEBUG
	
	#define PHOBOSPP_ALIGNED_ALLOC(s,a) aligned_alloc(a,s)
	#define PHOBOSPP_ALIGNED_FREE(x) ::free(x);
	#define PHOBOSPP_DEBUGBREAK(x) __builtin_trap();
	#define PHOBOSPP_DECL_UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
	#define PHOBOSPP_DECL_UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_ ## x
#else
	#warning "Unknown compiler!"

	#define PHOBOSPP_DECL_UNUSED(x) UNUSED_ ## x
	#define PHOBOSPP_DECL_UNUSED_FUNCTION(x) UNUSED_ ## x

	#define PHOBOSPP_FORCE_INLINE inline

	//#include <AuroraFW/STDL/LibC/Signal.h>
	#include<signal.h>
	#define PHOBOSPP_DEBUGBREAK(x) raise(SIGTRAP);
#endif

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
	#define PHOBOSPP_TARGET_COMPILER_BORLAND
#elif defined(__COMO__)
	#define PHOBOSPP_TARGET_COMPILER_COMEAU
#elif defined(__DECC)
	#define PHOBOSPP_TARGET_COMPILER_COMPAQ_CC
#elif defined(__DECCXX)
	#define PHOBOSPP_TARGET_COMPILER_COMPAQ_CXX
#elif defined(__convexc__)
	#define PHOBOSPP_TARGET_COMPILER_CONVEXC
#elif defined(_MSC_VER)
	#define PHOBOSPP_TARGET_COMPILER_MICROSOFT
#endif

#ifdef __CC_ARM
	#define PHOBOSPP_TARGET_COMPILER_ARM
#endif

#ifdef __MINGW32__
	#define PHOBOSPP_TARGET_COMPILER_MINGW

	#define PHOBOSPP_DECL_EXPORT __declspec(dllexport)
	#define PHOBOSPP_DECL_IMPORT __declspec(dllimport)
#endif

#ifdef __clang__
	#define PHOBOSPP_TARGET_COMPILER_CLANG ((__clang_major__ * 100) + __clang_minor__)
#endif

#ifdef __ELF__
	#define PHOBOSPP_TARGET_ELF 1
#endif

// Oracle Developer Studio C/C++ (12.5 or later)
#if (defined(__SUNPRO_C)&&(__SUNPRO_C>=0x5140))||(defined(__SUNPRO_CC)&&(__SUNPRO_CC>=0x5140))
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// MSVC
#elif defined(_MSC_VER)&&(_MSC_VER>=1020)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// clang
#elif defined(__clang__)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// comeau
#elif defined(__COMO__)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// C++Builder (XE3 or greater)
#elif defined(__CODEGEARC__)&&(__CODEGEARC__ >=650)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// Digital Mars
#elif defined(__DMC__)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// GCC
#elif defined(__GNUC__)&&((__GNUC__ >3)||(defined(__GNUC_MINOR__)&&(__GNUC__ ==3)&&(__GNUC_MINOR__ >=4)))
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// HP aC++ (A.06.12)
#elif defined(__HP_aCC)&&(__HP_aCC >=61200)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// IBM
#elif defined(__xlC__)&&((__xlC__ >1301)||((__xlC__ ==1301)&&(__xlC_ver__ >0100)))
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// Intel
#elif defined(__INTEL_COMPILER)||defined(__ICC)||defined(__ECC)||defined(__ICL)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// Pelles C
#elif defined(__POCC__)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// ARM compiler
#elif defined(__CC_ARM)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// IAR C/C++
#elif defined(__IAR_SYSTEMS_ICC__)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 1
// Portland Group C/C++
#elif defined(__PGI)
	#define PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT 0
#endif

#ifdef __STRICT_ANSI__
	#if __STRICT_ANSI__ == 1
		#define PHOBOSPP_TARGET_STRICT_ANSI
	#endif
#endif

//Temporary definitions
#define PHOBOSPP_CONSTEXPR constexpr
#define PHOBOSPP_NOEXCEPT noexcept

#if(PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#endif // PHOBOSPP_CORE_COMPILER_H