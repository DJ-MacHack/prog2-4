set "MyPathA=C:\Qt\5.9\mingw53_32\bin"
set "MyPathB="C:\Users\DJ MacHack\Dropbox\htw\ss17\Prog 2\Aufgaben\4\build-Test-Desktop_Qt_5_9_0_MinGW_32bit-Debug\debug"
%MyPathA%\windeployqt.exe --verbose=3 --dir out --release %MyPathB%\Test.exe

pause