#include "globals.h"
#include "fmt/format.h"

void hexdump(std::ostream& stream, const std::vector<uint8_t>& buffer)
{
	size_t pos = 0;

	while (pos < buffer.size())
	{
		stream << fmt::format("{:05x} : ", pos);
		for (int i=0; i<16; i++)
		{
			if ((pos+i) < buffer.size())
				stream << fmt::format("{:02x} ", buffer.at(pos+i));
			else
				stream << "-- ";
		}
		stream << " : ";
		for (int i=0; i<16; i++)
		{
			if ((pos+i) >= buffer.size())
				break;

			uint8_t c = buffer.at(pos+i);
			stream << (isprint(c) ? (char)c : '.');
		}
		stream << std::endl;

		pos += 16;
	}
}

