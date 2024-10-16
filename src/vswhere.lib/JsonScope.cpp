// <copyright file="JsonScope.cpp" company="Microsoft Corporation">
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt in the project root for license information.
// </copyright>

#include "stdafx.h"

using namespace std;

void JsonScope::StartScope()
{
    WriteSeparator();
}

void JsonScope::StartProperty()
{
    // Delay writing the parent scope until we write a property.
    WriteStart();

    WriteSeparator();
    RequireSeparator();
}

void JsonScope::WriteStartImpl()
{
    bool writeKey = false;

    WriteSeparator();

    if (Parent())
    {
        if (Parent()->IsObject())
        {
            writeKey = true;
        }

        // Write new line if not the root scope.
        VirtualConsole().WriteLine();
    }

    if (writeKey && Name().length())
    {
        VirtualConsole().Write(
            L"%ls%ls\"%ls\"%ls: %lc",
            Padding().c_str(),
            VirtualConsole().Color(JsonFormatter::ColorName),
            Name().c_str(),
            VirtualConsole().ResetColor(),
            StartChar());
    }
    else
    {
        VirtualConsole().Write(L"%ls%lc", Padding().c_str(), StartChar());
    }
}

void JsonScope::WriteEndImpl()
{
    if (m_requireSep)
    {
        // Write new line and padding only if elements were written.
        // This keeps empty arrays and objects looking like [] and {}.
        VirtualConsole().Write(L"\n%ls", Padding().c_str());
    }

    VirtualConsole().Write(L"%lc", EndChar());
}

void JsonScope::RequireSeparator() noexcept
{
    m_requireSep = true;

    if (auto p = Parent())
    {
        p->RequireSeparator();
    }
}

void JsonScope::WriteSeparator()
{
    if (m_requireSep)
    {
        VirtualConsole().Write(L",");
    }
}
