
// ClientTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClientTest.h"
#include "ClientTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
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
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientTestDlg �Ի���

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


// CClientTestDlg ��Ϣ�������


BOOL CClientTestDlg::OnInitDialog()
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
	//--------------------------------------------------------//
	m_tab.InsertItem(0, _T("�ջ�����"));
	m_tab.InsertItem(1, _T("��������"));
	m_tab.InsertItem(2, _T("��ѯ"));
	
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClientTestDlg::OnPaint()
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
