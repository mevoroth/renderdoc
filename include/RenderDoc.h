#ifndef _RENDER_DOC_HPP_
#define _RENDER_DOC_HPP_

#define RENDERDOC_ENABLE_CAPTURE

namespace RenderDoc
{
	void Initialize();
	void Release();

	void GetAPIVersion(int *major, int *minor, int *patch);

	void SetCaptureOptionU32();
	void SetCaptureOptionF32();

	void GetCaptureOptionU32();
	void GetCaptureOptionF32();

	void SetFocusToggleKeys();
	void SetCaptureKeys();

	void GetOverlayBits();
	void MaskOverlayBits();

	void Shutdown();
	void UnloadCrashHandler();

	void SetCaptureFilePathTemplate();
	void GetCaptureFilePathTemplate();

	void GetNumCaptures();
	void GetCapture();

	void TriggerCapture();

	void IsTargetControlConnected();
	void LaunchReplayUI();

	void SetActiveWindow();

	void StartFrameCapture();
	void IsFrameCapturing();
	void EndFrameCapture();

	void TriggerMultiFrameCapture();
}

#endif
