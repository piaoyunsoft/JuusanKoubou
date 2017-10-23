@echo off
cd/d "%~dp0"

rd/s/q "%appdata%\Code\User"
rd/s/q "%userprofile%\.vscode\extensions"

mklink /j "%appdata%\Code\User" .
mklink /j "%userprofile%\.vscode\extensions" .\extensions

rd/s/q "%appdata%\Code - Insiders\User"
rd/s/q "%userprofile%\.vscode-insiders\extensions"

md "%appdata%\Code - Insiders" 2>NUL
md "%userprofile%\.vscode-insiders" 2>NUL

mklink /j "%appdata%\Code - Insiders\User" .
mklink /j "%userprofile%\.vscode-insiders\extensions" .\extensions

pause
