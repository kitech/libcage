/* $Id: bn.hpp,v 1.4 2007/05/23 09:29:59 ytakanoster Exp $ */

/*
 * Copyright (c) 2009, Yuuki Takano (ytakanoster@gmail.com).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the writers nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef CAGETYPES_HPP
#define CAGETYPES_HPP

#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>

#include "common.hpp"

namespace libcage {
        typedef boost::shared_ptr<sockaddr_in>  in_ptr;
        typedef boost::shared_ptr<sockaddr_in6> in6_ptr;
        typedef boost::shared_ptr<uint160_t>    id_ptr;

        struct cageaddr {
                id_ptr          id;
                sa_family_t     domain; // PF_INET || PF_INET6
                boost::variant<in_ptr, in6_ptr> saddr;
        };

        static const uint16_t MAGIC_NUMBER = 0xbabe;
        static const uint16_t CAGE_VERSION = 0;

        static const uint16_t domain_loopback = 0;
        static const uint16_t domain_inet     = 1;
        static const uint16_t domain_inet6    = 2;

        static const uint16_t type_nat_echo                = 0;
        static const uint16_t type_nat_echo_reply          = 1;
        static const uint16_t type_nat_echo_redirect       = 2;
        static const uint16_t type_nat_echo_redirect_reply = 3;
        static const uint16_t type_dtun_ping         = 0;
        static const uint16_t type_dtun_ping_reply   = 1;

        struct msg_hdr {
                uint16_t        magic;
                uint16_t        ver;
                uint16_t        type;
                uint16_t        reserved;
                uint8_t         src[20];
                uint8_t         dst[20];
        };

        struct msg_nat_echo {
                msg_hdr         hdr;
                uint32_t        nonce;
        };

        struct msg_nat_echo_reply {
                msg_hdr         hdr;
                uint32_t        nonce;
                uint16_t        domain;
                uint16_t        port;
                uint8_t         addr[16];
        };

        struct msg_nat_echo_redirect {
                msg_hdr         hdr;
                uint32_t        nonce;
                uint16_t        port;
                uint16_t        padding;
        };

        struct msg_nat_echo_redirect_reply {
                msg_hdr         hdr;
                uint32_t        nonce;
                uint16_t        domain;
                uint16_t        port;
                uint8_t         addr[16];
        };

        struct msg_dtun_ping {
                msg_hdr         hdr;
                uint32_t        nonce;
        };

        struct msg_dtun_ping_reply {
                msg_hdr         hdr;
                uint32_t        nonce;
        };
}


#endif // CAGETYPES_HPP
