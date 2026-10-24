@echo off
chcp 65001 >nul
cd /d "%~dp0"

echo =======================================
echo       正在检查并上传代码到 GitHub
echo =======================================
echo.

git add .

git diff --cached --quiet
if %errorlevel%==0 (
    echo [提示] 没有发现任何新的修改，不需要上传。
    goto end
)

echo [1/2] 正在提交更改...
git commit -m "Auto Update: %date% %time%"

echo.
echo [2/2] 正在推送到 GitHub...
git push

if %errorlevel%==0 (
    echo.
    echo =======================================
    echo 🎉 上传成功！代码已安全保存到 GitHub。
    echo =======================================
) else (
    echo.
    echo ❌ 推送失败，请检查网络（确保 Watt Toolkit 已开启）。
)

:end
echo.
pause