
// LineChartDlg.h : 头文件
//

#pragma once
#include "tchart1.h"
#include <math.h>

// CLineChartDlg 对话框
class CLineChartDlg : public CDialogEx
{
// 构造
public:
	CLineChartDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LineChart_DIALOG };

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
	//CTChart m_chart;
	DECLARE_MESSAGE_MAP()
public:
	CTchart1 m_Chart;
};
