// <copyright file="XmlScope.cpp" company="Microsoft Corporation">
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt in the project root for license information.
// </copyright>

#include "stdafx.h"

using namespace std;

void XmlScope::WriteStartImpl()
{
    VirtualConsole().Write(Padding());
    VirtualConsole().WriteLine(L"%ls<%ls>%ls", VirtualConsole().Color(XmlFormatter::ColorTag), Name().c_str(), VirtualConsole().ResetColor());
}

void XmlScope::WriteEndImpl()
{
    VirtualConsole().Write(Padding());
    VirtualConsole().WriteLine(L"%ls</%ls>%ls", VirtualConsole().Color(XmlFormatter::ColorTag), Name().c_str(), VirtualConsole().ResetColor());
}
