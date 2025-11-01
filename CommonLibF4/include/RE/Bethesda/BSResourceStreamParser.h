#pragma once

#include "RE/Bethesda/BSResourceNiBinaryStream.h"

namespace RE
{
	class NiBinaryStream;

	class BSStreamParserData
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSStreamParserData };
		inline static constexpr auto VTABLE{ VTABLE::BSStreamParserData };

		virtual ~BSStreamParserData() = default;  // 00

		virtual bool            Begin() = 0;      // 01
		virtual void            End() = 0;        // 02
		virtual NiBinaryStream* GetStream() = 0;  // 03
	};

	template <class T>
	class BSStreamParser
	{
	public:
		BSStreamParser(BSStreamParserData* a_data) :
			data(a_data)
		{
			if (const auto stream = a_data->GetStream()) {
				NiBinaryStream::BufferInfo info;
				stream->GetBufferInfo(info);
				streamSizeInBytes = info.fileSize;
			}
		}

		// members
		T                   readBuffer[256]{};
		T*                  readPosition{ 0 };
		BSStreamParserData* data;
		std::uint64_t       streamSizeInBytes{ 0 };
	};
	static_assert(sizeof(BSStreamParser<char>) == 0x118);
	static_assert(sizeof(BSStreamParser<wchar_t>) == 0x218);

	class BSResourceStreamParser :
		public BSResourceNiBinaryStream,
		public BSStreamParserData
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSResourceStreamParser };
		inline static constexpr auto VTABLE{ VTABLE::BSResourceStreamParser };

		BSResourceStreamParser(const char* a_file) :
			BSResourceNiBinaryStream(a_file, false, nullptr, false)
		{}

		virtual ~BSResourceStreamParser() = default;  // 00

		// override (BSStreamParserData)
		virtual bool            Begin() override { return BSResourceNiBinaryStream::operator bool(); }  // 1:01
		virtual void            End() override {}                                                       // 1:02
		virtual NiBinaryStream* GetStream() override { return this; }                                   // 1:03
	};
}
