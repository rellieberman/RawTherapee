/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2004-2010 Gabor Horvath <hgabor@rawtherapee.com>
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _CLARITY_H_
#define _CLARITY_H_

#include <gtkmm.h>
#include <adjuster.h>
#include <toolpanel.h>

class Clarity : public Gtk::VBox, public AdjusterListener, public FoldableToolPanel {

  protected:
    Adjuster* Claritypasses;
    Adjuster* Claritystrength;
    
    Adjuster* MLmicrostrength;
    Adjuster* uniformity;
    Gtk::CheckButton* enabled;  
    Gtk::CheckButton* Claritythreechannels;  
    Gtk::CheckButton* enabledtwo;  
    Gtk::CheckButton* MLmicromatrix;  
	
    bool lastEnabled;
	bool lastEnabledtwo;
    sigc::connection enaconn;
    sigc::connection enatwoconn;
    sigc::connection matrixconn;
	
    sigc::connection chanthreeconn;
	bool lastchanthree;
	bool lastmatrix;
	
  public:

    Clarity ();
    virtual ~Clarity ();

    void read           (const rtengine::procparams::ProcParams* pp, const ParamsEdited* pedited=NULL); 
    void write          (rtengine::procparams::ProcParams* pp, ParamsEdited* pedited=NULL);
    void setDefaults    (const rtengine::procparams::ProcParams* defParams, const ParamsEdited* pedited=NULL);
    void setBatchMode   (bool batchMode);

    void adjusterChanged (Adjuster* a, double newval);
	void setAdjusterBehavior (bool strengthadd, bool mlstrentghadd, bool passadd, bool uniformityadd );
	void enabled_toggled();
	void enabledtwo_toggled();
	void MLmicromatrix_toggled();
	
	void chanthree_toggled();
    void trimValues          (rtengine::procparams::ProcParams* pp);
	
};

#endif