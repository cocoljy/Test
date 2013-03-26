// RecvM.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientTest.h"
#include "RecvM.h"
#include "afxdialogex.h"
#include "ClientTestDlg.h"

// CRecvM 对话框

IMPLEMENT_DYNAMIC(CRecvM, CDialogEx)

CRecvM::CRecvM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRecvM::IDD, pParent)
	, count(0)
{
	HRESULT hr;
	try {
		CoInitialize(NULL);
		hr = m_pConnection.CreateInstance(__uuidof(Connection));
		if (SUCCEEDED(hr))
		{
			hr = m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:/Database1.mdb", "", "", adModeUnknown);
		}
	} catch (_com_error e) {
		CString errormessage;
		errormessage.Format(_T("连接数据库失败！\r\n错误信息：%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);
	}
}

CRecvM::~CRecvM()
{
	m_pConnection->Close();
}

void CRecvM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, contain_box);
	DDX_Control(pDX, IDC_LIST2, showBox);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dateBox);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, rulDateBox);
	DDX_Control(pDX, IDC_EDIT5, remarkBox);
	DDX_Control(pDX, IDC_EDIT1, CourierNumBox);
	DDX_Control(pDX, IDC_EDIT2, CmpyNameBox);
	DDX_Control(pDX, IDC_EDIT3, CsgBox);
	DDX_Control(pDX, IDC_EDIT4, RecverBox);
	DDX_Control(pDX, IDC_COMBO1, ProductNumBox);
	DDX_Text(pDX, IDC_EDIT7, count);
	DDX_Control(pDX, IDC_LIST3, m_listCtr);
	DDX_Control(pDX, IDC_EDIT8, m_edit);
	DDX_Control(pDX, IDC_STATIC1, m_groupBox);
}


BEGIN_MESSAGE_MAP(CRecvM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRecvM::OnBnClickedButton1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CRecvM::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &CRecvM::OnDtnDatetimechangeDatetimepicker2)
	ON_BN_CLICKED(IDC_BUTTON2, &CRecvM::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRecvM::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CRecvM::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON4, &CRecvM::OnBnClickedButton4)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CRecvM::OnNMDblclkList1)
	ON_EN_KILLFOCUS(IDC_EDIT8, &CRecvM::OnEnKillfocusEdit8)
END_MESSAGE_MAP()

void RefreshListViewHeader(CListCtrl *pListCtrl, CStringArray &m_arrHeaderLabel, long *col_wide_arr)
{
	if (pListCtrl == NULL)
		return;
	
	int i, NUM_COLUMNS, nColumnCount;
	CHeaderCtrl *pHeader = pListCtrl->GetHeaderCtrl();
	nColumnCount = pHeader->GetItemCount();

	for (i = 0; i < nColumnCount; i++)
		pListCtrl->DeleteColumn(0);

	if ((NUM_COLUMNS = m_arrHeaderLabel.GetSize()) < 0)
		NUM_COLUMNS = 0;

	LV_COLUMN lvc;
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	for (i = 0; i < NUM_COLUMNS; i++) {
		lvc.iSubItem = i;
		lvc.pszText = m_arrHeaderLabel[i].GetBuffer(1);
		if (col_wide_arr != NULL)
			lvc.cx = col_wide_arr[i];
		else
			lvc.cx = 80;
		lvc.fmt = LVCFMT_CENTER;
		pListCtrl->InsertColumn(i, &lvc);
	}
}

