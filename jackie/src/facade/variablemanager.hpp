#if !defined(JACKIE_VARIABLEMANAGER_HPP)
#define JACKIE_VARIABLEMANAGER_HPP
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
#include <map>
#include <string>

namespace jackie {

/**
  * TODO: somehow we must declare temporally the predefined variables
  *       such as "N", "P", "Cs", etc.
  * NOTE: may use lex to scan the variable definitions
  */

class VariableManager
{
private:
	VariableManager();
	~VariableManager();
public:
	// Meyers' Singleton
	static VariableManager &Instance();

	// The class of the variable
	enum VClass { CONSTANT, UNIFORM, VARYING, VERTEX };
	// The type of the variable
	enum VType  { FLOAT, INTEGER, STRING, COLOR, POINT,
	              VECTOR, NORMAL, MATRIX, HPOINT };

	// Declare a variable
	// XXX: what if it was already declared??
	void Declare(const JtToken name, const JtToken declaration);

	// Get variable class
	// The variable can be either already declared, or declared inline
	VClass GetVClass(const JtToken name);

	// Get a variable type
	// The variable can be either already declared, or declared inline
	VType GetVType(const JtToken name);

	// Get a variable length
	// The variable can be either already declared, or declared inline
	jint64 GetVLength(const JtToken name);
};

} // end namespace jackie


#endif // !defined(JACKIE_VARIABLEMANAGER_HPP)
