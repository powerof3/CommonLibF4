#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSThread.h"
#include "RE/Bethesda/Events.h"

namespace RE
{
	namespace BSSaveDataSystemUtility
	{
		enum class RESULT;
	}

	class BGSSaveLoadFile;
	class BSEventFlag;
	class BSSaveDataSystemUtilityFile;

	class BGSSaveLoadFileEntry
	{
	public:
		// members
		const char*        fileName;          // 00
		const char*        playerName;        // 08
		const char*        playerTitle;       // 10
		const char*        location;          // 18
		const char*        playTime;          // 20
		const char*        raceName;          // 28
		std::int32_t       version;           // 30
		std::uint32_t      saveGameNumber;    // 34
		std::uint32_t      playerLevel;       // 38
		float              levelProgress;     // 3C
		float              levelThreshold;    // 40
		std::uint32_t      screenshotWidth;   // 44
		std::uint32_t      screenshotHeight;  // 48
		std::uint32_t      screenshotOffset;  // 4C
		REX::W32::FILETIME fileTime;          // 50
		REX::W32::FILETIME saveTime;          // 58
		std::int32_t       deviceID;          // 60
		bool               loaded;            // 64
		bool               corrupt;           // 65
		bool               needsSync;         // 66
	};
	static_assert(sizeof(BGSSaveLoadFileEntry) == 0x68);

	struct BGSNumericIDIndex
	{
	public:
		~BGSNumericIDIndex() noexcept {}  // intentional

		enum class Flags : std::uint8_t
		{
			kDefault = 1u << 6,  // idx 0x00
			kCreated = 1u << 7,  // idx 0xFF
		};

		[[nodiscard]] bool IsCreated() const noexcept { return flags.all(Flags::kCreated); }
		[[nodiscard]] bool IsDefault() const noexcept { return flags.all(Flags::kDefault); }

		[[nodiscard]] std::uint32_t GetNumericID() const
		{
			using func_t = decltype(&BGSNumericIDIndex::GetNumericID);
			static REL::Relocation<func_t> func{ REL::ID(2228199) };
			return func(this);
		}
		void SetNumericID(std::uint32_t a_formID)
		{
			using func_t = decltype(&BGSNumericIDIndex::SetNumericID);
			static REL::Relocation<func_t> func{ REL::ID(2228200) };
			return func(this, a_formID);
		}

		// members
		union
		{
			struct
			{
				union
				{
					std::uint8_t                      data1;
					REX::EnumSet<Flags, std::uint8_t> flags;
				};  // 0
				std::uint8_t data2;  // 1
				std::uint8_t data3;  // 2
			};
			std::uint8_t data[3]{ 0 };
		};  // 0
	};
	static_assert(sizeof(BGSNumericIDIndex) == 0x3);

	class alignas(0x80) BGSSaveLoadThread :
		public BSThread  // 00
	{
	public:
		struct AsyncRequest
		{
		public:
			using TaskFinishedCallback_t = void (*)(bool);

			// members
			std::uint32_t          taskTypeID;            // 00
			BGSSaveLoadFile*       savefile;              // 08
			TaskFinishedCallback_t taskFinishedCallback;  // 10
			BSFixedString          previousSaveToDelete;  // 18
		};
		static_assert(sizeof(AsyncRequest) == 0x20);

		virtual ~BGSSaveLoadThread();  // 00

		// members
		bool        running;   // 50
		bool        busy;      // 51
		BSEventFlag haveTask;  // 58
		// BSTCommonStaticMessageQueue<AsyncRequest, 8> asyncSaveLoadOperationQueue;  // 80
		std::byte pad80[0x780 - 0x80];
	};
	static_assert(sizeof(BGSSaveLoadThread) == 0x780);

	class BSSaveDataSystemUtilityImage
	{
	public:
		// members
		std::uint32_t size;    // 00
		std::uint32_t width;   // 04
		std::uint32_t height;  // 08
		char*         buffer;  // 10
	};
	static_assert(sizeof(BSSaveDataSystemUtilityImage) == 0x18);

