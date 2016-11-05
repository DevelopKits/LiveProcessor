
// LiveProcessorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LiveProcessor.h"
#include "LiveProcessorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma  comment(lib, "PlaybackCtrlSDId.lib")
#else 
#pragma  comment(lib, "PlaybackCtrlSDI.lib")
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLiveProcessorDlg 对话框



CLiveProcessorDlg::CLiveProcessorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LIVEPROCESSOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLiveProcessorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLiveProcessorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK_SDI_1, &CLiveProcessorDlg::OnBnClickedCheckSdi1)
	ON_BN_CLICKED(IDC_CHECK_SDI_2, &CLiveProcessorDlg::OnBnClickedCheckSdi2)
	ON_BN_CLICKED(IDC_CHECK_SDI_3, &CLiveProcessorDlg::OnBnClickedCheckSdi3)
	ON_BN_CLICKED(IDC_CHECK_SDI_4, &CLiveProcessorDlg::OnBnClickedCheckSdi4)
	ON_BN_CLICKED(IDC_CHECK_SDI_5, &CLiveProcessorDlg::OnBnClickedCheckSdi5)
	ON_BN_CLICKED(IDC_CHECK_SDI_6, &CLiveProcessorDlg::OnBnClickedCheckSdi6)
	ON_BN_CLICKED(IDC_CHECK_SDI_7, &CLiveProcessorDlg::OnBnClickedCheckSdi7)
	ON_BN_CLICKED(IDC_CHECK_SDI_8, &CLiveProcessorDlg::OnBnClickedCheckSdi8)
	ON_BN_CLICKED(IDC_CHECK_SDI_9, &CLiveProcessorDlg::OnBnClickedCheckSdi9)
	ON_BN_CLICKED(IDC_CHECK_SDI_10, &CLiveProcessorDlg::OnBnClickedCheckSdi10)
	ON_BN_CLICKED(IDC_CHECK_SDI_11, &CLiveProcessorDlg::OnBnClickedCheckSdi11)
	ON_BN_CLICKED(IDC_CHECK_SDI_12, &CLiveProcessorDlg::OnBnClickedCheckSdi12)
	ON_BN_CLICKED(IDC_CHECK_SDI_13, &CLiveProcessorDlg::OnBnClickedCheckSdi13)
	ON_BN_CLICKED(IDC_CHECK_SDI_14, &CLiveProcessorDlg::OnBnClickedCheckSdi14)
	ON_BN_CLICKED(IDC_CHECK_SDI_15, &CLiveProcessorDlg::OnBnClickedCheckSdi15)
	ON_BN_CLICKED(IDC_CHECK_SDI_16, &CLiveProcessorDlg::OnBnClickedCheckSdi16)
	ON_BN_CLICKED(IDC_BUTTON_START, &CLiveProcessorDlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CLiveProcessorDlg 消息处理程序

BOOL CLiveProcessorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLiveProcessorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLiveProcessorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLiveProcessorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLiveProcessorDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_d3d_processor.stop();
	CDialogEx::OnClose();
}

void CLiveProcessorDlg::enable_windows(int begin, int end, BOOL enable) {
	for (int i = begin; i <= end; ++i) {
		((CButton*)GetDlgItem(i))->EnableWindow(enable);
	}
}

void CLiveProcessorDlg::OnBnClickedCheckSdi1_8(int id) {
	// TODO: 在此添加控件通知处理程序代码
	int checked = ((CButton*)GetDlgItem(id))->GetCheck();
	if (checked) {
		enable_windows(IDC_CHECK_SDI_1, IDC_CHECK_SDI_8, FALSE);
		enable_windows(id, id, TRUE);

		enable_windows(id+8, id+8, FALSE);
	}
	else {
		enable_windows(IDC_CHECK_SDI_1, IDC_CHECK_SDI_16, TRUE);
	}
}

