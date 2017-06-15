
// LineChartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LineChart.h"
#include "LineChartDlg.h"
#include "afxdialogex.h"
#include "CSeries.h" 
#include "CAxis.h"
#include "CAxes.h"
#include "CLegend.h"


#include "common.h"
#include "customer.h"
#include "queue.h"
#include "store.h"
#include "result.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define R rand()
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLineChartDlg 对话框




CLineChartDlg::CLineChartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLineChartDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLineChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_Chart);
}

BEGIN_MESSAGE_MAP(CLineChartDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CLineChartDlg 消息处理程序

BOOL CLineChartDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	Store store;    //理发店
	Customer customer;  //顾客
	const UINT nDATALENGTH = 7; //初始化数据二维数组
	const UINT nNUM = 4;
	double dData[nNUM][nDATALENGTH];
	double totalMoney[7]={0};    //理发店480分钟内的营业收入
	double Money[7][3]={0};    //每级理发室的收入;
	bool business=true;    //代表理发店正在营业 
	
	CString str;
	InitStore(store);
	srand((unsigned)time(NULL));
	for(int i=0;i!=nDATALENGTH;i++){
		business = true;
		
		//srand((int)getpid());
		while(business){           //处理顾客的到
			InitCustomer(customer);
			goToStore(store,customer);   //顾客进入理发店 
			business = beforeNextOne(store,customer);
		}
		getResult(store,totalMoney[i],Money[i]);
		ClearStore(store);
		//InitStore(store);
		//printResult(totalMoney[i],Money[i]);
	}
	//printChart(totalMoney,Money);
	DestroyStore(store);
	for(int i=0;i!=nDATALENGTH;i++)
		dData[0][i] = totalMoney[i];
	for(int j=1;j!=nNUM;j++){
		for (int i=0;i<nDATALENGTH;i++)  
		{  
			dData[j][i] = Money[i][j-1]; 
		}
	}

	CSeries lineSeries[4];
	
	for(int i=0;i!=4;i++){
		
		lineSeries[i] = (CSeries)m_Chart.Series(i);
	} 
	lineSeries[0].Clear();//在最前面加上ClearAllSeries(ClearAllSeries是自己写的函数)就不用了
	for(int j=0;j!=nNUM;j++){
		for(int i=0;i<nDATALENGTH;i++)  
		{	 
			str.Format(_T("%d"),i+1);
			lineSeries[j].AddXY(i,dData[j][i],str,0);  
		}
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


/*const UINT nDATALENGTH= 100; 
    double dData[nDATALENGTH];
    for (int i=0;i<nDATALENGTH;i++)
    {
        dData[i] = 100 * sin((float)i)*cos((float)4*i);
    }
    //ClearAllSeries();
    CSeries lineSeries = (CSeries)m_Chart.Series(0);
    lineSeries.Clear();//在最前面加上ClearAllSeries(ClearAllSeries是自己写的函数)就不用了
    for(int i=0;i<nDATALENGTH;i++)
    {
        lineSeries.AddXY((double)i,dData[i],NULL,0);
    }
	return 1;
*/

void CLineChartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLineChartDlg::OnPaint()
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
HCURSOR CLineChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

