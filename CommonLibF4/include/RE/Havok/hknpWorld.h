#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBitField.h"
#include "RE/Havok/hkBlockStream.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkIntSpaceUtil.h"
#include "RE/Havok/hkRefPtr.h"
#include "RE/Havok/hkReferencedObject.h"
#include "RE/Havok/hkSimdFloat.h"
#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpBodyManager.h"
#include "RE/Havok/hknpConstraintManager.h"
#include "RE/Havok/hknpContactSolverType.h"
#include "RE/Havok/hknpMotionManager.h"
#include "RE/Havok/hknpShapeManager.h"
#include "RE/Havok/hknpSolverInfo.h"
#include "RE/Havok/hknpThreadSafetyCheck.h"
#include "RE/Havok/hknpWorldCinfo.h"
#include "RE/Havok/hknpWorldSignals.h"

namespace RE
{
	class hkBlockStreamAllocator;
	class hknpActionManager;
	class hknpBodyQualityLibrary;
	class hknpBroadPhase;
	class hknpCollisionCacheManager;
	class hknpCollisionDispatcher;
	class hknpCollisionQueryDispatcherBase;
	class hknpConstraintAtomSolver;
	class hknpContactConstraintSolver;
	class hknpDeactivationManager;
	class hknpEventDispatcher;
	class hknpInternalCommandProcessor;
	class hknpMaterialLibrary;
	class hknpModifierManager;
	class hknpMotionPropertiesLibrary;
	class hknpNullShapeTagCodec;
	class hknpPostCollideTask;
	class hknpPostSolveTask;
	class hknpShapeTagCodec;
	class hknpSimulation;
	class hknpSimulationContext;
	class hknpSolverSumVelocity;
	class hknpSolverVelocity;
	class hknpSpaceSplitter;
	class hkPrimaryCommandDispatcher;
	class hkSecondaryCommandDispatcher;

