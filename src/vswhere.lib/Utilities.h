// <copyright file="Utilities.h" company="Microsoft Corporation">
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt in the project root for license information.
// </copyright>

#pragma once

typedef std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> wstring_converter;

std::string to_string(const std::wstring& value);

struct ci_equal : public std::function<bool(std::wstring, std::wstring)>
{
    bool operator()(const std::wstring& lhs, const std::wstring& rhs) const
    {
        return CSTR_EQUAL == ::CompareStringW(LOCALE_INVARIANT, NORM_IGNORECASE, lhs.c_str(), SIZE_T_TO_INT(lhs.size()), rhs.c_str(), SIZE_T_TO_INT(rhs.size()));
    }
};

struct ci_less : public std::function<bool(std::wstring, std::wstring)>
{
    bool operator()(const std::wstring& lhs, const std::wstring& rhs) const
    {
        return CSTR_EQUAL > ::CompareStringW(LOCALE_INVARIANT, NORM_IGNORECASE, lhs.c_str(), SIZE_T_TO_INT(lhs.size()), rhs.c_str(), SIZE_T_TO_INT(rhs.size()));
    }
};
