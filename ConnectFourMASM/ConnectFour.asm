TITLE Connect Four Assembler Code
 
;Program Description: Functions written in assembler that will be linked to our C++ main function
;Author:			Kathleen, Andrew, Ryan, Jusice
;Creation Date:               12/01/2016
;Latest Revision:			  12/02/2016
 
; 32-bit assembly language template
 
INCLUDE Irvine32.inc
;----------------------------DATA----------------------------------------
.data
p1Prompt DWORD "Player 1: What would you like to be known as?",0
p2Prompt DWORD "Player 2: What would you like to be known as?",0
buff DWORD 80
p1Name	DWORD buff+1 DUP(?)
p2Name	DWORD buff+1 DUP(?)

again DWORD "y",0

blank BYTE " ",0
redBlue BYTE 14h		;red text on blue background
yellowBlue BYTE 30h		;yellow text on blue background
whiteBlue BYTE 31h		;white text on blue background
blueBlue BYTE 17h		;blue text on blue background


;-------------------------------MAIN FUNCTION------------------------------------- 
.code
main proc
	mov eax, p1Prompt		;asks P1 name
	call WriteString
	mov edx, offset p1Name	;reads P1 name
	mov ecx, buff
	call ReadString

	mov eax, p2Prompt	;asks P2 name
	call Writestring
	mov edx, offset p2Name	;reads P2 name
	mov ecx, buff
	call ReadString

	call Clrscr
	call emptyBoard
	call displayBoard
 
	call exitProcess
main endp

;---------------------------------FUNCTION TO DISPLAY BOARD----------------------------------- 
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

;-------------------------------FUNCTION TO CREATE A ROW OF THE BOARD-------------------------------------
row PROC USES EAX ECX           ;outputs a row of boxes using ascii characters
	mov ecx, 7
	Loop1:                                          ;ouputs first third of a row of 7 boxes
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
	Loop2:                                          ;ouputs second third of a row of 7 boxes
		mov al, 179
		call Writechar
	;set color for blank space based on player
		mov al, blank
		call Writechar
		mov eax, DWORD PTR blueBlue                    ;set color back after outputting blank space
		call settextcolor
		mov al, 179
		call Writechar
		mov al, blank
		call Writechar
	loop Loop2
	call crlf
 
	mov ecx, 7
	Loop3:                                          ;ouputs last third of a row of 7 boxes
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
 
;--------------------------------FUNCTION TO PLACE TILE------------------------------------
placeTile PROC USES ECX                     ;(int col, char player)
	;DOES THIS WORK?? WILL ECX CHANGE WHILE I AM RUNNING THE CMP AND JMP STATEMENTS?
	mov ecx, -1
 
	;if (col <= 0 || col > 7 || board[0][col] != ' ')
	cmp col, 0
		jb isfalse
	cmp col, 7
		ja isfalse
	cmp board[0][col], DWORD PTR blank      
		jne isfalse
	ret -1 ;return -1
          
	isfalse:         ;else  
		;for ( i=0; board[i][col] == ' '; i++)
		inc ecx
		board[ecx][col], DWORD PTR blank
		je isfalse
			;if (i == 5)
			cmp ecx, 5
			je setTile		
		dec ecx						;i--
	setTile:
		mov board[ecx][col], player	;board[i][col] = player
		mov eax, ecx
		ret						;return i	
placeTile endp

;-------------------------------FUNCTION TO EMPTY BOARD-------------------------------------
emptyBoard PROC USES ECX
    mov ecx, 6
    push ecx
    Loop1:
        mov ecx, 7
        Loop 2:        
            mov board[i][j], DWORD PTR blank ;board[i][j] = ' '
        loop Loop2
    pop ecx
    loop Loop1
    ret
emptyBoard endp

;---------------------------------FUNCTION TO CHECK FOR A WINNER-----------------------------------
check PROC
 
    ret
check endp
end main