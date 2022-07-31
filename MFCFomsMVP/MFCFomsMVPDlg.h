
// MFCFomsMVPDlg.h: 헤더 파일
//

#pragma once
#include "IUserFormView.h"
#include "UserFormPresenter.h"

#include <string>
#include <list>

using namespace std;

// CMFCFomsMVPDlg 대화 상자
class CMFCFomsMVPDlg : public CDialogEx, public IUserFormView
{
// 생성입니다.
public:
	CMFCFomsMVPDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCFOMSMVP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_UserListBox;
	CEdit m_NameEditBox;
	CEdit m_AgeEditBox;
	CEdit m_AddressEditBox;
	CButton m_SaveButton;

	UserFormPresenter* m_UserFormPresenter;

	// IUserFormView을(를) 통해 상속됨
	virtual void SetUserListBox(map<long, CUser> data) override;

	virtual void SetName(string value) override;

	virtual string GetName() override;

	virtual void SetAge(int value) override;

	virtual int GetAge() override;

	virtual void SetAddress(string value) override;

	virtual string GetAddress() override;

	virtual void SetPresenter(UserFormPresenter* presenter) override;

	afx_msg void SaveButton_Click();
	CButton m_UpdateBtn;
	afx_msg void UpdateBtn_Click();
	afx_msg void OnLbnSelchangeList1();

	// IUserFormView을(를) 통해 상속됨
	virtual long getSelectedUserID() override;
};
