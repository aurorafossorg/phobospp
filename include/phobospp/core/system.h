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

//TODO: Need to be documented

#ifndef PHOBOSPP_CORE_SYSTEM_H
#define PHOBOSPP_CORE_SYSTEM_H

#include <phobospp/core/compiler.h>
#if(PHOBOSPP_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#if defined(__linux__) || defined(__linux) || defined(linux)
	#define PHOBOSPP_TARGET_KERNEL_LINUX
#elif defined(PHOBOSPP_TARGET_PLATFORM_WINDOWS)
	#define PHOBOSPP_TARGET_KERNEL_NT
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	#define PHOBOSPP_TARGET_KERNEL_FREEBSD
#elif defined(__OpenBSD__)
	#define PHOBOSPP_TARGET_KERNEL_OPENBSD
#elif defined(__NetBSD__)
	#define PHOBOSPP_TARGET_KERNEL_NETBSD
#elif defined(__DragonFly__)
	#define PHOBOSPP_TARGET_KERNEL_DRAGONFLY
#endif

#if defined(__unix__) || defined(__unix) || defined(unix)
	#define PHOBOSPP_TARGET_ENVIRONMENT_UNIX
#elif defined(__CYGWIN__)
	#define PHOBOSPP_TARGET_CYGWIN
#endif

#if defined(PHOBOSPP_TARGET_ENVIRONMENT_UNIX) || defined(PHOBOSPP_TARGET_PLATFORM_APPLE_MAC)
	#define PHOBOSPP_TARGET_ENVIRONMENT_POSIX
#endif

#ifdef _WIN16
	#define PHOBOSPP_TARGET_PLATFORM_WINDOWS
	#define PHOBOSPP_TARGET_PLATFORM_WINDOWS_16
#elif defined(_WIN32)
	#define PHOBOSPP_TARGET_PLATFORM_WINDOWS
	#define PHOBOSPP_TARGET_PLATFORM_WINDOWS_32
	#ifdef _WIN64
		#define PHOBOSPP_TARGET_PLATFORM_WINDOWS_86_64
	#endif
#elif __APPLE__
	#define PHOBOSPP_TARGET_PLATFORM_APPLE
	#if defined(__APPLE_CPP__) || defined(__APPLE_CC__) || defined(__MACOS_CLASSIC__)
		#if (defined(__APPLE__) && defined(__MACH__)) || defined(macintosh) || defined(Macintosh)
			#define PHOBOSPP_TARGET_PLATFORM_APPLE_MAC
		#endif
		#if defined(__GNUC__)
			#if 0
				#define INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_EMBEDDED          @CONFIG_EMBEDDED@
				#define INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_IPHONE            @CONFIG_IPHONE@
				#define INTERNAL_PHOBOSPP_TARGET_PLATFORM_IPHONE_SIMULATOR     @CONFIG_IPHONE_SIMULATOR@
				#if INTERNAL_PHOBOSPP_TARGET_PLATFORM_IPHONE_SIMULATOR
					#define PHOBOSPP_TARGET_PLATFORM_APPLE_IPHONE_SIMULATOR
				#elif INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_IPHONE
					#define PHOBOSPP_TARGET_PLATFORM_APPLE_IPHONE
				#elif INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_EMBEDDED
					#define PHOBOSPP_TARGET_PLATFORM_APPLE_EMBEDDED
				#endif
				#undef INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_EMBEDDED
				#undef INTERNAL_PHOBOSPP_TARGET_PLATFORM_OS_IPHONE
				#undef INTERNAL_PHOBOSPP_TARGET_PLATFORM_IPHONE_SIMULATOR
			#endif
		#endif
	#endif
#elif defined(PHOBOSPP_TARGET_KERNEL_LINUX)
	#ifdef __gnu_linux__
		#define PHOBOSPP_TARGET_PLATFORM_GNU_LINUX
	#endif
#elif defined(__ANDROID__)
	#define PHOBOSPP_TARGET_PLATFORM_ANDROID
#endif

#if defined(PHOBOSPP_TARGET_KERNEL_LINUX) || defined(PHOBOSPP_TARGET_CYGWIN)
	#include <endian.h>
#elif defined(PHOBOSPP_TARGET_PLATFORM_APPLE)
	#include <libkern/OSByteOrder.h>

	#define htobe16(x) OSSwapHostToBigInt16(x)
	#define htole16(x) OSSwapHostToLittleInt16(x)
	#define be16toh(x) OSSwapBigToHostInt16(x)
	#define le16toh(x) OSSwapLittleToHostInt16(x)

	#define htobe32(x) OSSwapHostToBigInt32(x)
	#define htole32(x) OSSwapHostToLittleInt32(x)
	#define be32toh(x) OSSwapBigToHostInt32(x)
	#define le32toh(x) OSSwapLittleToHostInt32(x)

	#define htobe64(x) OSSwapHostToBigInt64(x)
	#define htole64(x) OSSwapHostToLittleInt64(x)
	#define be64toh(x) OSSwapBigToHostInt64(x)
	#define le64toh(x) OSSwapLittleToHostInt64(x)

	#define __BYTE_ORDER BYTE_ORDER
	#define __BIG_ENDIAN BIG_ENDIAN
	#define __LITTLE_ENDIAN LITTLE_ENDIAN
	#define __PDP_ENDIAN PDP_ENDIAN
#elif defined(PHOBOSPP_TARGET_KERNEL_OPENBSD)
	#include <sys/endian.h>
#elif defined(PHOBOSPP_TARGET_KERNEL_NETBSD) || defined(PHOBOSPP_TARGET_KERNEL_FREEBSD) || defined(PHOBOSPP_TARGET_KERNEL_DRAGONFLY)
	#include <sys/endian.h>
	#define be16toh(x) betoh16(x)
	#define le16toh(x) letoh16(x)

	#define be32toh(x) betoh32(x)
	#define le32toh(x) letoh32(x)

	#define be64toh(x) betoh64(x)
	#define le64toh(x) letoh64(x)
#elif defined(PHOBOSPP_TARGET_PLATFORM_WINDOWS)
	#include <winsock2.h>
	#include <sys/param.h>

	#if BYTE_ORDER == LITTLE_ENDIAN
		#define htobe16(x) htons(x)
		#define htole16(x) (x)
		#define be16toh(x) ntohs(x)
		#define le16toh(x) (x)

		#define htobe32(x) htonl(x)
		#define htole32(x) (x)
		#define be32toh(x) ntohl(x)
		#define le32toh(x) (x)

		#define htobe64(x) htonll(x)
		#define htole64(x) (x)
		#define be64toh(x) ntohll(x)
		#define le64toh(x) (x)
	#elif BYTE_ORDER == BIG_ENDIAN

		#define htobe16(x) (x)
		#define htole16(x) __builtin_bswap16(x)
		#define be16toh(x) (x)
		#define le16toh(x) __builtin_bswap16(x)

		#define htobe32(x) (x)
		#define htole32(x) __builtin_bswap32(x)
		#define be32toh(x) (x)
		#define le32toh(x) __builtin_bswap32(x)

		#define htobe64(x) (x)
		#define htole64(x) __builtin_bswap64(x)
		#define be64toh(x) (x)
		#define le64toh(x) __builtin_bswap64(x)
	#endif

	#define __BYTE_ORDER BYTE_ORDER
	#define __BIG_ENDIAN BIG_ENDIAN
	#define __LITTLE_ENDIAN LITTLE_ENDIAN
	#define __PDP_ENDIAN PDP_ENDIAN
#endif

#endif // PHOBOSPP_CORE_SYSTEM_H