	class BGSSaveLoadManager :
		public BSTEventSink<SPECIALMenuEvent::NameChangedEvent>  // 00
	{
	public:
		using SaveCompleteCallback_t = void (*)(BSSaveDataSystemUtility::RESULT, BSSaveDataSystemUtilityFile**);
		using LoadCompleteCallback_t = void (*)(BSSaveDataSystemUtility::RESULT, BSSaveDataSystemUtilityFile**);

		enum class QUEUED_TASK : std::int32_t
		{
			kAutoSave = 0x1,
			kForceSave = 0x2,
			kLoadMostRecentSave = 0x4,
			kQuickSave = 0x8,
			kQuickLoad = 0x10,
			kQuickNewSave = 0x20,
			kLoadGame = 0x40,
			kSysUtilLoadGame = 0x80,
			kMissingContentLoad = 0x100,
			kAutoSaveCommit = 0x200,
			kQuickSaveCommit = 0x400,
			kCaptureFaceGen = 0x800,
			kBuildSaveGameList = 0x1000,
			kRefreshScreenshot = 0x2000,
			kSaveAndQuit = 0x4000,
			kConfirmModsLoad = 0x8000,
			kSaveAndQuitToDesktop = 0x10000,
		};

		virtual ~BGSSaveLoadManager();  // 00

		// override (BSTEventSink)
		BSEventNotifyControl ProcessEvent(const SPECIALMenuEvent::NameChangedEvent& a_event, BSTEventSource<SPECIALMenuEvent::NameChangedEvent>* a_source) override;  // 01

		[[nodiscard]] static BGSSaveLoadManager* GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadManager**> singleton{ REL::ID(2697802) };
			return *singleton;
		}

		void QueueSaveLoadTask(QUEUED_TASK a_task)
		{
			using func_t = decltype(&BGSSaveLoadManager::QueueSaveLoadTask);
			static REL::Relocation<func_t> func{ REL::ID(2228080) };
			return func(this, a_task);
		}

		bool LoadGame(const char* a_fileName, std::int32_t a_deviceID, std::uint32_t a_outputStats, bool a_checkForMods, bool a_ignoreMissingContent)
		{
			using func_t = decltype(&BGSSaveLoadManager::LoadGame);
			static REL::Relocation<func_t> func{ REL::ID(2228039) };
			return func(this, a_fileName, a_deviceID, a_outputStats, a_checkForMods, a_ignoreMissingContent);
		}

		void BuildSaveGameList(std::uint64_t a_playerID)
		{
			using func_t = decltype(&BGSSaveLoadManager::BuildSaveGameList);
			static REL::Relocation<func_t> func{ REL::ID(2228053) };
			return func(this, a_playerID);
		}

		// members
		BSTArray<BGSSaveLoadFileEntry*>          saveGameList;                  // 008
		bool                                     isSaveListBuilt;               // 020
		std::uint32_t                            saveGameCount;                 // 024
		std::uint32_t                            currentSaveGameNumber;         // 028
		std::uint64_t                            saveGameListBuildID;           // 030
		std::int32_t                             currentAutoSaveNumber;         // 038
		bool                                     simulatedMode;                 // 03C
		bool                                     autosaveDisabledForDiskspace;  // 03D
		std::uint32_t                            queuedTasks;                   // 040
		std::uint32_t                            saveOperationDelayCounter;     // 044
		BGSSaveLoadFileEntry*                    queuedEntryToLoad;             // 048
		std::uint64_t                            lastSaveTime;                  // 050
		bool                                     savingAllowed;                 // 058
		char*                                    mostRecentSaveGame;            // 060
		std::int32_t                             mostRecentSaveGameDeviceID;    // 068
		BSTHashMap<std::uint64_t, BSFixedString> playerIDNameMap;               // 070
		BSTHashMap<BSFixedString, BSFixedString> editorIdLocationMap;           // 0A0
		std::uint64_t                            currentPlayerID;               // 0D0
		std::uint64_t                            displayPlayerID;               // 0D8
		BSFixedString                            savefileNameToDelete;          // 0E0
		BSTHashMap<std::uint32_t, BSFixedString> autosaveFileNames;             // 0E8
		BSFixedString                            quicksaveFileName;             // 118
		BSFixedString                            exitsaveFileName;              // 120
		bool                                     hasSaveData;                   // 128
		BGSSaveLoadFile*                         saveLoadFile;                  // 130
		bool                                     returnedFromSysUtil;           // 138
		bool                                     sysUtilLoadDataComplete;       // 139
		SaveCompleteCallback_t                   sysUtilSaveCompleteCallback;   // 140
		LoadCompleteCallback_t                   sysUtilLoadCompleteCallback;   // 148
		BSSaveDataSystemUtilityImage             saveDataCreateImage;           // 150
		BSSaveDataSystemUtilityImage             saveDataBackgroundImage;       // 168
		BSSaveDataSystemUtilityImage             saveDataIconEncodedImage;      // 180
		NiPointer<NiTexture>                     screenshot[1];                 // 198
		BGSSaveLoadThread                        saveLoadTasksThread;           // 200
	};
	static_assert(sizeof(BGSSaveLoadManager) == 0x980);
}
