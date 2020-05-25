#include "RenderDoc.h"

#include <cassert>

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#include <Windows.h>
#include "renderdoc_app.h"

namespace RenderDoc
{
	static constexpr char* RENDERDOC_DLL = "renderdoc.dll";
	static RENDERDOC_API_1_1_2* s_RenderDocAPI = nullptr;

	void Initialize()
	{
#ifdef RENDERDOC_ENABLE_CAPTURE
		HMODULE Module = GetModuleHandleA(RENDERDOC_DLL);
		if (Module)
		{
			pRENDERDOC_GetAPI RENDERDOC_GetAPI = (pRENDERDOC_GetAPI)GetProcAddress(Module, "RENDERDOC_GetAPI");
			int Result = RENDERDOC_GetAPI(eRENDERDOC_API_Version_1_1_2, (void **)&s_RenderDocAPI);
			assert(Result == RENDERDOC_GetAPIResult::SUCCESS);
		}
#endif
	}

	void Release()
	{
#ifdef RENDERDOC_ENABLE_CAPTURE
		s_RenderDocAPI = nullptr;
#endif
	}

	void GetAPIVersion(int *major, int *minor, int *patch)
	{
#ifdef RENDERDOC_ENABLE_CAPTURE
		if (s_RenderDocAPI)
		{
			s_RenderDocAPI->GetAPIVersion(major, minor, patch);
		}
#endif
	}

	void SetCaptureOptionU32() { assert(false); } // Not implemented
	void SetCaptureOptionF32() { assert(false); } // Not implemented
	void GetCaptureOptionU32() { assert(false); } // Not implemented
	void GetCaptureOptionF32() { assert(false); } // Not implemented

	void SetFocusToggleKeys() { assert(false); } // Not implemented
	void SetCaptureKeys() { assert(false); } // Not implemented

	void GetOverlayBits() { assert(false); } // Not implemented
	void MaskOverlayBits() { assert(false); } // Not implemented

	void Shutdown() { assert(false); } // Not implemented
	void UnloadCrashHandler() { assert(false); } // Not implemented

	void SetCaptureFilePathTemplate() { assert(false); } // Not implemented
	void GetCaptureFilePathTemplate() { assert(false); } // Not implemented

	void GetNumCaptures() { assert(false); } // Not implemented
	void GetCapture() { assert(false); } // Not implemented

	void TriggerCapture()
	{
#ifdef RENDERDOC_ENABLE_CAPTURE
		if (s_RenderDocAPI)
		{
			s_RenderDocAPI->TriggerCapture();
		}
#endif
	}

	void IsTargetControlConnected() { assert(false); } // Not implemented
	void LaunchReplayUI() { assert(false); } // Not implemented

	void SetActiveWindow() { assert(false); } // Not implemented

	void StartFrameCapture() { assert(false); } // Not implemented
	void IsFrameCapturing() { assert(false); } // Not implemented
	void EndFrameCapture() { assert(false); } // Not implemented

	void TriggerMultiFrameCapture() { assert(false); } // Not implemented
}
