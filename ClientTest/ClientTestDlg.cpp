
// ClientTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientTest.h"
#include "ClientTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
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
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientTestDlg 对话框

CClientTestDlg::CClientTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientTestDlg::IDD, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CClientTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CClientTestDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CClientTestDlg 消息处理程序


BOOL CClientTestDlg::OnInitDialog()
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
	//--------------------------------------------------------//
	m_tab.InsertItem(0, _T("收货管理"));
	m_tab.InsertItem(1, _T("发货管理"));
	m_tab.InsertItem(2, _T("查询"));
	
	m_sendm.Create(IDD_SEND_PANEL, GetDlgItem(IDC_TAB1));
	m_recvm.Create(IDD_RECV_PANEL , GetDlgItem(IDC_TAB1));
	m_searchm.Create(IDD_SH_PANEL , GetDlgItem(IDC_TAB1));

	CRect rs;
	m_tab.GetClientRect(&rs);

	rs.top += 22;
	//rs.bottom -= 60;
	//rs.left += 1;
	//rs.right -= 2;
	
	m_recvm.MoveWindow(&rs);
	m_sendm.MoveWindow(&rs);
	m_searchm.MoveWindow(&rs);

	m_recvm.ShowWindow(true);
	m_sendm.ShowWindow(false);
	m_searchm.ShowWindow(false);

	m_tab.SetCurSel(0);
	//------------------------------------------//
	//TODO

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



void CClientTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientTestDlg::OnPaint()
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
HCURSOR CClientTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CClientTestDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel = m_tab.GetCurSel();

	switch (CurSel)
	{
		case 0:
			m_recvm.ShowWindow(true);
			m_sendm.ShowWindow(false);
			m_searchm.ShowWindow(false);
			break;
		case 1:
			m_recvm.ShowWindow(false);
			m_sendm.ShowWindow(true);
			m_searchm.ShowWindow(false);
			break;
		case 2:
			m_recvm.ShowWindow(false);
			m_sendm.ShowWindow(false);
			m_searchm.ShowWindow(true);
			break;
		default:
			break;
	}

	*pResult = 0;
}
