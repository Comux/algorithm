@echo off
rm aa.exe
g++ -o aa.exe a.cpp

for  %%I in (1 2 3 4 5) do (
echo Problem Test
echo Data %%I
time < enter
aa.exe < %%I.in > tmp.txt
time < enter
fc tmp.txt %%I.out
del tmp.txt
pause
)
