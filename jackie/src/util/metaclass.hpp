#if !defined(JACKIE_UTIL_METACLASS_HPP)
#define JACKIE_UTIL_METACLASS_HPP
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

#include <string>
#include <map>
#include <iostream>

namespace jackie {
namespace util {

template < class BaseClass >
class MetaClass
{
private:
	// Avoid oxonobious warning
	// about friendless classes with just
	// private constructors
	friend class std::string;
	// Hidden constructor
	MetaClass() {}
	// Trivial virtual destructor
	~MetaClass() {}
	// Disable copy constructor
	MetaClass(const MetaClass &);
	// Disable assignment operator
	MetaClass &operator=(const MetaClass &);

protected:
	// Helper template class
	// Registers automatically class U in its constructor.
	// Use by declaring a global variable of this type
	// inside an anonymous namespace.
	// Let MyClass be a subclass of BaseClass. Then the following code:
	//     namespace {
	//         static RegisterClass< MyClass > singleton;
	//     }
	// registers automatically MyClass in MetaClass< BaseClass >
	template < class U >
	class RegisterClass
	{
	public:
		RegisterClass()
		{
			//:std::cout << "Registering class \"" << U::ClassID() << "\"."<< endl;
			MetaClass< BaseClass >::Instance().RegisterByName(
				U::ClassID(), U::NewInstance);
		}
	};

	// Virtual constructor type
	typedef BaseClass *(*BaseClassCtor)(const typename BaseClass::CtorParms &);

	// Concrete classes repository addressable by BaseClass name
	typedef std::map<
		const std::string,
		BaseClassCtor
		> CtorByNameRepositoryType;
	CtorByNameRepositoryType repositoryByName;

	// Find a constructor given the class identificator
	BaseClassCtor FindCtorByName(const std::string &classid) const
	{
		//:std::cout << "FindCtorByName(\"" << classid << "\")"<< endl;
		typename CtorByNameRepositoryType::const_iterator i;
		i= repositoryByName.find(classid);
		if( i != repositoryByName.end() ) {
			return (*i).second;
		} else {
			//return CtorPolicy::NullCtor;
			return NULL;
		}
	}

public:
	// Singleton pattern
	static MetaClass &Instance()
	{
		// Meyer's style singleton
		//:std::cout << "static MetaClass &Instance" << endl;
		static MetaClass instance;
		return instance;
	}

	// Registers a BaseClass given the class id
	void RegisterByName(const :std::string &classid, BaseClassCtor ctor)
	{
		// XXX: dispatch a warning if the classid is duplicated
		// Insert by name
		:std::cout << "Registrada clase \"" << classid << "\"." << :std::endl;
		repositoryByName[classid]= ctor;
	}

	// Factory method
	BaseClass *NewInstance(const :std::string &classid,
		const typename BaseClass::CtorParms &parms)
	{
		//:std::cout << "NewInstance(\"" << classid << "\")"<< endl;
		BaseClassCtor ctor= FindCtorByName(classid);
		if( ctor != NULL ) {
			return ctor(parms);
		} else {
			return NULL;
		}
	}
};

} } // end namespace jackie::util


#endif // !defined(JACKIE_UTIL_METACLASS_HPP)
