.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

DAYS = 7 ; constant representing the number of days in a week
HOURS = 24 ; constant representing the number of hours in a day
MINUTES = 60 ; constant representing the number of minutes in an hour
SECONDS = 60 ; constant representing the number of seconds in a minute

.data
	date_time DWORD ?			; byte 0000 stores the DAY, byte 0001 stores the HOUR, byte 0002 stores the MINUTE, and byte 0003 stores the SECOND
	num_of_iters DWORD 0		; counts the total number of iterations
	day BYTE DAYS				; used to restore cl to the current day value
	hour BYTE HOURS				; used to restore cl to the current hour value
	minute BYTE MINUTES			; used to restore cl to the current minute value

.code
main proc
    mov eax, 0
    mov esi, OFFSET date_time
    mov ecx, 0
    mov cl, DAYS

    ; comment 1: Initial loop, counting the days from 0-7th day
    L1:
    mov day, cl
    
    ; comment 2: We set the loop for Hours to 24 so it checks all 50400 seconds in a day
    mov cl, HOURS

        ; comment 3: We start the hour per day counter here with cl set to #Hours in a day
        L2:
        mov hour, cl

        ; comment 4: We set the minutes in a day counter here, to count all 3600 seconds per hour
        mov cl, MINUTES
            
            ; comment 5: We loop through every minute here
            L3:
            mov minute, cl

            ; comment 6: We update the counter to count all 60 seconds of a minute
            mov cl, SECONDS
            sub cl, 1

                ; comment 7: We do the loop for seconds in a minute by adding one to the dereferenced pointer
                L4:
                add BYTE PTR [esi+3], 1
                
                ; comment 8: We count the ammount of iterations
                add num_of_iters, 1
                Loop L4

            ; comment 9: We handle the special case when a minute ends, a second goes from 00:59 to 01:00 and we add one to the counter
            add BYTE PTR [esi+2], 1
            mov BYTE PTR [esi+3], 0
            add num_of_iters, 1
            mov cl, minute
            Loop L3

        ; comment 10: We update the array for when it passes from 00:59:59 to 01:00:00 
        add BYTE PTR [esi+1], 1
        mov BYTE PTR [esi+2], 0
        mov BYTE PTR [esi+3], 0
        mov cl, hour
        Loop L2

    ; comment 11: When a day is completed, we update the whole array for it to only store the value of the day passed
    add BYTE PTR [esi], 1
    mov BYTE PTR [esi+1], 0
    mov BYTE PTR [esi+2], 0
    mov BYTE PTR [esi+3], 0

    ; comment 12: We loop until the day counter is exhausted
    mov cl, day
    Loop L1

    invoke ExitProcess,0
main endp
end main