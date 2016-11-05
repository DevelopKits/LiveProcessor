
// LiveProcessorDlg.h : ͷ�ļ�
//

#pragma once


#include "D3DProcessor.h"
#include "PlaybackCtrlSdi.h"
#include "NoLockCBuffer.h"

// CLiveProcessorDlg �Ի���
class CLiveProcessorDlg : public CDialogEx
{
// ����
public:
	CLiveProcessorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIVEPROCESSOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	CD3DProcessor   m_d3d_processor;
	CSdiInput		m_sdi_input;

public:
	RingBuffer*		m_ring_buffer;
	int				m_image_w;
	int				m_image_h;
	double			m_frame_rate;

private:
	void enable_windows(int begin, int end, BOOL enable);
	void OnBnClickedCheckSdi1_8(int id);
	void OnBnClickedCheckSdi9_16(int id);
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedCheckSdi1();
	afx_msg void OnBnClickedCheckSdi2();
	afx_msg void OnBnClickedCheckSdi3();
	afx_msg void OnBnClickedCheckSdi4();
	afx_msg void OnBnClickedCheckSdi5();
	afx_msg void OnBnClickedCheckSdi6();
	afx_msg void OnBnClickedCheckSdi7();
	afx_msg void OnBnClickedCheckSdi8();
	afx_msg void OnBnClickedCheckSdi9();
	afx_msg void OnBnClickedCheckSdi10();
	afx_msg void OnBnClickedCheckSdi11();
	afx_msg void OnBnClickedCheckSdi12();
	afx_msg void OnBnClickedCheckSdi13();
	afx_msg void OnBnClickedCheckSdi14();
	afx_msg void OnBnClickedCheckSdi15();
	afx_msg void OnBnClickedCheckSdi16();
	afx_msg void OnBnClickedButtonStart();
};
