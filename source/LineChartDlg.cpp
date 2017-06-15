
// LineChartDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLineChartDlg �Ի���




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


// CLineChartDlg ��Ϣ�������

BOOL CLineChartDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	Store store;    //����
	Customer customer;  //�˿�
	const UINT nDATALENGTH = 7; //��ʼ�����ݶ�ά����
	const UINT nNUM = 4;
	double dData[nNUM][nDATALENGTH];
	double totalMoney[7]={0};    //����480�����ڵ�Ӫҵ����
	double Money[7][3]={0};    //ÿ�����ҵ�����;
	bool business=true;    //������������Ӫҵ 
	
	CString str;
	InitStore(store);
	srand((unsigned)time(NULL));
	for(int i=0;i!=nDATALENGTH;i++){
		business = true;
		
		//srand((int)getpid());
		while(business){           //����˿͵ĵ�
			InitCustomer(customer);
			goToStore(store,customer);   //�˿ͽ������� 
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
	lineSeries[0].Clear();//����ǰ�����ClearAllSeries(ClearAllSeries���Լ�д�ĺ���)�Ͳ�����
	for(int j=0;j!=nNUM;j++){
		for(int i=0;i<nDATALENGTH;i++)  
		{	 
			str.Format(_T("%d"),i+1);
			lineSeries[j].AddXY(i,dData[j][i],str,0);  
		}
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


/*const UINT nDATALENGTH= 100; 
    double dData[nDATALENGTH];
    for (int i=0;i<nDATALENGTH;i++)
    {
        dData[i] = 100 * sin((float)i)*cos((float)4*i);
    }
    //ClearAllSeries();
    CSeries lineSeries = (CSeries)m_Chart.Series(0);
    lineSeries.Clear();//����ǰ�����ClearAllSeries(ClearAllSeries���Լ�д�ĺ���)�Ͳ�����
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLineChartDlg::OnPaint()
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
HCURSOR CLineChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

