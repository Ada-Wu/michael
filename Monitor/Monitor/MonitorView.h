
// MonitorView.h : CMonitorView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"


class CMonitorView : public CFormView
{
protected: // �������л�����
	CMonitorView();
	DECLARE_DYNCREATE(CMonitorView)

public:
	enum{ IDD = IDD_MONITOR_FORM };

// ����
public:
	CMonitorDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMonitorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg void OnStnClickedStcDatarv2();
	//afx_msg void OnStnClickedStcDatasrvx7();
	//afx_msg void OnStnClickedStcDatasrvx8();
	//afx_msg void OnStnClickedPicMap();
	afx_msg void OnMenuSrvconf();
	afx_msg void OnMenuGwconf();
	afx_msg void OnMenuPrjconf();
	afx_msg void OnMenuTmchk();
	afx_msg void OnMenuSound();
	afx_msg void OnMenuHistory();
};

#ifndef _DEBUG  // MonitorView.cpp �еĵ��԰汾
inline CMonitorDoc* CMonitorView::GetDocument() const
   { return reinterpret_cast<CMonitorDoc*>(m_pDocument); }
#endif

