# mhook
A Windows API hooking library. Originally developed by Marton Anka.

# Acknowledgements
Mhook contains a disassembler that is a stripped-down version of the excellent tDisasm package by Matt Conover. Thank you Matt! tDisasm comes with a BSD-style license and re-releasig a derivative of it under the MIT license has been confirmed to be OK by its author. 

Alexandr Filenkov submitted bugfixes in Sept-2007. Michael Syrovatsky submitted fixes for IP-relative addressing in Jun-2008. Andrey Kubyshev submitted a bugfix in Jul-2011 and Jan-2013. John McDonald enabled unlimited hooks. Kasper Brandt provided a fix for hot patch function prologues. 

# Version history

## Version 2.5 (20 Oct 2017)
- 10x performance boost
- CMake build system
- Change tabs to spaces
- Ability to hook functions with `je`/`jne` in the first 5 bytes
- Fix hook recursion
- Other fixes

## Version 2.4 (05 Mar 2014)
- A number of improvements: hot patch location (mov edi, edi) handling, support for REX-prefixed EIP-relative jumps on x64, removal of compile-time limit on the number of hooks

## Version 2.3 (15 Jan 2012)
- A bugfix that allows hooking more API functions

## Version 2.2 (27 Jun 2008)
- Support for instructions using IP-relative addressing

## Version 2.1 (15 Oct 2007)
- Fixes

## Version 2.0 (08 Jul 2007)
- Built-in disassembler

## Version 1.0 (24 Jun 2007)
- Original release
