// Verso Live FFMPEG player

#include "FFMPEGMediaSession.h"

#pragma region IMediaControls
bool FFFMPEGMediaSession::CanControl(EMediaControl Control) const
{
	return false;
}

FTimespan FFFMPEGMediaSession::GetDuration() const
{
	return FTimespan::Zero();
}

float FFFMPEGMediaSession::GetRate() const
{
	return 0.0f;
}

EMediaState FFFMPEGMediaSession::GetState() const
{
	return EMediaState::Closed;
}

EMediaStatus FFFMPEGMediaSession::GetStatus() const
{
	return EMediaStatus::None;
}

TRangeSet<float> FFFMPEGMediaSession::GetSupportedRates(EMediaRateThinning Thinning) const
{
	return TRangeSet<float>();
}

FTimespan FFFMPEGMediaSession::GetTime() const
{
	return FTimespan::Zero();
}

bool FFFMPEGMediaSession::IsLooping() const
{
	return false;
}

bool FFFMPEGMediaSession::Seek(const FTimespan& Time)
{
	return false;
}

bool FFFMPEGMediaSession::SetLooping(bool Looping)
{
	return false;
}

bool FFFMPEGMediaSession::SetRate(float Rate)
{
	return false;
}
#pragma endregion

FFFMPEGMediaSession::FFFMPEGMediaSession()
	: FormatContext(nullptr)
{
}

void FFFMPEGMediaSession::SetTracks(TSharedPtr<FFFMPEGMediaTracks, ESPMode::ThreadSafe> InTracks)
{
	Tracks = InTracks;
}

bool FFFMPEGMediaSession::Initialize(bool LowLatency)
{
	return false;
}

void FFFMPEGMediaSession::Shutdown()
{
	
}
