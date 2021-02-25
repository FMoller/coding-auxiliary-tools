;Array reverser
;Author: Frederico Moeller
;Created: 25.02.2021 (in x86 Assembly Programming Language From Ground Up course, Udemy)


.386
.model flat,c
.code

Reverser	PROC
			push ebp
			mov ebp,esp
			push esi
			push edi


			xor eax,eax
			mov edi,[ebp+8]
			mov esi,[ebp+12]
			mov ecx,[ebp+16]
			test ecx,ecx

			lea esi,[esi+ecx*4-4]
			pushfd
			std

@@:			lodsd
			mov [edi],eax
			add edi,4
			dec ecx
			jnz @B

			popfd
			mov eax,1

			pop edi
			pop eax
			pop ebp

			ret

Reverser	endp
			end			
