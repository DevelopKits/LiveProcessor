
// LiveProcessorDlg.h : 头文件
//

#pragma once


#include "D3DProcessor.h"
#include "PlaybackCtrlSdi.h"
#include "NoLockCBuffer.h"

// CLiveProcessorDlg 对话框
class CLiveProcessorDlg : public CDialogEx
{
// 构造
public:
	CLiveProcessorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIVEPROCESSOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
