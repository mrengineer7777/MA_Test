/*
 MacAddress6.h - class to make it easier to handle BSSID and MAC addresses.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef MacAddress6_h
#define MacAddress6_h

#include <WString.h>

// A class to make it easier to handle and pass around 6-byte BSSID and MAC addresses.
class MacAddress6 {
private:
    union {
        struct {
            uint8_t align[2];
            uint8_t bytes[6];
        };
        uint64_t val;
    } _mac;

public:
    MacAddress6();
    MacAddress6(uint64_t mac);
    MacAddress6(const uint8_t *macbytearray);
    virtual ~MacAddress6() {}
    bool fromCStr(const char *buf);
    bool fromString(const String &address);
    void toBytes(uint8_t *buf);
    int  toCStr(char *buf);
    String toString() const;
    uint64_t Value();

    // Overloaded copy operators to allow initialisation of MacAddress6 objects from other types
    MacAddress6& operator=(const uint8_t *mac);
    MacAddress6& operator=(uint64_t macval);

    // Implicit conversion object to number [same as .Value()]
    operator uint64_t() const
    {
        return _mac.val;
    }

    // Allow comparing value of two classes
    bool operator==(const MacAddress6& mac2) const
    {
        return _mac.val == mac2._mac.val;
    }
};

#endif