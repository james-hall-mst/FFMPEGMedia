#pragma once

#include <libavformat/avformat.h>

#include "IMediaControls.h"

// Forward decs
class FFFMPEGMediaTracks;

class FFFMPEGMediaSession : public IMediaControls
{
	AVFormatContext* FormatContext;

public:
	FFFMPEGMediaSession();

	/**
	 * Set which tracks object is being used by the player.
	 *
	 * @param InTracks Tracks object.
	 */
	void SetTracks(TSharedPtr<FFFMPEGMediaTracks, ESPMode::ThreadSafe> InTracks);

	/**
	 * Initialize the media session.
	 *
	 * @param LowLatency Whether to enable low latency processing.
	 * @see SetTopolgy, Shutdown
	 */
	bool Initialize(bool LowLatency);

	/**
	 * Close the media session.
	 *
	 * @see Initialize
	 */
	void Shutdown();
	
#pragma region IMediaControls
	
	//~ IMediaControls interface

	virtual bool CanControl(EMediaControl Control) const override;
	virtual FTimespan GetDuration() const override;
	virtual float GetRate() const override;
	virtual EMediaState GetState() const override;
	virtual EMediaStatus GetStatus() const override;
	virtual TRangeSet<float> GetSupportedRates(EMediaRateThinning Thinning) const override;
	virtual FTimespan GetTime() const override;
	virtual bool IsLooping() const override;
	virtual bool Seek(const FTimespan& Time) override;
	virtual bool SetLooping(bool Looping) override;
	virtual bool SetRate(float Rate) override;

#pragma endregion
private:
	FCriticalSection Lock;

	TWeakPtr<FFFMPEGMediaTracks, ESPMode::ThreadSafe> Tracks;
};