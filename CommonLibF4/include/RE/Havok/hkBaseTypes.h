#pragma once

namespace RE
{
	class hkBool
	{
	public:
		~hkBool() noexcept {}  // intentional

		bool b;
	};

	template <class E, class U>
	using hkEnum = REX::EnumSet<E, U>;

	template <class E, class U>
	using hkFlags = REX::EnumSet<E, U>;

	template <class T>
	class hkPadSpu
	{
	public:
		~hkPadSpu() noexcept {}  // NOLINT(modernize-use-equals-default)

		void     operator=(T val) { storage = val; }
		T        val() const { return storage; }
		T&       operator*() { return &storage; }
		const T& operator*() const { return &storage; }
		T*       operator->() { return &storage; }
		const T* operator->() const { return &storage; }

		// members
		T storage;
	};

	enum class hkResultEnum
	{
		kSuccess,
		kFailure
	};

	struct hkResult
	{
	public:
		~hkResult() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		hkResultEnum e;  // 0
	};
	static_assert(sizeof(hkResult) == 0x4);
}
