/////////////////////////////////////////////////////////////////////////////
// Name:        wx/wasm/colour.h
// Purpose:
// Author:      Adam Hilss
// Copyright:   (c) 2022 Adam Hilss
// Licence:     LGPL v2
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_WASM_COLOUR_H_
#define _WX_WASM_COLOUR_H_

//-----------------------------------------------------------------------------
// wxColour
//-----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxColour : public wxColourBase
{
public:
    // constructors
    // ------------
    DEFINE_STD_WXCOLOUR_CONSTRUCTORS

    // copy ctors and assignment operators
    wxColour(const wxColour& col)
    {
        Init();
        *this = col;
    }

    virtual ~wxColour();

    wxColour& operator=(const wxColour& col);

    // accessors
    virtual bool IsOk() const { return m_isInit; }

    unsigned char Red() const { return m_red; }
    unsigned char Green() const { return m_green; }
    unsigned char Blue() const { return m_blue; }
    unsigned char Alpha() const { return m_alpha; }

    // comparison
    bool operator==(const wxColour& colour) const
    {
        return (m_red == colour.m_red &&
                m_green == colour.m_green &&
                m_blue == colour.m_blue &&
                m_alpha == colour.m_alpha &&
                m_isInit == colour.m_isInit);
    }

    bool operator!=(const wxColour& colour) const { return !(*this == colour); }

protected:

    // Helper function
    void Init();

    virtual void
    InitRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

private:
    bool m_isInit;
    unsigned char m_red;
    unsigned char m_blue;
    unsigned char m_green;
    unsigned char m_alpha;

private:
    wxDECLARE_DYNAMIC_CLASS(wxColour);
};

#endif // _WX_WASM_COLOUR_H_
