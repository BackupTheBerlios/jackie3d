#if !defined( JACKIE_UTIL_TYPES_HPP )
#define JACKIE_UTIL_TYPES_HPP

/***************************************************************************
 *  Copyright (C) 2004 by David Rigel García García                        *
 *  info@NO-SPAMjackie3d.org                                               *
 *                                                                         *
 *  All rights reserved.                                                   *
 *                                                                         *
 *  Redistribution and use in source and binary forms, with or without     *
 *  modification, are permitted provided that the following conditions     *
 *  are met:                                                               *
 *                                                                         *
 *      o Redistributions of source code must retain the above copyright   *
 *        notice, this list of conditions and the following disclaimer.    *
 *      o Redistributions in binary form must reproduce the above          *
 *        copyright notice, this list of conditions and the following      *
 *        disclaimer in the documentation and other materials provided     *
 *        with the distribution.                                           *
 *      o None of the names of its contributors may be used to             *
 *        endorse or promote products derived from this software without   *
 *        specific prior written permission.                               *
 *                                                                         *
 *  THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     *
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. *
 *  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,      *
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED     *
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, *
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF  *
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 *  DAMAGE.                                                                *
 ***************************************************************************/

/** Basic data types */

#include "util/port/primitivetypes.hpp"

namespace jackie {
namespace util {

class jfloat {
private:
	:jki::JtFloat	value;
public:
	static const jfloat PI=       3.14159265358979;
    static const jfloat EPSILON=  1.0e-10;
	static const jfloat INFINITY= 10e38;

	// Constructors
	jfloat()                   { }
	jfloat(const jfloat &other){ value= other.value; }
	jfloat(:jki::JtFloat &f)   { value= f; }
	jfloat(float &f)           { value= static_cast<:jki::JtFloat>(f); }
	jfloat(double &f)          { value= static_cast<:jki::JtFloat>(f); }


	// Assignment
	float &operator =(const jfloat &other) {
		// no need to check whether other == *this
		// because there's no danger involved
		*this= jfloat(other);
		return *this;
	}
	jfloat &operator =(const :jki::JtFloat &other)
	{ *this= jfloat(other); return *this; }
	jfloat &operator =(const float &other)
	{ *this= jfloat(other); return *this; }
	jfloat &operator =(const double &other)
	{ *this= jfloat(other); return *this; }
};

// TODO: unit test & jint32 jint64

} } // end namespace jackie::util

#endif // !defined( JACKIE_UTIL_TYPES_HPP )
