
// MFCFomsMVPDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCFomsMVP.h"
#include "MFCFomsMVPDlg.h"
#include "afxdialogex.h"

#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFomsMVPDlg 대화 상자



CMFCFomsMVPDlg::CMFCFomsMVPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCFOMSMVP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFomsMVPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_UserListBox);
	DDX_Control(pDX, IDC_EDIT1, m_NameEditBox);
	DDX_Control(pDX, IDC_EDIT2, m_AgeEditBox);
	DDX_Control(pDX, IDC_EDIT3, m_AddressEditBox);
	DDX_Control(pDX, IDC_BUTTON1, m_SaveButton);
	DDX_Control(pDX, IDC_BUTTON2, m_UpdateBtn);
}

BEGIN_MESSAGE_MAP(CMFCFomsMVPDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCFomsMVPDlg::SaveButton_Click)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCFomsMVPDlg::UpdateBtn_Click)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCFomsMVPDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMFCFomsMVPDlg 메시지 처리기

BOOL CMFCFomsMVPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCFomsMVPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCFomsMVPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCFomsMVPDlg::SetUserListBox(map<long, CUser> data)
{
	m_UserListBox.ResetContent();
	for each (auto i in data)
	{
		m_UserListBox.InsertString(-1, i.second.GetName().c_str());
		cout << "user id : " + i.second.GetID() << endl;
	}
}

void CMFCFomsMVPDlg::SetName(string value)
{
	m_NameEditBox.SetWindowTextA(value.c_str());
}

string CMFCFomsMVPDlg::GetName()
{
	CString cstr = _T("");
	m_NameEditBox.GetWindowTextA(cstr);
	string str = CT2CA(cstr);
	return str;
}

void CMFCFomsMVPDlg::SetAge(int value)
{
	CString str;
	str.Format(_T("%d"), value);
	m_AgeEditBox.SetWindowTextA(str);
}

int CMFCFomsMVPDlg::GetAge()
{
	CString cstr;
	m_AgeEditBox.GetWindowTextA(cstr);
	int value = _ttoi(cstr);
	return value;
}

void CMFCFomsMVPDlg::SetAddress(string value)
{
	m_AddressEditBox.SetWindowTextA(value.c_str());
}

string CMFCFomsMVPDlg::GetAddress()
{
	CString cstr = _T("");
	m_AddressEditBox.GetWindowTextA(cstr);
	string str = CT2CA(cstr);
	return str;
}

void CMFCFomsMVPDlg::SetPresenter(UserFormPresenter* presenter)
{
	m_UserFormPresenter = presenter;
}

void CMFCFomsMVPDlg::SaveButton_Click()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_UserFormPresenter->SaveUser();
}


void CMFCFomsMVPDlg::UpdateBtn_Click()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_UserFormPresenter->UpdateUser();
}


void CMFCFomsMVPDlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	m_UserFormPresenter->SelectItem();
}

long CMFCFomsMVPDlg::getSelectedUserID()
{
	long value = m_UserListBox.GetCurSel();

	return value;
}
