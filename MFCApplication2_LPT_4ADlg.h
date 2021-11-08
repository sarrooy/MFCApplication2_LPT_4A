
// MFCApplication2_LPT_4ADlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApplication2LPT4ADlg
class CMFCApplication2LPT4ADlg : public CDialogEx
{
// Construcción
public:
	CMFCApplication2LPT4ADlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_LPT_4A_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOnButton();
	afx_msg void OnBnClickedOffButton();
	short m_data2Send;
	afx_msg void OnBnClickedSendButton();
	short m_AddressPort;
	short m_read_address;
	afx_msg void OnBnClickedReadButton();
	short m_read_estatico;
	short m_2oREAD_PORT;
	short m_FULL_PORT_READ;
	short m_RCONTROL;
	short m_RDATA;
	CString m_RSTATUS;
	afx_msg void OnBnClickedStatusCheckerButton();
};
