
// LineChartDlg.h : ͷ�ļ�
//

#pragma once
#include "tchart1.h"
#include <math.h>

// CLineChartDlg �Ի���
class CLineChartDlg : public CDialogEx
{
// ����
public:
	CLineChartDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LineChart_DIALOG };

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
	//CTChart m_chart;
	DECLARE_MESSAGE_MAP()
public:
	CTchart1 m_Chart;
};
