/****************************************************************************
 * Control - A custom control, a mini board to display current position
 *  Author:  Bill Forster
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2010-2014, Bill Forster <billforsternz at gmail dot com>
 ****************************************************************************/
#ifndef __t2__MiniBoard__
#define __t2__MiniBoard__

#include "wx/wx.h"
#include "BoardSetup.h"

class MiniBoard : public wxControl
{
public:
    MiniBoard( wxWindow* parent,
                      wxWindowID id = wxID_ANY,
                      const wxPoint& point = wxDefaultPosition );
    ~MiniBoard();
    void Set( const thc::ChessPosition &cp ) { if(bs) {this->cp=cp; bs->Set(cp); bs->Draw();} }
    thc::ChessPosition cp;
    
private:
    wxBitmap     chess_bmp;
    BoardSetup   *bs;
    void UpdateBoard();
    void OnPaint(wxPaintEvent& WXUNUSED(evt));
    void OnEraseBackground(wxEraseEvent& WXUNUSED(evt));
    void OnSize(wxSizeEvent& WXUNUSED(evt));
private:
    DECLARE_EVENT_TABLE()
};

#endif /* defined(__t2__MiniBoard__) */
