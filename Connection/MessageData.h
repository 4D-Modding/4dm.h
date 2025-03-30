#pragma once

namespace fdm::Connection
{
	struct MessageData
	{
		uint16_t type = 0;
		char content[];
	};
}
