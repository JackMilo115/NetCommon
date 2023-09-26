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
	}
}