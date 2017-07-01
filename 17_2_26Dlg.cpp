
// 17_2_26Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "17_2_26.h"
#include "17_2_26Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy17_2_26Dlg 对话框



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


// CMy17_2_26Dlg 消息处理程序

BOOL CMy17_2_26Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Init_One = FALSE;
	GetClientRect(m_rcClent);
	m_sizeClient.cx = m_rcClent.Width();
	m_sizeClient.cy = m_rcClent.Height();
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy17_2_26Dlg::OnPaint()
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
HCURSOR CMy17_2_26Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CMy17_2_26Dlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CPoint pt(point);
	CRect rcClient;
	GetClientRect(rcClient);
	GetWindowRect(m_rcClent);
	::ScreenToClient(this->GetSafeHwnd(),&pt);
	point = pt;

	if (pt.x<rcClient.left+5&&pt.y<rcClient.top+5)//左上角,判断是不是在左上角，就是看当前坐标是不是即在左边拖动的范围内，又在上边拖动的范围内，其它角判断方法类似  
    {  
        return HTTOPLEFT;  
    }else if (pt.x>rcClient.right-5 && pt.y<rcClient.top+5)//右上角  
    {  
        return HTTOPRIGHT;  
    }else if (pt.x<rcClient.left+5 && pt.y>rcClient.bottom-5)//左下角  
    {  
        return HTBOTTOMLEFT;  
    }else if (pt.x>rcClient.right-5 && pt.y>rcClient.bottom-5)//右下角  
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
        return HTBOTTOM;          //以上这四个是上、下、左、右四个边  
	}  
	if( 5 < pt.y && pt.y < 25 )
    {  
        return HTCAPTION;  
    }  
	
	return CDialogEx::OnNcHitTest(point);
}


void CMy17_2_26Dlg::OnSize(UINT nType, int cx, int cy)
{
	
	// TODO: 在此处添加消息处理程序代码
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
	// TODO: 在此处添加消息处理程序代码
	//x tianxiadiyi
}
