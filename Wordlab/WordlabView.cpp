
// templateView.cpp : implementation of the CWordlabView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Wordlab.h"
#endif
#include "WordlabDoc.h"
#include "WordlabView.h"
#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <utility>
#include <random>
#include <string>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool groupMode = false;
bool isSpace = false;
CString previousWord;

// CWordlabView

IMPLEMENT_DYNCREATE(CWordlabView, CRichEditView)

BEGIN_MESSAGE_MAP(CWordlabView, CRichEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWordlabView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MUTATE_GROUP, &CWordlabView::OnMutateGroup)
	ON_UPDATE_COMMAND_UI(ID_MUTATE_GROUP, &CWordlabView::OnUpdateMutateGroup)
	ON_COMMAND(ID_MUTATE_RANDOMISE, &CWordlabView::OnMutateRandomise)
	ON_UPDATE_COMMAND_UI(ID_MUTATE_RANDOMISE, &CWordlabView::OnUpdateMutateRandomise)
	ON_COMMAND(ID_MUTATE_STRIP, &CWordlabView::OnMutateStrip)
	ON_UPDATE_COMMAND_UI(ID_MUTATE_STRIP, &CWordlabView::OnUpdateMutateStrip)
	ON_COMMAND(ID_MUTATE_SCATTER, &CWordlabView::OnMutateScatter)
	ON_UPDATE_COMMAND_UI(ID_MUTATE_SCATTER, &CWordlabView::OnUpdateMutateScatter)
END_MESSAGE_MAP()

// CWordlabView construction/destruction

CWordlabView::CWordlabView()
{
	// TODO: add construction code here
	std::srand(static_cast<int>(time(0)));
}

CWordlabView::~CWordlabView()
{
}

BOOL CWordlabView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

// CWordlabView drawing

void CWordlabView::OnDraw(CDC* /*pDC*/)
{
	CWordlabDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CWordlabView printing


void CWordlabView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWordlabView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWordlabView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWordlabView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWordlabView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWordlabView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWordlabView diagnostics

#ifdef _DEBUG
void CWordlabView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CWordlabView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CWordlabDoc* CWordlabView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWordlabDoc)));
	return (CWordlabDoc*)m_pDocument;
}
#endif //_DEBUG


// CWordlabView message handlers


void CWordlabView::OnMutateGroup()
{
	CRichEditView::OnCharUnderline();
}


void CWordlabView::OnUpdateMutateGroup(CCmdUI *pCmdUI)
{
	CRichEditView::OnUpdateCharEffect (pCmdUI, CFM_UNDERLINE, CFE_UNDERLINE);
}

BOOL CWordlabView::AllSpaces(CString str) 
{
	for(int i = 0; i < str.GetLength(); i++) {
	    if(str.GetAt(i) != ' ') {
		    return FALSE;
	    }
	}

	return TRUE;
}

BOOL CWordlabView::EndsInNonSpace(CString str)
{
	if(str.GetAt(str.GetLength() - 1) != ' ') 
	{
		return true;
	}
	else
	{
		return false;
	}
}