BOOL CRecvM::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE;

	contain_box.SetExtendedStyle(dwExStyle);
	contain_box.SetTextColor(RGB(255, 0, 0));
	contain_box.SetBkColor(RGB(200, 200, 250));
	contain_box.ModifyStyle(0, LVS_REPORT);
	contain_box.SetWindowPos(NULL, 0, 0, 510, 200, SWP_NOMOVE);

	CStringArray m_arrHeaderLable1;
	m_arrHeaderLable1.Add(_T("品名"));
	m_arrHeaderLable1.Add(_T("编号"));
	m_arrHeaderLable1.Add(_T("备注"));

	long col_wide_arr1[8] = {200, 200, 110};
	RefreshListViewHeader(&contain_box, m_arrHeaderLable1, col_wide_arr1);
	//--------------------------------------------------------------------//
	showBox.SetExtendedStyle(dwExStyle);
	showBox.SetTextColor(RGB(255, 0, 0));
	showBox.SetBkColor(RGB(200, 200, 250));
	showBox.ModifyStyle(0, LVS_REPORT);
	showBox.SetWindowPos(NULL, 0, 0, 580, 250, SWP_NOMOVE);

	CStringArray m_arrHeaderLable;
	m_arrHeaderLable.Add(_T("ID"));
	m_arrHeaderLable.Add(_T("公司名称"));
	m_arrHeaderLable.Add(_T("收货日期"));
	m_arrHeaderLable.Add(_T("运单号"));
	m_arrHeaderLable.Add(_T("收件人"));
	m_arrHeaderLable.Add(_T("签收人"));
	m_arrHeaderLable.Add(_T("备注"));

	long col_wide_arr[8] = {30, 110, 80, 110, 70, 70, 110, 80};
	RefreshListViewHeader(&showBox, m_arrHeaderLable, col_wide_arr);
	//--------------------------------------------------------------------//
	m_listCtr.SetExtendedStyle(dwExStyle);
	m_listCtr.SetTextColor(RGB(255, 0, 0));
	m_listCtr.SetBkColor(RGB(200, 200, 250));
	m_listCtr.ModifyStyle(0, LVS_REPORT);
	m_listCtr.SetWindowPos(NULL, 0, 0, 340, 250, SWP_NOMOVE);

	CStringArray m_arrHeaderLable2;
	m_arrHeaderLable2.Add(_T("品名"));
	m_arrHeaderLable2.Add(_T("编号"));
	m_arrHeaderLable2.Add(_T("备注"));

	long col_wide_arr2[8] = {120, 120, 100, 110, 70, 70, 110, 80};
	RefreshListViewHeader(&m_listCtr, m_arrHeaderLable2, col_wide_arr2);
	//--------------------------------------------------------------------//
	updateListBox(showBox, GetWndTextByCString(rulDateBox));
	//-----------------------------------------------------------//
	CFileOperation cfo;

	cfo.open(CString("ProductList.txt"));
	CString ProductName;
	while((ProductName = cfo.readProductName()).GetLength())
		ProductNumBox.AddString(ProductName);
	//---------------------------------------------------------------//
	m_edit.ShowWindow(FALSE);
	//--------------------------------------------------------------//
	//		p.Format(_T("%d"), var1.intVal);

	//		time_t q=(time_t)(((double)var3.date -70.0*365.0-19.0-8.0/24.0)*86400.0);//70年中假定有18年闰年，假定时区东八区需要加或减8小时，不对的话请楼主自行微调。

	return TRUE;
}

// CRecvM 消息处理程序
void CRecvM::InsertDetail(int ID, int i)
{
	_RecordsetPtr m_pRecordset;
	m_pRecordset.CreateInstance(__uuidof(Recordset));

	CString id;
	id.Format(_T("%d"), ID);

	CStringArray ss;
	try {
		USES_CONVERSION;

		ss.RemoveAll();
		ss.Add(contain_box.GetItemText(i, 0));
		ss.Add(contain_box.GetItemText(i, 1));
		ss.Add(contain_box.GetItemText(i, 2));
		memset(sql, 0, sizeof(sql));
		strcat_s(sql, "insert into Detailed (ID, ProductName, ProductNum, Remark) values (");//, ProductName, ProductNum, Remark  , 'a', 'b', 'c'
		strcat_s(sql, T2A(id.GetBuffer()));  strcat_s(sql, ",'");
		strcat_s(sql, T2A(ss[0].GetBuffer()));  strcat_s(sql, "','");
		strcat_s(sql, T2A(ss[1].GetBuffer()));  strcat_s(sql, "','");
		strcat_s(sql, T2A(ss[2].GetBuffer()));  strcat_s(sql, "')");
		m_pRecordset->Open(sql, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);

	} catch(_com_error *e) {
		CString errormessage;
		errormessage.Format(_T("操作数据库失败！\r\n错误信息：%s"), e->ErrorMessage());
		AfxMessageBox(errormessage);
		return;
	}
}

