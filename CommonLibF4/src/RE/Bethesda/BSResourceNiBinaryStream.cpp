#include "RE/Bethesda/BSResourceNiBinaryStream.h"

namespace RE
{
	BSResourceNiBinaryStream::BSResourceNiBinaryStream() :
		NiBinaryStream(),
		stream(nullptr),
		buffer(nullptr),
		pos(0),
		lastError(BSResource::ErrorCode::kNone)
	{}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_file, bool a_writeable, BSResource::Location* a_optionalStart, bool a_fullReadHint) :
		NiBinaryStream()
	{
		using func_t = void (*)(BSResourceNiBinaryStream*, const char*, bool, BSResource::Location*, bool);
		static REL::Relocation<func_t> func{ REL::ID(2269830) };
		func(this, a_file, a_writeable, a_optionalStart, a_fullReadHint);
	}

	BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
	{
		dtor();
	}
	void BSResourceNiBinaryStream::Seek(std::ptrdiff_t a_numBytes)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::Seek);
		REL::Relocation<func_t> func{ REL::ID(2269834) };
		return func(this, a_numBytes);
	}

	std::size_t BSResourceNiBinaryStream::DoRead(void* a_buf, std::size_t a_toRead)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoRead);
		REL::Relocation<func_t> func{ REL::ID(2269839) };
		return func(this, a_buf, a_toRead);
	}

	std::size_t BSResourceNiBinaryStream::DoWrite(const void* a_buf, std::size_t a_toWrite)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::DoWrite);
		REL::Relocation<func_t> func{ REL::ID(2269840) };  // rel id ?141B93D90
		return func(this, a_buf, a_toWrite);
	}

	void BSResourceNiBinaryStream::GetBufferInfo([[maybe_unused]] BufferInfo& a_buf)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::GetBufferInfo);
		REL::Relocation<func_t> func{ REL::ID(2269836) };
		return func(this, a_buf);
	}

	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = decltype(&BSResourceNiBinaryStream::dtor);
		REL::Relocation<func_t> func{ REL::ID(2269832) };  //1B93A00
		return func(this);
	}

	[[nodiscard]] BSResourceNiBinaryStream* BSResourceNiBinaryStream::BinaryStreamWithRescan(const char* a_fileName)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::BinaryStreamWithRescan);
		REL::Relocation<func_t> func{ REL::ID(543595) };
		return func(a_fileName);
	}
}
