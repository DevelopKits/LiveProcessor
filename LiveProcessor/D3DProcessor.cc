#include "stdafx.h"
#include "D3DProcessor.h"

#pragma comment(lib, "d3d9.lib")


/*
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
*/

int defSourceDataCallback(unsigned char* buf, int len, void* cxt) {
	return len;
}



CD3DProcessor::CD3DProcessor():m_pDirect3D9(NULL), m_pDirect3DDevice(NULL), m_pDirect3DSurfaceRender(NULL), m_buffer(NULL), m_buffer_len(0)
	, m_pixel_w(0),m_pixel_h(0), m_need_data_cb_ctx(NULL),m_need_data_cb(NULL){

}

CD3DProcessor::~CD3DProcessor() {
	delete m_buffer;
}

int CD3DProcessor::InitD3D(HWND hwnd, unsigned long lWidth, unsigned long lHeight) {
	HRESULT lRet;
	InitializeCriticalSection(&m_critial);
	Cleanup();

	m_pixel_w = lWidth;
	m_pixel_h = lHeight;

	m_pDirect3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pDirect3D9 == NULL)
		return -1;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	GetClientRect(hwnd, &m_rtViewport);

	lRet = m_pDirect3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pDirect3DDevice);
	if (FAILED(lRet))
		return -1;

//#if LOAD_BGRA
	lRet = m_pDirect3DDevice->CreateOffscreenPlainSurface(
		m_pixel_w, m_pixel_h,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&m_pDirect3DSurfaceRender,
		NULL);
//#elif LOAD_YUV420P
//	lRet = m_pDirect3DDevice->CreateOffscreenPlainSurface(
//		lWidth, lHeight,
//		(D3DFORMAT)MAKEFOURCC('Y', 'V', '1', '2'),
//		D3DPOOL_DEFAULT,
//		&m_pDirect3DSurfaceRender,
//		NULL);
//#endif


	if (FAILED(lRet))
		return -1;

	return 0;

}
void CD3DProcessor::Cleanup() {
	EnterCriticalSection(&m_critial);
	if (m_pDirect3DSurfaceRender)
		m_pDirect3DSurfaceRender->Release();
	if (m_pDirect3DDevice)
		m_pDirect3DDevice->Release();
	if (m_pDirect3D9)
		m_pDirect3D9->Release();
	LeaveCriticalSection(&m_critial);
}
BOOL CD3DProcessor::Render() {
	HRESULT lRet;
	//Read Data
	//RGB
	//if (fread(buffer, 1, pixel_w*pixel_h*bpp / 8, fp) != pixel_w*pixel_h*bpp / 8) {
	//	// Loop
	//	fseek(fp, 0, SEEK_SET);
	//	fread(buffer, 1, pixel_w*pixel_h*bpp / 8, fp);
	//}

	if (m_need_data_cb) {
		if (m_need_data_cb(m_buffer, m_buffer_len, m_need_data_cb_ctx) <= 0) {
			return -1;
		}
	}

	if (m_pDirect3DSurfaceRender == NULL)
		return -1;
	D3DLOCKED_RECT d3d_rect;
	lRet = m_pDirect3DSurfaceRender->LockRect(&d3d_rect, NULL, D3DLOCK_DONOTWAIT);
	if (FAILED(lRet))
		return -1;

	byte *pSrc = m_buffer;
	byte * pDest = (BYTE *)d3d_rect.pBits;
	int stride = d3d_rect.Pitch;
	unsigned long i = 0;

	//Copy Data
//#if LOAD_BGRA
	int pixel_w_size = m_pixel_w * 4;
	for (i = 0; i < m_pixel_h; i++) {
		memcpy(pDest, pSrc, pixel_w_size);
		pDest += stride;
		pSrc += pixel_w_size;
	}
//#elif LOAD_YUV420P
//	for (i = 0; i < pixel_h; i++) {
//		memcpy(pDest + i * stride, pSrc + i * pixel_w, pixel_w);
//	}
//	for (i = 0; i < pixel_h / 2; i++) {
//		memcpy(pDest + stride * pixel_h + i * stride / 2, pSrc + pixel_w * pixel_h + pixel_w * pixel_h / 4 + i * pixel_w / 2, pixel_w / 2);
//	}
//	for (i = 0; i < pixel_h / 2; i++) {
//		memcpy(pDest + stride * pixel_h + stride * pixel_h / 4 + i * stride / 2, pSrc + pixel_w * pixel_h + i * pixel_w / 2, pixel_w / 2);
//	}
//#endif

	lRet = m_pDirect3DSurfaceRender->UnlockRect();
	if (FAILED(lRet))
		return -1;

	if (m_pDirect3DDevice == NULL)
		return -1;

	m_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	m_pDirect3DDevice->BeginScene();
	IDirect3DSurface9 * pBackBuffer = NULL;

	m_pDirect3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
	m_pDirect3DDevice->StretchRect(m_pDirect3DSurfaceRender, NULL, pBackBuffer, &m_rtViewport, D3DTEXF_LINEAR);
	m_pDirect3DDevice->EndScene();
	m_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	pBackBuffer->Release();

	return true;
}

void CD3DProcessor::start(HWND hwnd, unsigned long lWidth, unsigned long lHeight) {
	if (FAILED(InitD3D(hwnd, lWidth, lHeight))) {
		fprintf(stdout, "InitD3D FAILED!\n");
		return;
	}

	if (m_need_data_cb == NULL) {
		m_pixel_w = 1280;
		m_pixel_h = 720;

		m_need_data_cb = defSourceDataCallback;
	}

	m_buffer_len = m_pixel_h*m_pixel_w * 4;
	m_buffer = new unsigned char[m_buffer_len];
	memset(m_buffer, 0x32, m_buffer_len);

	return CMyThread::start();
}

void CD3DProcessor::run() {

	while (!m_exited) {
		Render();
		::Sleep(3);
	}

	Cleanup();
}

void CD3DProcessor::set_need_data_cb(SourceDataCallback _cb, void* ctx) {
	m_need_data_cb = _cb;
	m_need_data_cb_ctx = ctx;
}