void CRecvM::OnBnClickedButton1()
{
	UpdateData(TRUE);

	CStringArray ss;
	ss.Add(GetWndTextByCString(CmpyNameBox));
	ss.Add(GetWndTextByCString(dateBox));
	ss.Add(GetWndTextByCString(CourierNumBox));
	ss.Add(GetWndTextByCString(CsgBox));
	ss.Add(GetWndTextByCString(RecverBox));
	ss.Add(GetWndTextByCString(remarkBox));

	if (!(ss[0].GetLength() && ss[2].GetLength() && ss[3].GetLength() && ss[4].GetLength() && contain_box.GetItemCount())) 
	{
		AfxMessageBox(_T("请填写完整信息！"));
		return;
	}

	_RecordsetPtr m_pRecordset;
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try {
		USES_CONVERSION;
		memset(sql, 0, sizeof(sql));
		strcat_s(sql, "insert into RecvInfo (CorpName, RecvDate, WaybillNum, Consignee, Receiver, Remark) values ('");
		for (int i = 0; i < 5; i++)
		{
			strcat_s(sql, T2A(ss[i].GetBuffer())); strcat_s(sql, "','");
		}
		strcat_s(sql, T2A(ss[5].GetBuffer())); strcat_s(sql, "')");
		AfxMessageBox(CString(sql));
		m_pRecordset->Open(sql, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	} catch(_com_error *e) {
		CString errormessage;
		errormessage.Format(_T("操作数据库失败！\r\n错误信息：%s"), e->ErrorMessage());
		AfxMessageBox(errormessage);
		return;
	}
	updateListBox(showBox, ss[1]);
	UpdateData(FALSE);

	USES_CONVERSION;
	for (int i = 0; i < contain_box.GetItemCount(); i++)
	{
		InsertDetail(atoi(T2A(showBox.GetItemText(showBox.GetItemCount() - 1, 0).GetBuffer())), i);
	}

	contain_box.DeleteAllItems();
}


void CRecvM::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	//TODO
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CRecvM::updateListBox(CListCtrl &m_listCtrl, CString time)
{
	_RecordsetPtr m_pRecordset;
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try {

		memset(sql, 0, sizeof(sql));
		strcat_s(sql, "select * from RecvInfo where RecvDate=#");
		USES_CONVERSION;
		strcat_s(sql, T2A(time.GetBuffer()));
		strcat_s(sql, "#");
		m_pRecordset->Open(sql, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	} catch(_com_error *e) {
		CString errormessage;
		errormessage.Format(_T("操作数据库失败！\r\n错误信息：%s"), e->ErrorMessage());
		AfxMessageBox(errormessage);
		return;
	}

	showBox.DeleteAllItems();
	  
	try {
		if (!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else {
			return;
		}

		int i = 0;
		while (!m_pRecordset->adoEOF) {
			_variant_t var1, var2, var3, var4, var5, var6, var7;
			var1 = m_pRecordset->GetCollect("ID");
			var2 = m_pRecordset->GetCollect("CorpName");
			var3 = m_pRecordset->GetCollect("RecvDate");
			var4 = m_pRecordset->GetCollect("WaybillNum");
			var5 = m_pRecordset->GetCollect("Consignee");
			var6 = m_pRecordset->GetCollect("Receiver");
			var7 = m_pRecordset->GetCollect("Remark");

			CString p;

			p.Format(_T("%d"), var1.intVal);
			
			showBox.InsertItem(i, p);
			showBox.SetItemText(i, 1, var2.bstrVal);
			showBox.SetItemText(i, 2, CString(var3));
			showBox.SetItemText(i, 3, var4.bstrVal);
			showBox.SetItemText(i, 4, var5.bstrVal);
			showBox.SetItemText(i, 5, var6.bstrVal);
			showBox.SetItemText(i, 6, var7.bstrVal);
			i++;
			m_pRecordset->MoveNext();
		}
		m_pRecordset->Close();
	} catch(_com_error *e) {
		CString errormessage;
		errormessage.Format(_T("数据库操作错误！\r\n错误信息：%s"), e->ErrorMessage());
		AfxMessageBox(errormessage);
	}
}

void CRecvM::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	
	UpdateData(TRUE);

	updateListBox(showBox, GetWndTextByCString(rulDateBox));

	UpdateData(FALSE);
	
	*pResult = 0;
}


void CRecvM::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CRecvM::OnBnClickedButton3()
{
	UpdateData(TRUE);
	CString productName;
	productName = GetWndTextByCString(ProductNumBox);

	int n = contain_box.GetItemCount();
	for (int i = n; i < count + n; i++)
		contain_box.InsertItem(i, productName);
}

int CRecvM::GetCurrentSelectedItemPosition(CListCtrl &clc)
{
	POSITION pos;
	int nItem;
	pos = clc.GetFirstSelectedItemPosition();
	if (pos == NULL)
		return -1;
	else
		nItem = clc.GetNextSelectedItem(pos);
	return nItem;
}

void CRecvM::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	_RecordsetPtr m_pRecordset;
	m_listCtr.DeleteAllItems();
	m_pRecordset.CreateInstance(__uuidof(Recordset));

	USES_CONVERSION;
	int index = atoi(T2A(showBox.GetItemText(GetCurrentSelectedItemPosition(showBox), 0).GetBuffer()));
	CString a;
	a.Format(_T("%d"), index);
	remarkBox.SetWindowTextW(a);

	try {
		memset(sql, 0, sizeof(sql));
		strcat_s(sql, "select * from Detailed where ID=");
		USES_CONVERSION;
		strcat_s(sql, T2A(a.GetBuffer()));
		m_pRecordset->Open(sql, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	} catch(_com_error *e) {
		CString errormessage;
		errormessage.Format(_T("操作数据库失败！\r\n错误信息：%s"), e->ErrorMessage());
		AfxMessageBox(errormessage);
		return;
	}

	int i = 0;
	while (!m_pRecordset->adoEOF) {
		_variant_t var1, var2, var3;
		var1 = m_pRecordset->GetCollect("ProductName");
		var2 = m_pRecordset->GetCollect("ProductNum");
		var3 = m_pRecordset->GetCollect("Remark");
	
		m_listCtr.InsertItem(i, var1.bstrVal);
		m_listCtr.SetItemText(i, 1, var2.bstrVal);
		m_listCtr.SetItemText(i, 2, var2.bstrVal);

		i++;
		m_pRecordset->MoveNext();
	}

	*pResult = 0;
}

void CRecvM::OnBnClickedButton4()
{
	int i;
	if ((i = GetCurrentSelectedItemPosition(contain_box)) >= 0)
		contain_box.DeleteItem(GetCurrentSelectedItemPosition(contain_box));
}


void CRecvM::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	NM_LISTVIEW *pNMListView = (NM_LISTVIEW*)pNMHDR;
	CRect rc;
	CRect rtWindow;
	
	if(pNMListView->iItem != -1)
	{
		m_row = pNMListView->iItem;
		m_column = pNMListView->iSubItem;
		contain_box.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem, LVIR_LABEL, rc);

		contain_box.GetWindowRect(rtWindow);
		ScreenToClient(rtWindow);

		rc.left = rc.left + 3 + rtWindow.left;//442
		rc.top = rc.top + 2 + rtWindow.top;
		rc.right = rc.right + 3 + rtWindow.left;
		rc.bottom = rc.bottom + 2 + rtWindow.top;

		m_edit.SetWindowTextW(contain_box.GetItemText(pNMListView->iItem, pNMListView->iSubItem));
		m_edit.ShowWindow(SW_SHOW);
		m_edit.MoveWindow(&rc);
		m_edit.SetFocus();
		m_edit.CreateSolidCaret(1, rc.Height() - 5);
		m_edit.ShowCaret();
		m_edit.SetSel(-1);
	}
	
	*pResult = 0;
}


void CRecvM::OnEnKillfocusEdit8()
{
	CString str;
	m_edit.GetWindowTextW(str);
	contain_box.SetItemText(m_row, m_column, str);
	m_edit.ShowWindow(SW_HIDE);
}

void CRecvM::OnOK()
{
	return;
}