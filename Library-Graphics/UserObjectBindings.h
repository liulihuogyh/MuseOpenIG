/*
-----------------------------------------------------------------------------
File:        UserObjectBindings.h
Copyright:   Copyright (C) 2007-2015 Poojan Prabhu. All rights reserved.
Created:     10/20/2015
Last edit:   12/15/2015
Author:      Poojan Prabhu
E-mail:      poojanprabhu@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#pragma once

#if defined(OPENIG_SDK)
	#include <OpenIG-Graphics/export.h>
#else
	#include <Library-Graphics/export.h>
#endif

#include <map>
#include <iostream>
#include <boost/any.hpp>

namespace OpenIG {
	namespace Library {
		namespace Graphics {

			class IGLIBGRAPHICS_EXPORT UserObjectBindings
			{
			public:
				UserObjectBindings();
				virtual ~UserObjectBindings();

				void SetUserAny(const std::string& key, const boost::any& anything);
				bool HasKey(const std::string& key) const;
				const boost::any& GetUserAny(const std::string& key);
				void EraseKey(const std::string& key);
			private:

				typedef std::map<std::string, boost::any > UserObjectsMap;
				UserObjectsMap m_UserObjectsMap;
			};
		}
	}
}

