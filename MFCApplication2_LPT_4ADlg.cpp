
// MFCApplication2_LPT_4ADlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2_LPT_4A.h"
#include "MFCApplication2_LPT_4ADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMFCApplication2LPT4ADlg



CMFCApplication2LPT4ADlg::CMFCApplication2LPT4ADlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_LPT_4A_DIALOG, pParent)
	, m_data2Send(0)
	, m_AddressPort(0)
	, m_read_address(0)
	, m_read_estatico(0)
	, m_2oREAD_PORT(0)
	, m_FULL_PORT_READ(0)
	, m_RCONTROL(0)
	, m_RDATA(0)
	, m_RSTATUS(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2LPT4ADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DATA_EDIT, m_data2Send);
	DDX_Text(pDX, IDC_ADDRESS__EDIT, m_AddressPort);
	DDX_Text(pDX, IDC_READ_ADDRESS__EDIT, m_read_address);

	DDX_Text(pDX, IDC_READ_STATIC, m_read_estatico);
	DDX_Text(pDX, IDC_READ2o_PUERTO_STATIC, m_2oREAD_PORT);
	
	DDX_Text(pDX, IDC_FULL_PORT_EDIT, m_FULL_PORT_READ);   
	DDX_Text(pDX, IDC_RCONTROL_STATIC, m_RCONTROL);  
	DDX_Text(pDX, IDC_RDATA_STATIC, m_RDATA);
	DDX_Text(pDX, IDC_RSTATUS_STATIC, m_RSTATUS);  

}

BEGIN_MESSAGE_MAP(CMFCApplication2LPT4ADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ON_BUTTON, &CMFCApplication2LPT4ADlg::OnBnClickedOnButton)
	ON_BN_CLICKED(IDC_OFF_BUTTON, &CMFCApplication2LPT4ADlg::OnBnClickedOffButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CMFCApplication2LPT4ADlg::OnBnClickedSendButton)
	ON_BN_CLICKED(IDC_READ_BUTTON, &CMFCApplication2LPT4ADlg::OnBnClickedReadButton)
	//ON_BN_CLICKED(IDC_STATUS_CHECKER_BUTTON, &CMFCApplication2LPT4ADlg::OnBnClickedStatusCheckerButton)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplication2LPT4ADlg

BOOL CMFCApplication2LPT4ADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMFCApplication2LPT4ADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCApplication2LPT4ADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCApplication2LPT4ADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*comentario de funcion
* declarar la estructura de mi funcion para lectura y escritura de datos a los puertos
*/
//					short 0x300 => 0x378 0011 0111 1000
void _stdcall Out32(short direccion_de_puerto, short dato_a_escribir);
short _stdcall Inp32(short direccion_de_puerto_a_leer);
//short _stdcall Inp4_A(short direccion_de_puerto);


void CMFCApplication2LPT4ADlg::OnBnClickedOnButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Out32(0x378, 0xff);
}


void CMFCApplication2LPT4ADlg::OnBnClickedOffButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Out32(0x378, 0x00);
}


void CMFCApplication2LPT4ADlg::OnBnClickedSendButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	Out32(m_AddressPort, m_data2Send);
}


void CMFCApplication2LPT4ADlg::OnBnClickedReadButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	m_read_estatico = Inp32(m_AddressPort);
	m_2oREAD_PORT = Inp32(m_read_estatico);
	UpdateData(FALSE);
}


void CMFCApplication2LPT4ADlg::OnBnClickedStatusCheckerButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	//m_FULL_PORT_READ = 0x378;
	m_RDATA = Inp32(m_FULL_PORT_READ); //0x378
	short tonto_VS = m_FULL_PORT_READ + 1;
	m_RSTATUS = Inp32(tonto_VS); //0x379
	m_RCONTROL = Inp32(m_FULL_PORT_READ+2); //0x37A
	UpdateData(FALSE);
}
