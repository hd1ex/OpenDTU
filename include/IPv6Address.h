// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "IPAddress.h"

class IPv6Address {
    uint32_t bytes[4];

public:
    IPv6Address(uint32_t data[4])
    {
        for (size_t i = 0; i < 4; i++)
        {
            bytes[i] = data[i];
        }
    }

    inline operator const uint32_t*() const
    {
        return &bytes[0];
    }
};
