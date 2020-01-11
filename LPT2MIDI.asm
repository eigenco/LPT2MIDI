        org     100h

        mov     ax, 4a15h
        mov     bx, 0
        mov     dx, 330h
        shl     edx, 16
        mov     dx, 330h
        mov     cx, 1
        mov     si, io_dispatch_table
        mov     di, end
        int     2fh

        mov     ax, 0x3100
        mov     dx, 512/16
        int     21h

align 16
handler330:
        mov     ah, al

        mov     al, 255
        mov     dx, 0x37a
        out     dx, al
        times 5 in al, dx

        mov     al, ah
        mov     dx, 0x378
        out     dx, al
        times 5 in al, dx

        xor     al, al
        mov     dx, 0x37a
        out     dx, al
        times 10 in al, dx

        retf

align 16
io_dispatch_table:
        dw      0x0330
        dw      handler330
end:
