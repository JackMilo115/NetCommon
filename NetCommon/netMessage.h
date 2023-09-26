#pragma once
#include "netCommon.h"

namespace olc
{
	namespace net
	{
		// Scruct that represents the message header
		template <typename T>
		struct message_header
		{
			T id{};
			uint32_t size = 0;
		};

		// Struct that represents the message
		template <typename T>
		struct message
		{
			message_header<T> header{};
			std::vector<uint8_t> body;

			size_t size() const
			{
				return sizeof(message_header<T>) + body.size();
			}

			// Temporary. Makes it easier to output to the console.
			friend std::ostream& operator << (std::ostream& os, const message<T>* msg)
			{
				os << "ID:" << int(msg.header.id) << " Size:" << msg.header.size;
				return os;
			}
		};
	}
}