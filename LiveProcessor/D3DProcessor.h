#pragma once

#include <d3d9.h>
#include "MyThread.h"

typedef int(*SourceDataCallback)(unsigned char*, int, void*);

class CD3DProcessor :public CMyThread{
public:
	CD3DProcessor();
	~CD3DProcessor();
	void set_need_data_cb(SourceDataCallback _cb, void* ctx);
	void start(HWND hwnd, unsigned long lWidth, unsigned long lHeight);
	//void stop();

protected:
	void run();

private:
	int InitD3D(HWND hwnd, unsigned long lWidth, unsigned long lHeight);
	void Cleanup();
	BOOL Render();

private:
	IDirect3D9			*m_pDirect3D9 = NULL;
	IDirect3DDevice9	*m_pDirect3DDevice = NULL;
	IDirect3DSurface9	*m_pDirect3DSurfaceRender = NULL;
	RECT				m_rtViewport;

	CRITICAL_SECTION	m_critial;

	unsigned char*		m_buffer;
	int					m_buffer_len;

	int					m_pixel_w;
	int					m_pixel_h;

	SourceDataCallback m_need_data_cb;
	void*			   m_need_data_cb_ctx;
};