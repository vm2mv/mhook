call mvn -f ./pom/x86-windows-static-mt-msvc10-release/pom.xml deploy || goto :EOF
call mvn -f ./pom/x86-windows-static-mt-msvc10-debug/pom.xml deploy || goto :EOF
call mvn -f ./pom/x64-windows-static-mt-msvc10-release/pom.xml deploy || goto :EOF
call mvn -f ./pom/x64-windows-static-mt-msvc10-debug/pom.xml deploy || goto :EOF