#pragma once

#include <xenos/xe.h>
#include <xenos/edram.h>

#define MAKE_COLOR3(r,g,b) (0xff000000 | ((b)<<16) | ((g)<<8) | (r))
#define MAKE_COLOR4(r,g,b,a) ((a)<<24 | ((b)<<16) | ((g)<<8) | (r))
#define MAKE_COLOR1F(c) ((u8)(255.0f*((c)>1.0f?1.0f:(c))))
#define MAKE_COLOR4F(r,g,b,a) (MAKE_COLOR1F(a)<<24 | (MAKE_COLOR1F(b)<<16) | (MAKE_COLOR1F(g)<<8) | MAKE_COLOR1F(r))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

extern struct XenosDevice * xe;

#include "drkPvr.h"
#include "Renderer_if.h"

#if REND_API == REND_D3D

	bool InitRenderer();
	void TermRenderer();
	void ResetRenderer(bool Manual);
	
	void HandleEvent(u32 evid,void* p);
	bool ThreadStart();
	void ThreadEnd();
	void VBlank();
	void StartRender();
	void EndRender();
	void DoRender();
    void HandleCache();

	void ListCont();
	void ListInit();
	void SoftReset();

	void SetRenderRect(float* rect,bool  drc);
	void SetFBScale(float x,float y);
	void ListModes(void(* callback)(u32 w,u32 h,u32 rr));

	void VramLockedWrite(vram_block* bl,u32 addr);
	
	extern volatile bool do_render_pending;
	extern volatile bool rend_end_render_call_pending;


#define rend_init         InitRenderer
#define rend_term         TermRenderer
#define rend_reset        ResetRenderer

#define rend_thread_start ThreadStart
#define rend_thread_end	  ThreadEnd
#define rend_vblank       VBlank
#define rend_start_render StartRender
#define rend_end_render   EndRender
#define rend_handle_event HandleEvent
#define rend_handle_cache HandleCache

#define rend_list_cont ListCont
#define rend_list_init ListInit
#define rend_list_srst SoftReset

#define rend_text_invl VramLockedWrite
#define rend_set_render_rect SetRenderRect
#define rend_set_fb_scale SetFBScale
#define rend_list_modes ListModes
#endif