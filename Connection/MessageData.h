#pragma once

namespace fdm::Connection
{
	class MessageData
	{
	public:
		unsigned short type = 0;
		char* content{};
	};
}