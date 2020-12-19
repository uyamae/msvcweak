# Visual C++ でのweak symbol

weak symbol をVisual C++ で使用する方法のサンプルです。

weak symbol はライブラリでデフォルト実装を用意しておきつつ、アプリケーション側で独自実装を
定義するような場合に使用します。

Visual C++ の場合はリンカの/alternatename オプションを使用して、あるシンボルの定義が見つからない場合に
代わりに参照するシンボルを指定します。

C++ リンケージの場合にはマングリングされたシンボル名を指定する必要があります。
C リンケージの場合にはx86 では名前の前に_ が付加されますがx64 ではそのままの名前になります。

## 参考リンク

* [What does the /ALTERNATENAME linker switch do?](https://devblogs.microsoft.com/oldnewthing/20200731-00/?p=104024)