BOOL CWordlabView::BeginsWithNonSpace(CString str)
{
    if(str.GetAt(0) != ' ') 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CWordlabView::AppendText( CString msg ) {
 int nBegin;
 CRichEditCtrl &rec = GetRichEditCtrl();
 nBegin = rec.GetTextLength();
 rec.SetSel(nBegin, nBegin);   // Select last character
 rec.ReplaceSel(msg);          // Append, move cursor to end of text
 rec.SetSel(-1,0);             // Remove Black selection bars
 nBegin = rec.GetTextLength(); // Get New Length
 rec.SetSel(nBegin,nBegin);    // Cursor to End of new text
 // Fix annoying "do you want to save your changes?" when program exits
 GetDocument()->SetModifiedFlag(FALSE); // -Optional- (sometimes you want this)
}

void CWordlabView::OnMutateRandomise()
{
	CHARFORMAT cf;
    CString text;
	CString word;
	CString underlined;
	typedef std::pair<CString,bool> group;
    std::vector<group> groups;

	groupMode = false;
	isSpace = false;

	CRichEditCtrl &rEditCtrl = GetRichEditCtrl();

	GetWindowText(text);

	//loop for all text in rich edit control
	for(int i = 0; i < text.GetLength(); i++)
	{
		rEditCtrl.SetSel(i, i + 1); //from start to end character
        rEditCtrl.GetSelectionCharFormat(cf);

        if(cf.dwEffects & CFE_UNDERLINE) //check whether underline character
        {
			if(!groupMode) {
                groupMode = true;
			}

			isSpace = false;
           
            if(!word.IsEmpty()) {
                std::pair <CString,bool> group;
				group = std::make_pair(word,false);
				groups.push_back(group);
				word = "";
			}

			underlined = underlined + rEditCtrl.GetSelText();
			
        }
		else {
			if(groupMode) {

				rEditCtrl.SetSel(i, i + 1); //from start to end character
				if(rEditCtrl.GetSelText() == " ") {
			        underlined = underlined + rEditCtrl.GetSelText();        			        
				}
				else {
					groupMode = false;

					word = word + rEditCtrl.GetSelText();

					if(!underlined.IsEmpty()) {
						std::pair <CString,bool> group;
				        group = std::make_pair(underlined,true);
                        groups.push_back(group);
				        underlined = "";
			        }
				}
			    
			}
			else {
                if(!isSpace) {
                    rEditCtrl.SetSel(i, i + 1); //from start to end character

 					if(rEditCtrl.GetSelText() == " ") {
                        isSpace = true;                  
					}
					else if(rEditCtrl.GetSelText() == "\r") {
						if(!word.IsEmpty()) {
                            std::pair <CString,bool> group;
				            group = std::make_pair(word,false);
                            groups.push_back(group);
				            word = "";
			            }
					}
					else {
					    if(word == "\r") {
							std::pair <CString,bool> group;
				            group = std::make_pair(word,false);
                            groups.push_back(group);
				            word = "";
					    }
					}
					word = word + rEditCtrl.GetSelText();
                    

				}
				else if(isSpace) {
                    rEditCtrl.SetSel(i, i + 1); //from start to end character

                    if(rEditCtrl.GetSelText() != " ") {
                        isSpace = false;

						if(!word.IsEmpty() && !AllSpaces(word)) {
							std::pair <CString,bool> group;
				            group = std::make_pair(word,false);
                            groups.push_back(group);
				            word = "";
			            }
                        
					}

					word = word + rEditCtrl.GetSelText();
				}
			}
		}
	}

	if(!underlined.IsEmpty()) {
		std::pair <CString,bool> group;
		group = std::make_pair(underlined,true);
        groups.push_back(group);
	}
	if(!word.IsEmpty()) {
		std::pair <CString,bool> group;
	    group = std::make_pair(word,false);
        groups.push_back(group);
	}	

	// using built-in random generator:
	//std::random_device rd;
    //std::mt19937 g(rd());
    
    std::random_shuffle(groups.begin(), groups.end());

	// Delete all of the text.
    rEditCtrl.SetSel(0, -1);
    rEditCtrl.Clear();

	int nEnd = 0;

	// loop through start of text to end of text
	for(int k = 0; k < groups.size(); k++) {
		rEditCtrl.SetSel(nEnd, nEnd);
		rEditCtrl.GetSelectionCharFormat(cf);

		if(k != 0 && EndsInNonSpace(previousWord) && BeginsWithNonSpace(groups.at(k).first)) {
			(groups.at(k).first).Insert(0,(CString)" ");
	    }

		if(groups.at(k).second) {
			if(!(cf.dwEffects & CFE_UNDERLINE)) {
				
				CRichEditView::OnCharUnderline();

                AppendText(groups.at(k).first);
				nEnd = nEnd + (groups.at(k).first.GetLength());
			}
			else {

				AppendText(groups.at(k).first);
				nEnd = nEnd + (groups.at(k).first.GetLength());
			}
		}
		else {
            if(cf.dwEffects & CFE_UNDERLINE) {
                CRichEditView::OnCharUnderline();

                AppendText(groups.at(k).first);
                nEnd = nEnd + (groups.at(k).first.GetLength());
			}
			else {
                AppendText(groups.at(k).first);
                nEnd = nEnd + (groups.at(k).first.GetLength());
			}
		}

		previousWord = groups.at(k).first;
	}
}

void CWordlabView::OnUpdateMutateRandomise(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CRichEditView::OnUpdateCharEffect (pCmdUI, CFM_UNDERLINE, CFE_UNDERLINE);
}

void CWordlabView::OnMutateStrip()
{
	CHARFORMAT cf;
    CString text;

	CRichEditCtrl &rEditCtrl = GetRichEditCtrl();
	std::string mod_text("");
	GetWindowText(text);

	//loop for all text in rich edit control
	for(int i = 0; i < text.GetLength(); i++)
	{
		rEditCtrl.SetSel(i, i + 1); //from start to end character
        rEditCtrl.GetSelectionCharFormat(cf);
		
        if(cf.dwEffects & CFE_UNDERLINE) //check whether underline character
        {
	        CRichEditView::OnCharUnderline();
			//std::string s("");
			//s.insert(0, 1, rEditCtrl.GetSelText()[0]);
			//mod_text.append(s);
			//rEditCtrl.ReplaceSel(rEditCtrl.GetSelText());
		   
	//		OutputDebugStringA("modA");
	//		std::string s("");
	//		s.insert(0, 1, '\r');
	//		mod_text.append(s);
	//	}
	//	else if(rEditCtrl.GetSelText() == "\0") {
	//		std::string s("");
	//		s.insert(0, 1, '\0');
	//		mod_text.append(s);
		}
		else if(rEditCtrl.GetSelText()[0] == '\r') {
			  
		}
		else {
			//std::string s("");
			//s.insert(0, 1, 'A');
			//mod_text.append(s);
			rEditCtrl.ReplaceSel((CString)" ");
		}
		//break;
	}

	//rEditCtrl.SetSel(0, text.GetLength());
	//rEditCtrl.ReplaceSel((CString)mod_text.c_str());
}

void CWordlabView::OnUpdateMutateStrip(CCmdUI *pCmdUI)
{
	CRichEditView::OnUpdateCharEffect (pCmdUI, CFM_UNDERLINE, CFE_UNDERLINE);
}

void CWordlabView::OnMutateScatter()
{
	CRichEditCtrl &rEditCtrl = GetRichEditCtrl();
	std::string spaces;

	CString sel_text = rEditCtrl.GetSelText();
	std::string mod_text("");
	for(int i = 0; i < sel_text.GetLength(); i++)
	{
		if(sel_text[i] == ' ') {
			
	        int rnd = std::rand() % 10;
	
	        if(rnd == 0) {
                spaces = " ";
	        }
			else if(rnd == 1) {
				spaces = " ";
			}
			else if(rnd == 2) {
				spaces = "   ";
			}
			else if(rnd == 3) {
				spaces = "    ";
			}
			else if(rnd == 4) {
				spaces = "     ";
			}
			else if(rnd == 5) {
				spaces = "      ";
			}
			else if(rnd == 6) {
				spaces = "       ";
			}
			else if(rnd == 7) {
				spaces = "        ";
			}
			else if(rnd == 8) {
				spaces = "         ";
			}
			else if (rnd == 9) {
				spaces = "          ";
			}
			
			mod_text.append(spaces);
		}
		else {
			std::string carray("");
			carray.insert(0, 1, sel_text[i]);
			mod_text.append(carray);
		}
	}
	rEditCtrl.ReplaceSel(CString(mod_text.c_str()));
}


void CWordlabView::OnUpdateMutateScatter(CCmdUI *pCmdUI)
{
	CRichEditView::OnUpdateCharEffect (pCmdUI, CFM_UNDERLINE, CFE_UNDERLINE);
}

