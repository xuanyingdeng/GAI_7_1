
// 17_2_26Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "17_2_26.h"
#include "17_2_26Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy17_2_26Dlg �Ի���



CMy17_2_26Dlg::CMy17_2_26Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy17_2_26Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Init_One = TRUE;
}

void CMy17_2_26Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy17_2_26Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	ON_WM_SIZE()
	ON_WM_SIZING()
END_MESSAGE_MAP()


// CMy17_2_26Dlg ��Ϣ�������

BOOL CMy17_2_26Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_Init_One = FALSE;
	GetClientRect(m_rcClent);
	m_sizeClient.cx = m_rcClent.Width();
	m_sizeClient.cy = m_rcClent.Height();
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy17_2_26Dlg::OnPaint()
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
HCURSOR CMy17_2_26Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CMy17_2_26Dlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CPoint pt(point);
	CRect rcClient;
	GetClientRect(rcClient);
	GetWindowRect(m_rcClent);
	::ScreenToClient(this->GetSafeHwnd(),&pt);
	point = pt;

	if (pt.x<rcClient.left+5&&pt.y<rcClient.top+5)//���Ͻ�,�ж��ǲ��������Ͻǣ����ǿ���ǰ�����ǲ��Ǽ�������϶��ķ�Χ�ڣ������ϱ��϶��ķ�Χ�ڣ��������жϷ�������  
    {  
        return HTTOPLEFT;  
    }else if (pt.x>rcClient.right-5 && pt.y<rcClient.top+5)//���Ͻ�  
    {  
        return HTTOPRIGHT;  
    }else if (pt.x<rcClient.left+5 && pt.y>rcClient.bottom-5)//���½�  
    {  
        return HTBOTTOMLEFT;  
    }else if (pt.x>rcClient.right-5 && pt.y>rcClient.bottom-5)//���½�  
    {  
        return HTBOTTOMRIGHT;  
    }else if (pt.x<rcClient.left+5)  
    {  
	
        return HTLEFT;  
    }else if (pt.x>rcClient.right-5)  
    {  

        return HTRIGHT;  
    }else if (pt.y<rcClient.top+5)  
    {  
        return HTTOP;  
    }if (pt.y>rcClient.bottom-5)  
    {  
        return HTBOTTOM;          //�������ĸ����ϡ��¡������ĸ���  
	}  
	if( 5 < pt.y && pt.y < 25 )
    {  
        return HTCAPTION;  
    }  
	
	return CDialogEx::OnNcHitTest(point);
}


void CMy17_2_26Dlg::OnSize(UINT nType, int cx, int cy)
{
	
	// TODO: �ڴ˴������Ϣ����������
/*	CRect rcWind;
	GetWindowRect(rcWind);
	bool bt = FALSE;
	if(!m_Init_One)
	{
		if(cx < m_sizeClient.cx)
		{
			cx = m_sizeClient.cx;
			bt = TRUE;
		}
		if(cy < m_sizeClient.cy)
		{
			cy = m_sizeClient.cy;
			bt = TRUE;
		}
	}
	*/
	CDialogEx::OnSize(nType, cx, cy);
	
}


void CMy17_2_26Dlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	if(pRect->right-pRect->left<= m_sizeClient.cx)
	{
		pRect->left = m_rcClent.left;
		pRect->right = pRect->left+m_sizeClient.cx;
	}
 
	if(pRect->bottom-pRect->top<= m_sizeClient.cy)
	{ 
		pRect->top = m_rcClent.top;
		pRect->bottom = pRect->top+m_sizeClient.cy;
	}
	CDialogEx::OnSizing(fwSide, pRect);
	// TODO: �ڴ˴������Ϣ����������
	//x tianxiadiyi
}
