#pragma once

#include "RE/Scaleform/Kernel/SF_Memory.h"

namespace RE
{
	namespace Scaleform
	{
		class RefCountImpl;
		class RefCountImplCore;

		class RefCountImplCore
		{
		public:
			static constexpr auto RTTI{ RTTI_Scaleform__RefCountImplCore };

			RefCountImplCore() = default;
			virtual ~RefCountImplCore() = default;	// 00

		protected:
			// members
			volatile std::int32_t refCount{ 1 };  // 08
		};
		static_assert(sizeof(RefCountImplCore) == 0x10);

		class RefCountImpl :
			public RefCountImplCore	 // 00
		{
		public:
			static constexpr auto RTTI{ RTTI_Scaleform__RefCountImpl };

			virtual ~RefCountImpl() = default;	// 00

			inline void AddRef()
			{
				stl::atomic_ref myRefCount{ refCount };
				++refCount;
			}

			inline void Release()
			{
				stl::atomic_ref myRefCount{ refCount };
				if (--myRefCount == 0) {
					delete this;
				}
			}
		};
		static_assert(sizeof(RefCountImpl) == 0x10);

		template <class Base, std::int32_t>
		class RefCountBaseStatImpl :
			public Base	 // 00
		{
		public:
			RefCountBaseStatImpl() = default;

			SF_HEAP_REDEFINE_NEW(RefCountBaseStatImpl);
		};
		//static_assert(sizeof(RefCountBaseStatImpl<void*, 0>) == 0x10);

		template <class, std::int32_t STAT>
		class RefCountBase :
			public RefCountBaseStatImpl<RefCountImpl, STAT>	 // 00
		{
		public:
			RefCountBase() = default;
		};
		//static_assert(sizeof(RefCountBase<void*, 0>) == 0x10);

		template <class T>
		class Ptr
		{
		public:
			using element_type = T;

			// 1
			inline constexpr Ptr() noexcept :
				_ptr(nullptr)
			{}

			// 2
			inline constexpr Ptr(std::nullptr_t) noexcept :
				_ptr(nullptr)
			{}

			// 3
			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline explicit Ptr(Y* a_rhs) :
				_ptr(a_rhs)
			{
				TryAttach();
			}

			// 9a
			inline Ptr(const Ptr& a_rhs) :
				_ptr(a_rhs._ptr)
			{
				TryAttach();
			}

			// 9b
			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline Ptr(const Ptr<Y>& a_rhs) :
				_ptr(a_rhs._ptr)
			{
				TryAttach();
			}

			// 10a
			inline Ptr(Ptr&& a_rhs) noexcept :
				_ptr(std::move(a_rhs._ptr))
			{
				a_rhs._ptr = nullptr;
			}

			// 10b
			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline Ptr(Ptr<Y>&& a_rhs) noexcept :
				_ptr(std::move(a_rhs._ptr))
			{
				a_rhs._ptr = nullptr;
			}

			inline ~Ptr() { TryDetach(); }

			// 1a
			inline Ptr& operator=(const Ptr& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					TryDetach();
					_ptr = a_rhs._ptr;
					TryAttach();
				}
				return *this;
			}

			// 1b
			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline Ptr& operator=(const Ptr<Y>& a_rhs)
			{
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
				return *this;
			}

			// 2a
			inline Ptr& operator=(Ptr&& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					TryDetach();
					_ptr = std::move(a_rhs._ptr);
					a_rhs._ptr = nullptr;
				}
				return *this;
			}

			// 2b
			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline Ptr& operator=(Ptr<Y>&& a_rhs)
			{
				TryDetach();
				_ptr = std::move(a_rhs._ptr);
				a_rhs._ptr = nullptr;
				return *this;
			}

			inline void reset()
			{
				TryDetach();
			}

			template <
				class Y,
				std::enable_if_t<
					std::is_convertible_v<
						Y*,
						element_type*>,
					int> = 0>
			inline void reset(Y* a_ptr)
			{
				if (_ptr != a_ptr) {
					TryDetach();
					_ptr = a_ptr;
					TryAttach();
				}
			}

			[[nodiscard]] constexpr element_type* get() const noexcept
			{
				return _ptr;
			}

			[[nodiscard]] explicit constexpr operator bool() const noexcept
			{
				return static_cast<bool>(_ptr);
			}

			[[nodiscard]] constexpr element_type& operator*() const noexcept
			{
				assert(static_cast<bool>(*this));
				return *_ptr;
			}

			[[nodiscard]] constexpr element_type* operator->() const noexcept
			{
				assert(static_cast<bool>(*this));
				return _ptr;
			}

		protected:
			template <class>
			friend class Ptr;

			inline void TryAttach()
			{
				if (_ptr) {
					_ptr->AddRef();
				}
			}

			inline void TryDetach()
			{
				if (_ptr) {
					_ptr->Release();
					_ptr = nullptr;
				}
			}

			// members
			element_type* _ptr;	 // 0
		};
		//static_assert(sizeof(Ptr<void*>) == 0x8);

		template <class T, class... Args>
		[[nodiscard]] inline Ptr<T> make_shared(Args&&... a_args)
		{
			auto ptr = Ptr<T>{ new T(std::forward<Args>(a_args)...) };
			if (ptr) {
				ptr->Release();	 // ensure lifetime ends with smart pointer
			}
			return ptr;
		}

		template <class T1, class T2>
		[[nodiscard]] constexpr bool operator==(const Ptr<T1>& a_lhs, const Ptr<T2>& a_rhs)
		{
			return a_lhs.get() == a_rhs.get();
		}

		template <class T1, class T2>
		[[nodiscard]] constexpr bool operator!=(const Ptr<T1>& a_lhs, const Ptr<T2>& a_rhs)
		{
			return !(a_lhs == a_rhs);
		}

		template <class T>
		[[nodiscard]] constexpr bool operator==(const Ptr<T>& a_lhs, std::nullptr_t) noexcept
		{
			return !a_lhs;
		}

		template <class T>
		[[nodiscard]] constexpr bool operator==(std::nullptr_t, const Ptr<T>& a_rhs) noexcept
		{
			return !a_rhs;
		}

		template <class T>
		[[nodiscard]] constexpr bool operator!=(const Ptr<T>& a_lhs, std::nullptr_t) noexcept
		{
			return static_cast<bool>(a_lhs);
		}

		template <class T>
		[[nodiscard]] constexpr bool operator!=(std::nullptr_t, const Ptr<T>& a_rhs) noexcept
		{
			return static_cast<bool>(a_rhs);
		}

		template <class T>
		Ptr(T*) -> Ptr<T>;
	}
}