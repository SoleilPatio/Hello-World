#!/usr/bin/env python
# -*- coding: UTF-8 -*-
#
# generated by wxGlade 0.9.5 on Sat Mar 28 19:49:25 2020
#

import wx

# begin wxGlade: dependencies
# end wxGlade

# begin wxGlade: extracode
# end wxGlade


class MyFrame(wx.Frame):
    def __init__(self, *args, **kwds):
        # begin wxGlade: MyFrame.__init__
        kwds["style"] = kwds.get("style", 0) | wx.DEFAULT_FRAME_STYLE
        wx.Frame.__init__(self, *args, **kwds)
        self.SetSize((1123, 784))
        self.button_Load = wx.Button(self, wx.ID_ANY, u"讀取")
        self.ui_initial_position = wx.SpinCtrl(self, wx.ID_ANY, "0", min=0, max=100)
        self.ui_extra_position = wx.ComboBox(self, wx.ID_ANY, choices=[], style=wx.CB_DROPDOWN)
        self.ui_extra_time = wx.ComboBox(self, wx.ID_ANY, choices=[], style=wx.CB_DROPDOWN)
        self.notebook_1 = wx.Notebook(self, wx.ID_ANY, style=wx.NB_BOTTOM)
        self.ui_message_page = wx.ScrolledWindow(self.notebook_1, wx.ID_ANY, style=wx.TAB_TRAVERSAL)
        self.ui_message = wx.TextCtrl(self.ui_message_page, wx.ID_ANY, u"顯示訊息在這裏", style=wx.TE_MULTILINE | wx.TE_READONLY)
        self.frame_statusbar = self.CreateStatusBar(1)

        self.__set_properties()
        self.__do_layout()

        self.Bind(wx.EVT_BUTTON, self.OnLoad, self.button_Load)
        # end wxGlade

    def __set_properties(self):
        # begin wxGlade: MyFrame.__set_properties
        self.SetTitle("InvestSim")
        self.ui_message_page.SetScrollRate(10, 10)
        self.frame_statusbar.SetStatusWidths([-1])
        
        # statusbar fields
        frame_statusbar_fields = ["frame_statusbar"]
        for i in range(len(frame_statusbar_fields)):
            self.frame_statusbar.SetStatusText(frame_statusbar_fields[i], i)
        # end wxGlade

    def __do_layout(self):
        # begin wxGlade: MyFrame.__do_layout
        sizer_1 = wx.BoxSizer(wx.VERTICAL)
        sizer_3 = wx.BoxSizer(wx.HORIZONTAL)
        sizer_2 = wx.BoxSizer(wx.HORIZONTAL)
        Sizer_Input = wx.StaticBoxSizer(wx.StaticBox(self, wx.ID_ANY, u"輸入"), wx.HORIZONTAL)
        grid_sizer_1 = wx.GridSizer(3, 2, 0, 0)
        Sizer_Chart = wx.StaticBoxSizer(wx.StaticBox(self, wx.ID_ANY, u"線圖"), wx.HORIZONTAL)
        Sizer_Function = wx.StaticBoxSizer(wx.StaticBox(self, wx.ID_ANY, u"功能"), wx.HORIZONTAL)
        Sizer_Function.Add(self.button_Load, 0, wx.ALL, 2)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        Sizer_Function.Add((0, 0), 0, 0, 0)
        sizer_1.Add(Sizer_Function, 0, wx.ALL | wx.EXPAND, 2)
        Sizer_Chart.Add((0, 0), 0, 0, 0)
        sizer_2.Add(Sizer_Chart, 3, wx.ALL | wx.EXPAND, 2)
        label_1 = wx.StaticText(self, wx.ID_ANY, u"初始口數")
        grid_sizer_1.Add(label_1, 0, wx.ALL, 2)
        grid_sizer_1.Add(self.ui_initial_position, 0, wx.ALL, 2)
        label_2 = wx.StaticText(self, wx.ID_ANY, u"加碼口數")
        grid_sizer_1.Add(label_2, 0, wx.ALL, 2)
        grid_sizer_1.Add(self.ui_extra_position, 0, wx.ALL, 2)
        label_3 = wx.StaticText(self, wx.ID_ANY, u"加碼次數")
        grid_sizer_1.Add(label_3, 0, wx.ALL, 2)
        grid_sizer_1.Add(self.ui_extra_time, 0, wx.ALL, 2)
        Sizer_Input.Add(grid_sizer_1, 1, 0, 0)
        sizer_2.Add(Sizer_Input, 1, wx.ALL | wx.EXPAND, 2)
        sizer_1.Add(sizer_2, 2, wx.EXPAND, 0)
        sizer_3.Add(self.ui_message, 1, wx.ALL | wx.EXPAND, 5)
        self.ui_message_page.SetSizer(sizer_3)
        self.notebook_1.AddPage(self.ui_message_page, u"訊息")
        sizer_1.Add(self.notebook_1, 1, wx.EXPAND, 0)
        self.SetSizer(sizer_1)
        self.Layout()
        self.Centre()
        # end wxGlade

    def OnLoad(self, event):  # wxGlade: MyFrame.<event_handler>
        print("Event handler 'OnLoad' not implemented!")
        event.Skip()
# end of class MyFrame

class MyApp(wx.App):
    def OnInit(self):
        self.frame = MyFrame(None, wx.ID_ANY, "")
        self.SetTopWindow(self.frame)
        self.frame.Show()
        return True

# end of class MyApp

if __name__ == "__main__":
    app = MyApp(0)
    app.MainLoop()
