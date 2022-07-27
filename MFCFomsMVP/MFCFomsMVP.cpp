﻿
// MFCFomsMVP.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "MFCFomsMVP.h"
#include "MFCFomsMVPDlg.h"

#include "IUserFormView.h"
#include "CMemoryRepository.h"
#include "UserFormPresenter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCFomsMVPApp

BEGIN_MESSAGE_MAP(CMFCFomsMVPApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCFomsMVPApp 생성

CMFCFomsMVPApp::CMFCFomsMVPApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CMFCFomsMVPApp 개체입니다.

CMFCFomsMVPApp theApp;


// CMFCFomsMVPApp 초기화

BOOL CMFCFomsMVPApp::InitInstance()
{
	CWinApp::InitInstance();


	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// MFC 컨트롤의 테마를 사용하기 위해 "Windows 원형" 비주얼 관리자 활성화
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	//SetRegistryKey(_T("로컬 애플리케이션 마법사에서 생성된 애플리케이션"));

	//Dependency Injection
	//repository
	CMemoryRepository m_UserFormRepository;

	CMFCFomsMVPDlg dlg;
	m_pMainWnd = &dlg;

	UserFormPresenter m_UserFormPresenter;
	m_UserFormPresenter.SetIUserForm(&dlg);
	m_UserFormPresenter.SetIUserFormRepository(&m_UserFormRepository);


	INT_PTR nResponse = dlg.DoModal();
	
	/*else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "경고: 대화 상자를 만들지 못했으므로 애플리케이션이 예기치 않게 종료됩니다.\n");
		TRACE(traceAppMsg, 0, "경고: 대화 상자에서 MFC 컨트롤을 사용하는 경우 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS를 수행할 수 없습니다.\n");
	}*/

	// 위에서 만든 셸 관리자를 삭제합니다.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고 응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
	return FALSE;
}

