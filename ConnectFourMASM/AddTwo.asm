TITLE Connect Four Assembler Code

;Program Description: Functions written in assembler that will be linked to our C++ main function
;Author:	Kathleen, Andrew, Ryan, Jusice
;Creation Date:		12/1/2016
;Latest Revision:

; 32-bit assembly language template

INCLUDE Irvine32.inc

.data
blank BYTE " ",0
redBlue BYTE 14h		;red text on blue background
yellowBlue BYTE 30h	;yellow text on blue background
whiteBlue BYTE 31h		;white text on blue background
blueBlue BYTE 17h		;blue text on blue background

.code
main proc
	call displayBoard

	call exitProcess
main endp

;FUNCTION TO DISPLAY BOARD
displayBoard PROC USES EAX ECX
	mov eax, DWORD PTR blueBlue
	call settextcolor
	call Clrscr

	mov ecx, 6
	Loop4:
		call row
	loop Loop4	
	ret
displayBoard endp

;FUNCTION TO CREATE A ROW OF THE BOARD
row PROC USES EAX ECX		;outputs a row of boxes using ascii characters
	mov ecx, 7
	Loop1:				;ouputs first third of a row of 7 boxes
		mov al, 218
		call Writechar
		mov al, 196
		call Writechar
		mov al, 191
		call Writechar
		mov al, blank
		call Writechar
	loop Loop1
	call crlf

	mov ecx, 7
	Loop2:				;ouputs second third of a row of 7 boxes
		mov al, 179
		call Writechar
	;set color for blank space based on player
		mov al, blank
		call Writechar
		mov eax, DWORD PTR blueBlue		;set color back after outputting blank space
		call settextcolor
		mov al, 179
		call Writechar
		mov al, blank
		call Writechar
	loop Loop2
	call crlf

	mov ecx, 7
	Loop3:				;ouputs last third of a row of 7 boxes
		mov al, 192
		call Writechar
		mov al, 196
		call Writechar
		mov al, 217
		call Writechar
		mov al, blank
		call Writechar
	loop Loop3
	call crlf
	ret
row endp

;FUNCTION TO PLACE TILE
placeTile PROC
	
	ret
placeTile endp

;FUNCTION TO EMPTY BOARD
emptyBoard PROC

	ret
emptyBoard endp

;FUNCTION TO CHECK FOR A WINNER
check PROC

	ret
check endp
end main