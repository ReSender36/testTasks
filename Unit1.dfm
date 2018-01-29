object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1058#1077#1089#1090#1086#1074#1099#1077' '#1079#1072#1076#1072#1085#1080#1103' 1 - 5'
  ClientHeight = 441
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 161
    Height = 130
    Caption = #1047#1072#1076#1072#1085#1080#1077' 1'
    TabOrder = 0
    object Label2: TLabel
      Left = 9
      Top = 52
      Width = 73
      Height = 13
      Caption = #1087#1077#1088#1077#1084#1077#1085#1085#1072#1103' B:'
    end
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 74
      Height = 13
      Caption = #1087#1077#1088#1077#1084#1077#1085#1085#1072#1103' A:'
    end
    object Edit2: TEdit
      Left = 88
      Top = 44
      Width = 69
      Height = 21
      TabOrder = 0
    end
    object Button1: TButton
      Left = 43
      Top = 95
      Width = 115
      Height = 25
      Caption = #1054#1073#1084#1077#1085#1103#1090#1100' '#1084#1077#1089#1090#1072#1084#1080
      TabOrder = 1
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 88
      Top = 21
      Width = 69
      Height = 21
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 175
    Top = 8
    Width = 185
    Height = 130
    Caption = #1047#1072#1076#1072#1085#1080#1077' 2'
    TabOrder = 1
    object Label3: TLabel
      Left = 8
      Top = 16
      Width = 73
      Height = 13
      Caption = #1053#1077#1082#1072#1103' '#1089#1090#1088#1086#1082#1072':'
    end
    object Edit3: TEdit
      Left = 3
      Top = 35
      Width = 179
      Height = 21
      TabOrder = 0
    end
    object Button2: TButton
      Left = 69
      Top = 95
      Width = 113
      Height = 25
      Caption = #1055#1077#1088#1077#1074#1077#1088#1085#1091#1090#1100' '#1089#1090#1088#1086#1082#1091
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 144
    Width = 617
    Height = 113
    Caption = #1047#1072#1076#1072#1085#1080#1077' 4'
    TabOrder = 2
    object Memo1: TMemo
      Left = 3
      Top = 32
      Width = 611
      Height = 97
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
    end
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 263
    Width = 617
    Height = 162
    Caption = #1047#1072#1076#1072#1085#1080#1077' 5'
    TabOrder = 3
    object Memo2: TMemo
      Left = 3
      Top = 16
      Width = 611
      Height = 143
      Lines.Strings = (
        'Memo1')
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object GroupBox5: TGroupBox
    Left = 363
    Top = 8
    Width = 262
    Height = 130
    Caption = #1047#1072#1076#1072#1085#1080#1077' 3'
    TabOrder = 4
    object Memo3: TMemo
      Left = 3
      Top = 13
      Width = 256
      Height = 114
      Lines.Strings = (
        'Memo3')
      TabOrder = 0
    end
  end
end