void CLiveProcessorDlg::OnBnClickedCheckSdi9_16(int id) {
	// TODO: 在此添加控件通知处理程序代码
	int checked = ((CButton*)GetDlgItem(id))->GetCheck();
	if (checked) {
		enable_windows(IDC_CHECK_SDI_9, IDC_CHECK_SDI_16, FALSE);
		enable_windows(id, id, TRUE);

		enable_windows(id - 8, id - 8, FALSE);
	}
	else {
		enable_windows(IDC_CHECK_SDI_1, IDC_CHECK_SDI_16, TRUE);
	}
}


void CLiveProcessorDlg::OnBnClickedCheckSdi1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_1);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_2);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi3()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_3);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi4()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_4);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi5()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_5);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi6()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_6);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi7()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_7);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi8()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_8);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi9()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_9);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi10()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_10);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi11()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_11);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi12()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_12);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi13()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_13);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi14()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_14);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi15()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_15);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi16()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_16);
}

int on_d3d_need_data_cb(unsigned char* buf, int len, void* ctx) {
	CLiveProcessorDlg *p = (CLiveProcessorDlg*)ctx;
	if (p && p->m_ring_buffer)
		return RingBuffer_read(p->m_ring_buffer, (char*)buf, len);

	return -1;
}

static int on_sdi_have_data_cb(unsigned char* buffer, int buffer_len, void* ctx) {

	CLiveProcessorDlg *p = (CLiveProcessorDlg*)ctx;
	if (p && p->m_ring_buffer)
		return RingBuffer_write(p->m_ring_buffer, (char*)buffer, buffer_len);
	else
		return -1;
}
static int on_sdi_format_changed_cb(int w, int h, double f, void* ctx) {//width,height,frame_rate
	CLiveProcessorDlg *p = (CLiveProcessorDlg*)ctx;
	p->m_image_h = h;
	p->m_image_w = w;
	p->m_frame_rate = f;
	if (p->m_ring_buffer) {
		RingBuffer_destroy(p->m_ring_buffer);
	}

	p->m_ring_buffer = RingBuffer_create(p->m_image_h*p->m_image_w * 4, (int)p->m_frame_rate);

	p->m_d3d_processor.set_need_data_cb(on_d3d_need_data_cb, p);
	p->m_d3d_processor.start(p->GetDlgItem(IDC_STATIC_DISPLAY)->GetSafeHwnd(), p->m_image_w, p->m_image_h);

	char log[100];
	sprintf(log, "%s %d %d %.2f", __FUNCTION__, w, h, f);
	AfxMessageBox("NO INPUT SDI WAS SELECTED!\n");

	return 0;
}



void CLiveProcessorDlg::OnBnClickedButtonStart()
{
	// TODO: 在此添加控件通知处理程序代码
	int input_index = -1;
	int output_index = -1;
	int i = 0;
	for (i = IDC_CHECK_SDI_1; i < IDC_CHECK_SDI_9; ++i) {
		++input_index;
		int checked = ((CButton*)GetDlgItem(i))->GetCheck();
		if (checked) {
			break;
		}
	}

	if (i >= IDC_CHECK_SDI_9) {
		char log[100];
		sprintf(log, "NO INPUT ! %s %d", __FUNCTION__, i);
		AfxMessageBox(log);
		return;
	}

	for (i = IDC_CHECK_SDI_9; i <= IDC_CHECK_SDI_16; ++i) {
		++output_index;
		int checked = ((CButton*)GetDlgItem(i))->GetCheck();
		if (checked) {
			break;
		}
	}

	if (i > IDC_CHECK_SDI_16) {
		AfxMessageBox("NO OUTPUT SDI WAS SELECTED!\n");
		return;
	}

	m_ring_buffer = NULL;
	m_image_h = m_image_w = 0;
	m_frame_rate = .0f;

	m_sdi_input.set_format_changed(on_sdi_format_changed_cb, this);
	m_sdi_input.set_cb_have_data(on_sdi_have_data_cb, this);
	m_sdi_input.start(input_index);

}