	class hknpWorld :
		public hkReferencedObject
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpWorld };
		static constexpr auto VTABLE{ VTABLE::hknpWorld };

		enum class AdditionMode : std::int32_t
		{
			kDoNotAddBody = 0,
			kAddBodyNow = 1,
			kAddBodyInNextStep = 2
		};

		enum class SimulationStage : std::int32_t
		{
			kDone = 0x1,
			kPreCollide = 0x2,
			kCollide = 0x4,
			kPostCollide = 0x8,
			kPreSolve = 0x10,
			kSolve = 0x20,
			kPostSolve = 0x40,
		};

		using AdditionFlagsEnum = hkcdRayQueryFlags::Enum;
		using LeavingBroadPhaseBehavior = hknpWorldCinfo::LeavingBroadPhaseBehavior;
		using SimulationType = hknpWorldCinfo::SimulationType;

		void AddBodies(hknpBodyId* a_ids, std::uint32_t a_idCount, AdditionMode a_additionMode, hkFlags<AdditionFlagsEnum, std::uint8_t> a_additionFlags)
		{
			using func_t = decltype(&hknpWorld::AddBodies);
			static REL::Relocation<func_t> func{ REL::ID(2255681) };
			func(this, a_ids, a_idCount, a_additionMode, a_additionFlags);
		}

		hknpBodyId& CreateBody(hknpBodyId& a_id, const hknpBodyCinfo& a_cInfo, AdditionMode a_additionMode, hkFlags<AdditionFlagsEnum, std::uint8_t> a_additionFlags)
		{
			using func_t = decltype(&hknpWorld::CreateBody);
			static REL::Relocation<func_t> func{ REL::ID(2255680) };
			return func(this, a_id, a_cInfo, a_additionMode, a_additionFlags);
		}

		hknpMotionId& CreateMotion(hknpMotionId& a_id, const hknpMotionCinfo& a_cInfo)
		{
			using func_t = decltype(&hknpWorld::CreateMotion);
			static REL::Relocation<func_t> func{ REL::ID(2255688) };
			return func(this, a_id, a_cInfo);
		}

		// members
		hknpBodyManager                                                 bodyManager;                       // 010
		hknpMotionManager                                               motionManager;                     // 0D8
		hknpConstraintManager                                           constraintManager;                 // 120
		hknpModifierManager*                                            modifierManager;                   // 150
		hkRefPtr<hkBlockStreamAllocator>                                persistentStreamAllocator;         // 158
		hkBlockStreamAllocator*                                         stepLocalStreamAllocator;          // 160
		hknpSimulation*                                                 simulation;                        // 168
		hknpSpaceSplitter*                                              spaceSplitter;                     // 170
		hknpBroadPhase*                                                 broadPhase;                        // 178
		hkIntSpaceUtil                                                  intSpaceUtil;                      // 180
		hkSimdFloat32                                                   collisionTolerance;                // 1E0
		hknpCollisionCacheManager*                                      collisionCacheManager;             // 1F0
		hknpCollisionDispatcher*                                        collisionDispatcher;               // 1F8
		hknpCollisionQueryDispatcherBase*                               collisionQueryDispatcher;          // 200
		hkBool                                                          contactCachingEnabled;             // 208
		hkBlockStream<std::int8_t>                                      lastFrameContactData;              // 210
		hknpContactSolverType::Enum                                     contactSolverType;                 // 310
		hknpContactConstraintSolver*                                    contactSolver;                     // 318
		hknpConstraintAtomSolver*                                       constraintAtomSolver;              // 320
		hknpSolverInfo                                                  solverInfo;                        // 330
		hkBool                                                          enableSolverDynamicScheduling;     // 470
		hkArray<hknpSolverVelocity>                                     solverVelocities;                  // 478
		hkArray<hknpSolverSumVelocity>                                  solverSumVelocities;               // 488
		hkBool                                                          deactivationEnabled;               // 498
		hknpDeactivationManager*                                        deactivationManager;               // 4A0
		hkBool                                                          deleteCachesOnDeactivation;        // 4A8
		hknpWorldSignals                                                signals;                           // 4B0
		hkPrimaryCommandDispatcher*                                     commandDispatcher;                 // 598
		hkRefPtr<hkSecondaryCommandDispatcher>                          traceDispatcher;                   // 5A0
		std::uint16_t                                                   userData;                          // 5A8
		hkVector4f                                                      gravity;                           // 5B0
		hkRefPtr<hkReferencedObject>                                    defaultModifierSet;                // 5C0
		hkRefPtr<hknpMaterialLibrary>                                   materialLibrary;                   // 5C8
		hkRefPtr<hknpMotionPropertiesLibrary>                           motionPropertiesLibrary;           // 5D0
		hkRefPtr<hknpBodyQualityLibrary>                                qualityLibrary;                    // 5D8
		hkBitField                                                      dirtyMaterials;                    // 5E0
		hkBitField                                                      dirtyQualities;                    // 5F8
		hknpShapeManager                                                shapeManager;                      // 610
		hkRefPtr<hknpShapeTagCodec>                                     shapeTagCodec;                     // 638
		hknpNullShapeTagCodec*                                          nullShapeTagCodec;                 // 640
		hkRefPtr<hknpEventDispatcher>                                   eventDispatcher;                   // 648
		hkRefPtr<hknpInternalCommandProcessor>                          internalPhysicsCommandDispatcher;  // 650
		hkBool                                                          consistencyChecksEnabled;          // 658
		hknpPostCollideTask*                                            postCollideTask;                   // 660
		hknpPostSolveTask*                                              postSolveTask;                     // 668
		hkEnum<SimulationStage, std::uint32_t>                          simulationStage;                   // 670
		hknpSimulationContext*                                          simulationContext;                 // 678
		hknpActionManager*                                              actionManager;                     // 680
		hkEnum<hknpWorldCinfo::SimulationType, std::uint8_t>            simulationType;                    // 688
		hkBool                                                          mergeEventsBeforeDispatch;         // 689
		hkEnum<hknpWorldCinfo::LeavingBroadPhaseBehavior, std::uint8_t> leavingBroadPhaseBehavior;         // 68A
		hknpThreadSafetyCheck                                           threadSafetyCheck;                 // 690
	};
	static_assert(sizeof(hknpWorld) == 0x6D0);
}
