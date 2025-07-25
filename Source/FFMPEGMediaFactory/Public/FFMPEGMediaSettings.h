// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"

#include "FFMPEGMediaSettings.generated.h"

UENUM()
enum class ESynchronizationType : uint8 {
    AudioMaster = 0,
    VideoMaster,
    ExternalClock
};

UENUM()
enum class ERTSPTransport : uint8 {
    Default = 0,
    Udp,
    UdpMulticast,
    Tcp,
    Http,
    Https
};



/**
 * Settings for the WmfMedia plug-in.
 */
UCLASS(config=GameUserSettings, defaultconfig)
class FFMPEGMEDIAFACTORY_API UFFMPEGMediaSettings
	: public UObject
{
	GENERATED_BODY()

public:
	 
	/** Default constructor. */
	UFFMPEGMediaSettings();
   

public:

	
	UPROPERTY(config, EditAnywhere, Category=Media)
	bool UseInfiniteBuffer;
    

    UPROPERTY(config, EditAnywhere, Category = Media)
    bool AllowFrameDrop;

    UPROPERTY(config, EditAnywhere, Category = Media)
    bool UseHardwareAcceleratedCodecs;

    UPROPERTY(config, EditAnywhere, Category = Media)
    bool DisableAudio;

    UPROPERTY(config, EditAnywhere, Category=Media)
	bool ZeroLatencyStreaming;
    
    UPROPERTY(config, EditAnywhere, Category = Media)
    ERTSPTransport RtspTransport;

    //Allow non spec compliant speedup tricks.
    UPROPERTY(config, EditAnywhere, Category = Media)
    bool SpeedUpTricks;

    UPROPERTY(config, EditAnywhere, Category = Media, meta = (UIMin=0, UIMax = 16))
    int AudioThreads;

    UPROPERTY(config, EditAnywhere, Category = Media, meta = (UIMin=0, UIMax = 16))
    int VideoThreads;

	UPROPERTY(config, EditAnywhere, Category = Media)
	ESynchronizationType SyncType;


public:
	void GetSyncTypes(TArray<FName>& OutNames)
	{
		if (UEnum* EnumPtr = StaticEnum<ESynchronizationType>())
		{
			int32 NumEnum = EnumPtr->NumEnums();
			for (int32 i = 0; i < NumEnum; ++i)
			{
				ESynchronizationType Type = static_cast<ESynchronizationType>(EnumPtr->GetValueByIndex(i));

				if ((int64)Type == EnumPtr->GetMaxEnumValue())
				{
					continue;
				}
				
				OutNames.Add(EnumPtr->GetNameByIndex(i));
			}
		}
	}

	void GetTransportTypes(TArray<FName>& OutNames)
	{
		if (UEnum* EnumPtr = StaticEnum<ERTSPTransport>())
		{
			int32 NumEnum = EnumPtr->NumEnums();
			for (int32 i = 0; i < NumEnum; ++i)
			{
				ERTSPTransport Type = static_cast<ERTSPTransport>(EnumPtr->GetValueByIndex(i));
				if ((int64)Type == EnumPtr->GetMaxEnumValue())
				{
					continue;
				}
				
				OutNames.Add(EnumPtr->GetNameByIndex(i));
			}
		}
	}
};
