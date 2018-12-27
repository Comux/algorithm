@echo off
rm a.exe
gcc -o a.exe a.c

for  %%I in (1) do (
echo Problem Test
echo Data %%I
time<enter
a.exe < %%I.in > tmp.txt
time<enter
fc tmp.txt %%I.out
del tmp.txt
pause
)
pause