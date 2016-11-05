
// LiveProcessorDlg.cpp : ʵ���ļ�
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



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLiveProcessorDlg �Ի���



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


// CLiveProcessorDlg ��Ϣ�������

BOOL CLiveProcessorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLiveProcessorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLiveProcessorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLiveProcessorDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_d3d_processor.stop();
	CDialogEx::OnClose();
}

void CLiveProcessorDlg::enable_windows(int begin, int end, BOOL enable) {
	for (int i = begin; i <= end; ++i) {
		((CButton*)GetDlgItem(i))->EnableWindow(enable);
	}
}

void CLiveProcessorDlg::OnBnClickedCheckSdi1_8(int id) {
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_1);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_2);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_3);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_4);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_5);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_6);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_7);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi1_8(IDC_CHECK_SDI_8);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_9);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_10);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_11);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_12);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_13);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_14);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedCheckSdi9_16(IDC_CHECK_SDI_15);
}


void CLiveProcessorDlg::OnBnClickedCheckSdi16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
