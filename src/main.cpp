/**
 * @file
 * @brief Visual C++ でのweak symbol サンプル
 * 
 * https://devblogs.microsoft.com/oldnewthing/20200731-00/?p=104024
 */
/*
 * C リンケージで宣言
 */
/// 呼び出す関数名
extern "C" int func();
/// デフォルト実装
extern "C" int _default_func();
/*
 * リンカーへの指定
 */
#if defined(_M_IX86)
// x86 は_ が付加される
#pragma comment(linker, "/alternatename:_func=__default_func")
#elif defined(_M_IA64) || defined(_M_AMD64)
// x64 は そのままの名前
#pragma comment(linker, "/alternatename:func=_default_func")
#endif

/*
 * C++ リンケージで宣言
 */
/// 呼び出す関数名
extern int func2();
/// デフォルト実装
extern int _default_func2();

// Visual Studio 2019 では以下の指定でリンクできた
// リンクエラーの時に出力されたエラーメッセージを参考に指定
#if defined(_M_IX86)
#pragma comment(linker, "/alternatename:?func2@@YAHXZ=?_default_func2@@YAHXZ")
#elif defined(_M_IA64) || defined(_M_AMD64)
#pragma comment(linker, "/alternatename:?func2@@YAHXZ=?_default_func2@@YAHXZ")
#endif

// 1:デフォルト実装が呼び出される
// 0:独自実装が呼び出される
#define USE_DEFAULT 1

/// メイン関数
int main()
{
	return func() + func2();
}

#if !USE_DEFAULT
/// C リンケージの独自実装
int func() {
	return 0;
}
/// C++ リンケージの独自実装
int func2() {
	return 0;
}
#endif

/// C リンケージのデフォルト実装
int _default_func() {
	return 1;
}
/// C++ リンケージのデフォルト実装
int _default_func2() {
	return 2;
}

