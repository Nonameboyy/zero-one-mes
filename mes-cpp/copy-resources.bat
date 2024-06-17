@rem Turn off command line output
@echo off
setlocal enabledelayedexpansion

@rem ===================Customized Parameters===================
echo --------------------------------
echo This tool is used to copy the necessary resources in the demo to the new module.
echo You need to enter the name of the new module (ie: the folder path where the new module is located)
set /p "newm=Enter the module name (eg: sample):"
echo --------------------------------
@rem ================================================

@rem Execute replication logic
xcopy arch-demo !newm! /S /Y /EXCLUDE:exclude.txt
@rem Build some empty directories to ensure structural integrity
md !newm!\dao !newm!\service !newm!\domain\vo !newm!\domain\query !newm!\domain\dto
type nul > !newm!\zh-dict.yaml
type nul > !newm!\dao\.keep
type nul > !newm!\service\.keep
type nul > !newm!\domain\vo\.keep
type nul > !newm!\domain\query\.keep
type nul > !newm!\domain\dto\.keep
echo File copy completed
pause